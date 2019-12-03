from socket import *
import os
import sys
import struct
import time
import select
import binascii
import socket

#########################################################
#
#   Nathan Redmond, Lucas Martin, Antwan Pearson
#
#########################################################

# resources
# Textbook website
# textbook pages 161 to 180
# https://docs.python.org to  learn about functions such as select.select, htons, struct.pack, etc.

# Meeting times
# 03/5/19 10 to 2
# 03/6/19 4:15 to 5:30

ICMP_ECHO_REQUEST = 8
timeRTT = []
packageSent = 0;
packageRev = 0;
packageLose = 0;


#the checksum function calculates and returns checksum for errors.
def checksum(str):
    csum = 0
    countTo = (len(str) / 2) * 2
    count = 0
    while count < countTo:
        thisVal = ord(str[count+1]) * 256 + ord(str[count])
        csum = csum + thisVal
        csum = csum & 0xffffffffL
        count = count + 2
    if countTo < len(str):
        csum = csum + ord(str[len(str) - 1])
        csum = csum & 0xffffffffL
    #Adds floating point if there is one.
    csum = (csum >> 16) + (csum & 0xffff)
    csum = csum + (csum >> 16)
    #if not checksum, means if 0 -> 1, if 1 -> 0
    answer = ~csum
    answer = answer & 0xffff
    answer = answer >> 8 | (answer << 8 & 0xff00)
    return answer
def receiveOnePing(mySocket, ID, timeout, destAddr):
    global packageRev,timeRTT
    timeLeft = 1 #timeout
    while 1:
        #starts time
        startedSelect = time.time()
        #Reads from the socket
        whatReady = select.select([mySocket], [], [], timeLeft)
        howLongInSelect = (time.time() - startedSelect)
        #If whatReady is empty after 1 second, timeout
        if whatReady[0] == []:
            return "0: Destination Network Unreachable."
        timeReceived = time.time()
        # got this from textbook pg 164, 1024 is buffer size
        recPacket, addr = mySocket.recvfrom(1024)
        icmpHeader = recPacket[20:28]
        requestType, code, revChecksum, revId, revSequence = struct.unpack('bbHHh',icmpHeader)

        timeLeft = timeLeft - howLongInSelect
        if timeLeft <= 0:
            return "1: Destination Host Unreachable."

        #if the same ID, unpack the data
        if ID == revId:
            bytesInDouble = struct.calcsize('d')
            timeData = struct.unpack('d',recPacket[28:28 + bytesInDouble])[0]
            timeRTT.append(timeReceived - timeData)
            packageRev += 1
            return timeReceived - timeData
        else:
            return "ID is not the same!"

def sendOnePing(mySocket, destAddr, ID):
    global packageSent
    myChecksum = 0
    header = struct.pack("bbHHh", ICMP_ECHO_REQUEST, 0, myChecksum, ID, 1)
    data = struct.pack("d", time.time())
    myChecksum = checksum(header + data)

    # Get the right checksum from different platforms, and put in the header
    if sys.platform == 'darwin':
        myChecksum = socket.htons(myChecksum) & 0xffff
        #Convert 16-bit integers from host to network byte order.
    else:
        myChecksum = socket.htons(myChecksum)
    header = struct.pack("bbHHh", ICMP_ECHO_REQUEST, 0, myChecksum, ID, 1)
    packet = header + data
    mySocket.sendto(packet, (destAddr, 1))
    packageSent += 1

def doOnePing(destAddr, timeout):
    icmp = socket.getprotobyname("icmp")

    #Create Socket here
    try:
        mySocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, icmp)
    except socket.error, (errno, msg):
        if errno == 1:
            raise socket.error(msg)

    myID = os.getpid() & 0xFFFF  #Return the current process id
    sendOnePing(mySocket, destAddr, myID)
    delay = receiveOnePing(mySocket, myID, timeout, destAddr)
    mySocket.close()
    return delay

def ping(host, timeout=1):
    #timeout=1 means: waits 1 second to recieve data from server before times out.
    dest = socket.gethostbyname(host)
    print "Pinging " + dest + " using Python:"
    print ""
    #Send ping requests to a server separated by approximately one second
    while 1 :
        delay = doOnePing(dest, timeout)
        print time.time()
        print "RTT:",delay
        print "maxRTT:", (max(timeRTT) if len(timeRTT) > 0 else 0), "\tminRTT:", (min(timeRTT) if len(timeRTT) > 0 else 0), "\naverageRTT:", float(sum(timeRTT)/len(timeRTT) if len(timeRTT) > 0 else float("nan"))
        packageLose = (((float(packageSent) - float(packageRev))/float(packageSent))*100)
        print "Package Lose Rate:", ("%.2f" % packageLose)
        print " "
        #send a ping every second
        time.sleep(1)
    return delay


#DIFFERENT DOMAIN NAMES ACROSS DIFFERENT CONTINENTS TO PING
    #local host
#ping("127.0.0.1")
    #North America
#ping("www.google.com")
    #Australia
#ping("www.sydney.edu.au")
    #Asia
#ping("www.pku.edu.cn")
    #Africa
ping("www.kyu.ac.ug")
    #South America
#ping("www5.usp.br")
