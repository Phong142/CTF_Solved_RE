v = ["Dufhbmf", "pG`imos", "ewUglpt"]
flag = ''
for i in range(12):
    a = i % 3
    b = 2*int(i/3)
    flag += chr(ord(v[a][b])-1)

print(flag)