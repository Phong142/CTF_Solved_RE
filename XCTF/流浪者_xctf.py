source="abcdefghiABCDEFGHIJKLMNjklmn0123456789opqrstuvwxyzOPQRSTUVWXYZ"
xor="KanXueCTF2019JustForhappy"

for i in xor:
    ind=source.index(i)
    if ind>=0 and ind<10:
        print(chr(ind+48),end="")
    elif ind>=10 and ind<36:
        print(chr(ind+87),end="")
    else:
        print(chr(ind+29),end="")
