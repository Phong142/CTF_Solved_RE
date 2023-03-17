e = "picoCTF{w1{1wq8/7376j.:}"
flag=""
for i in range(8, 23):
    if i%2==0:
        flag+=chr(ord(e[i])-5)
    else:
        flag+=chr(ord(e[i])+2)

print("PICOCTF{", end="")
print(flag, end="")
print("}")