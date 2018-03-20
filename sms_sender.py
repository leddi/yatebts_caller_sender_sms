#!/usr/bin/env python
import csv
import socket
import telnetlib
serv= ("localhost", 5038)
port= 5038

sck=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sck.connect(serv)
sck.send("javascript load custom_sms" + "\n")

# csv-datei  IMSI-Empfänger,MSISDN-Sender,Text,Zeitraster
with open ('sms_1.csv') as csvfile:
	reader = csv.reader(csvfile, delimiter=',')
	empfaenger = []
	sender = []
	text = []
	zeit = []
	for row in reader:
		empf = row[0]
		sende = row[1]		
		txt  = row[2]
		zeit1 = row[3]
		
		empfaenger.append(empf)
		text.append(txt)
		sender.append(sende)
		zeit.append(zeit1)
		
	print(empfaenger)
	print(text)
	print(sender)
	print(zeit)

for e in range(len(text)):
	m = "control custom_sms called="
	m += empfaenger[e]
	m += " caller="
	m += sender[e]
	m += " text="
	m += text[e]
	
	sck.send(m + "\n")
	print sck.recv(4069)
	time.sleep(int(zeit[e]))

sck.close()
del sck
