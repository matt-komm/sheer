#!/usr/bin/python

#avail = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_"
avail = "abcdefghijklmnopqrstuvwxyz0123456789_-(). "

print len(avail)
'''
reverseMap = [' ']

index = 1
for i in range(128):
    if chr(i) in avail:
        print str(index)+",","//"+str(i)+" = "+chr(i)
        reverseMap.append(chr(i))
        index+=1
    else:
        print str(0)+",","//"+str(i)
        
print
print "----------------"
print

for i,c in enumerate(reverseMap):
    print str(ord(c))+",","//"+str(i)+" = "+str(c) 
'''
