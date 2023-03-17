first=[]
for i in range(97,123):
    first.append(i)
#print('',first)
differences= [0, 9, -9, -1, 13, -13, -4, -11, -9, -1, -7, 6, -13, 13, 3, 9, -13, -11, 6, -7]
for i in range(0,26):
    print(first[i])
    for j in range(0,20):
        print(chr(first[i]+differences[j]),end="")
    print('')