enflag='izwhroz""w"v.K".Ni'
key=0x12
flag=''
s=[]
for i in range(0, key, 3):
    a=(ord(enflag[i])^key)-6
    b=(ord(enflag[i+1])^key)+6
    c=ord(enflag[i+2])^6^key
    s.append(a)
    s.append(b)
    s.append(c)

for i in s:
    flag+=chr(i)
print(flag)