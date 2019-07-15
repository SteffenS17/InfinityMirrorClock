'''
Created on 21.05.2018

@author: steff
'''
from tkinter import *
import math
import serial
##User INPUTS!
#Default Number of LEDS
NUM_LEDS = 136
nCom = 'com7'
baud_rate = 115200
## Init
ser = serial.Serial(nCom,baud_rate)
## Create Window
root = Tk() #Main Window
root.configure(background='black')
root.pack_propagate(0) #Don't allow the widgets inside to determine the frame's width / height
root.state('zoomed')

rWidth = root.winfo_screenwidth()
rHeight = root.winfo_screenheight()

canvas = Canvas(root, width = rWidth, height = rHeight)
canvas.config(background='black')
canvas.pack(side = BOTTOM)

num = int(0)
r = int(rHeight / 3)
a = int(rWidth / 2)
b = int(rHeight / 2)
#draw initial circle
def drawInitialCircle():
    for angle in range(0, 360, int(360/NUM_LEDS)):
        x = r * math.sin(math.radians(angle)) + a
        y = r * math.cos(math.radians(angle)) + b
        canvas.create_rectangle(x,y,x+10,y+10,fill="gray")
        
drawInitialCircle()
#pos = int(360/NUM_LEDS*20)
#x = r * math.sin(math.radians(pos)) + a
#y = r * math.cos(math.radians(pos)) + b
#canvas.create_rectangle(x,y,x+10,y+10,fill="red")
#Read Serial
def readSerial():
    global num
    while True:
        try:
            c = ser.readline().decode("ascii")   #<entry>:pos;r;g;b
            if "<entry>:" in c:
                meas = c.split(":")
                n=meas[1].split(";")
                pos=-int(n[0])
                c=[int(n[1]),int(n[2]),int(n[3])]              
                colorval = "#%02x%02x%02x" % (5*c[0],5*c[1],5*c[2]) #depends on brightness!!
                pos = int(360/NUM_LEDS*pos)
                x = r * (math.sin(math.radians(pos))) + a
                y = r * (math.cos(math.radians(pos))) + b
                canvas.create_rectangle(x,y,x+10,y+10,fill=colorval)
            if "<clear>:" in c:
                num += 1
                if num == 10:
                    canvas.delete(ALL)
                    num = 0
                    drawInitialCircle()
        except:
            c = "" 
        break
    root.after(1, readSerial) # check serial again soon
# after initializing serial, an arduino may need a bit of time to reset
root.after(1, readSerial)
root.mainloop()
