import socket

ip = '127.0.0.1' 
port = 4220
message = b' hi from python'
    

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# for i in range (1, 10):
#     sock.sendto(message, (ip ,port))
#     i += 1

# print(f'UDP target ip: {ip}')
# print(f'UDP target port: {port}')
# print (f'Message send: {message}')

sock.bind((ip, port))

while(True):
    data, addr = sock.recvfrom(256)
    print(f'received message: {data}')

