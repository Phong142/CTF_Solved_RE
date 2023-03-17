v6=7
v7='harambe'
v8=":\"AL_RT^L*.?+6/46"
flag=""
for i in range(0, len(v8)):
    flag+=chr(ord((v7[i%7]))^ord(v8[i]))
print(flag)