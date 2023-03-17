v1='cbtcqLUBChERV[[Nh@_X^D]X_YPV[CJ'
v2=0x37
flag=""
for i in v1:
    flag+=chr(ord(i)^v2)
print(flag)