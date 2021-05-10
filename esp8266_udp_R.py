import socket

ip = '127.0.0.1' 
port = 4294
message = b' hi from python'
    

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sock.bind((ip, port))

while(True):
    data, addr = sock.recvfrom(256)
    print(f'received message: {data}')
