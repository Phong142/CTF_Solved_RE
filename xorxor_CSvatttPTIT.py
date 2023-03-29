
import binascii

s = binascii.unhexlify("0121317d1d5d0701636e355f4b237e")
l = len(s)
for byte in range(256):
    flag = [c for c in s]
    key = byte
    pbyte = 0
    for j in range(2606):
        p = [0] * l
        p[l - 1] = key ^ pbyte
        for i in range(l - 1)[::-1]:
            p[i] = p[i + 1] ^ flag[i + 1]
            key = p[i]
        pbyte = flag[0]
        flag = p
    flag = "".join([chr(c) for c in flag])
    if "ATTT{" in flag:
        print(flag)