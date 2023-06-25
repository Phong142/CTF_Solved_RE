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
        # tmp[j] = (char.decode("ascii"))
        # print(extract_number_from_cmd_color_string(char.decode("ascii")), end="")
        # print(char.decode("ascii"), end ="")
        file.write(char.decode("ascii"))
        # if(char.decode("ascii").isdigit()):
        #   if(char.decode("ascii") != " "):
        #     print(char, end = "")
        #   else:
        #     pint(" ")
        char = process.stdout.read(1)
    file.write("\n")
    # print(" ", i)
file.close()

with open("save.txt", "r") as file:
    cnt = 32
    for line in file:
      lines = line.strip().split()
      i = 0
    #   print(lines)
      for word in lines:
        # if(line.strip().split().isdigit()):
        #   print(line.strip().split())
        # print(int(word), end =" ")
        if(int(word) == 0):
          f[i] = cnt
        i+=1
    #   print(" " + str(cnt))
    #   print()
      cnt+=1
real_flag = ""
for i in f:
  real_flag += chr(i)
print(f'ATTT{{{real_flag}}}')
