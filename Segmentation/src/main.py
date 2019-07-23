#! /usr/bin/python3

noOfSegment = int(input('Enter the total no of segment: '))
print("")
sizeOfSegments = []

for i in range(noOfSegment):
    print("Enter the size of segment", i, "(Bytes):", end=" ")
    sizeOfSeg = int(input())
    sizeOfSegments.append(sizeOfSeg)

print("")
maximum = max(sizeOfSegments)

while True:
    physicalMemorySize = int(input("Enter Physical Memory Size (Bytes): "))
    if physicalMemorySize >= maximum:
        break
    else:
        print("Physical Memory Size must be greater than", maximum, ". Try again..\n")

print("")
segmentTable = []
for i in range(noOfSegment):
    row = []
    print("Enter Base Address (Bytes) for Segment", i, ": ")
    base = int(input())
    row.append(base)
    row.append(sizeOfSegments[i])
    segmentTable.append(row)
print("")

while True:
    print("Enter Logical Memory Address (segment and offset separated by single comma(,)): ")
    logicalMemoryAddress = input().split(",")
    s = int(logicalMemoryAddress[0])
    d = int(logicalMemoryAddress[1])

    if s >= noOfSegment:
        print("Trap Addressing Error! Because there is no such type segment. Try Again..")

    elif d >= segmentTable[s][1]:
        print("Trap Addressing Error! Because there is no such type segment", s, "Try Again..")
    else:
        break

physicalAddress = segmentTable[s][0] + d
print("\nPhysical Address is", physicalAddress)

print("\n\tLogical Address Space")
print("\t--------------------------")
print("-"*33)
print("|Segment   \t|\t Segment Size\t|")
print("-"*33)

for i in range(noOfSegment):
    print("|Segment", i, "\t|", end="")
    print(sizeOfSegments[i], "\t\t\t|")
    print("-" * 33)

print("")


lSize = 8
baseSize = 14
sSize = 12

print("\n\n\t Segmentation Table")
print("\t-----------------------\n")
print("-"*41)
print("| Segment No   | Base Address  | Limit  |")
print("-"*41)

for i in range(noOfSegment):
    nSpace = sSize - len(str(i)) - 2
    bSpace = baseSize - len(str(segmentTable[i][0])) - 2
    lSpace = lSize - len(str(segmentTable[i][1])) - 2

    print("| ", i, " "*nSpace, "|", end="")
    print(segmentTable[i][0], " "*bSpace, "|", end="")
    print(segmentTable[i][1], " "*lSpace, "|")
    print("-" * 41)

print("")


print("\n\n\t Primary address Space")
print("\t-----------------------\n")

listS = []
for i in range(noOfSegment):
        listS.append(segmentTable[i][0])
        number = int(segmentTable[i][0]+segmentTable[i][1])
        listS.append(number)

listSorted = sorted(listS)

for i in range(0, noOfSegment*2, 2):
    print("-"*10, listSorted[i])
    print("|", " "*6, "|")
    print("-" * 10, listSorted[i+1])
    i = i + 1





