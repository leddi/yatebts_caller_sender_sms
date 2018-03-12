import csv
import time
import socket
import telnetlib
serv= ("localhost", 5038)
port= 5038

sck=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sck.connect(serv)
sck.send("javascript load custom_sms" + "\n")


with open ('call_1.csv') as csvfile:
	reader = csv.reader(csvfile, delimiter=',')
	empfaenger = []
	wave = []
	for row in reader:
		empf = row[0]
		wav  = row[1]
		
		empfaenger.append(empf)
		wave.append(wav)
		
	print(empfaenger)
	print(wave)



for e in range(len(wave)):
	m = "call wave/play//home/yate/wave/"
	m += wave[e]
	m += " ybts/IMSI"
	m += empfaenger[e]

	sck.send(m + "\n")
	print sck.recv(128)
	time.sleep(20)

sck.close()
del sck
