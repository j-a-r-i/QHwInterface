import socket, time

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('localhost', 8001))

msg = "{\"cmd\":\"foo\"}\n"

for i in range(10):
    s.sendall(msg)
    time.sleep(0.5)
s.close()