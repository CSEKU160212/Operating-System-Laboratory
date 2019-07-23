#! /usr/bin/python3
from tkinter import *

KB = 1024

while 1:
    LMSize = int(input("Enter Logical Memory Size(K): "))
    PMSize = int(input("Enter Physical Memory Size(K): "))
    if PMSize < LMSize:
        break
    print("Physical Memory Size must be smaller than Logical Memory Size, Try again..\n")

PUSize = int(input("Enter Paging Unit Size(K): "))
LMBlock = int(LMSize / PUSize)
PMBlock = int(PMSize / PUSize)

pageTable = []

for i in range(0, PMBlock):
    print("Enter Frame No for Page", i, ":", end=" ")
    pageTable.append(int(input()))

LMAddress = int(input("Enter Logical Memory Address: "))

p = int(LMAddress / (PUSize*KB))
d = int(LMAddress % (PUSize*KB))

frameNo = pageTable[p]

frameAddress = int(frameNo * PUSize * KB + d)


print("Page:", p)
print("Offset:", d)
print("Frame No:", frameNo)
print("Physical Memory address:", frameAddress)

root = Tk()
root.title("Paging Graphical View")

leftFrame = Frame(root)
logicalLabel = Label(leftFrame, text="Logical Memory")
logicalLabel.pack(side=TOP)
leftBottomFrame = Frame(leftFrame)

for i in range(0, LMBlock):
    pageNo = LMBlock-i-1
    name = "Page", pageNo
    lb = ((LMBlock-i)*PUSize)-PUSize, "-", (LMBlock-i)*PUSize, "K"
    theLabel = Label(leftBottomFrame, text=lb)

    if p == pageNo:
        button1 = Button(leftBottomFrame, text=name, bg='blue')
    else:
        button1 = Button(leftBottomFrame, text=name)
    theLabel.grid(row=i, column=0)
    button1.grid(row=i, column=1)

leftBottomFrame.pack(side=LEFT)
leftFrame.pack(side=LEFT, padx=100)


rightFrame = Frame(root)
middleFrame = Frame(rightFrame)
pageTableLabel = Label(middleFrame, text="Page Table")
pageTableLabel.pack(side=TOP)
rightBottomFrame = Frame(middleFrame)
for i in range(0, PMBlock):
    frameNo = pageTable[PMBlock - i - 1]
    name = frameNo
    lb1 = PMBlock - i - 1
    theLabel = Label(rightBottomFrame, text=lb1)
    if p == (PMBlock - i - 1):
        button1 = Button(rightBottomFrame, text=name, bg='blue')
    else:
        button1 = Button(rightBottomFrame, text=name)

    theLabel.grid(row=i, column=0)
    button1.grid(row=i, column=1)
rightBottomFrame.pack(side=LEFT)
middleFrame.pack(side=LEFT, padx=150)


leftLeftFrame = Frame(rightFrame)
phySicalMLabel = Label(leftLeftFrame, text="Physical Memory")
phySicalMLabel.pack(side=TOP)
lLLFrame = Frame(leftLeftFrame)
for i in range(0, PMBlock):

    frameNo = PMBlock-i-1
    name = "Frame", frameNo
    lb2 = ((PMBlock-i)*PUSize) - PUSize, "-", (PMBlock-i)*PUSize, "K"
    theLabel = Label(lLLFrame, text=lb2)

    if pageTable[p] == frameNo:
        button1 = Button(lLLFrame, text=name, bg='blue')
    else:
        button1 = Button(lLLFrame, text=name)
    theLabel.grid(row=i, column=0)
    button1.grid(row=i, column=1)

lLLFrame.pack(side=RIGHT)
leftLeftFrame.pack(side=LEFT)

rightFrame.pack(side=RIGHT, padx=200)

root.mainloop()
