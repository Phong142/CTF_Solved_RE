import base64
a = "JTYzJTMwJTZlJTc2JTMzJTcyJTc0JTMxJTZlJTY3JTVm"
b= "JTY2JTcyJTMwJTZkJTVmJTYyJTYxJTM1JTY1JTVmJTM2"
c= "JTM0JTVmJTM4JTM0JTY2JTY0JTM1JTMwJTM5JTM1"
flag=""

flag1= base64.b64decode(a).decode('utf-8')
flag2= base64.b64decode(b).decode('utf-8')
flag3= base64.b64decode(c).decode('utf-8')

for i in range(0, len(flag1)):
    if(flag1[i]!='%'):
        flag+=flag1[i]
for i in range(0, len(flag2)):
    if(flag2[i]!='%'):
        flag+=flag2[i]
for i in range(0, len(flag3)):
    if(flag3[i]!='%'):
        flag+=flag3[i]

print("PICOCTF{", end="")
print(bytes.fromhex(flag).decode("ASCII"), end="")
print("}")