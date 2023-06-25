import subprocess
import re

flag =b"xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
f = [None] * 29
file = open("save.txt", "w")
for i in range(32,128):
    payload = flag.replace(b"x", chr(i).encode("ascii"))
    process = subprocess.Popen(["easyRE.exe"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    process.stdout.read(36)
    process.stdin.write(payload + b"\r\n")
    process.stdin.flush()
    process.stdout.read(7)
    char = process.stdout.read(1)
    while(char!=b"]"):
        file.write(char.decode("ascii"))
        char = process.stdout.read(1)
    file.write("\n")
file.close()

with open("save.txt", "r") as file:
    cnt = 32
    for line in file:
      lines = line.strip().split()
      i = 0
      for word in lines:
        if(int(word) == 0):
          f[i] = cnt
        i+=1
      cnt+=1
real_flag = ""
for i in f:
  real_flag += chr(i)
print(f'ATTT{{{real_flag}}}')
