s="c61b68366edeb7bdce3c6820314b7498"
v3=1
flag=""

for i in range(len(s)):
    if(i&1):
        v3=1
    else:
        v3=-1
    flag+=chr(ord(s[i])+v3)

print(flag)