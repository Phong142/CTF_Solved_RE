import string

str_w3 = "W3challs Protection system"
str_pw = "Please enter your password :"

a0 = ord(str_w3[13]) - 3
a1 = ord(str_pw[14]) - 6
a2 = ord(str_w3[0]) - 0xC
a3 = ord(str_pw[1]) + 5
a4 = ord(str_w3[13]) - 9 + 3
a5 = ord(str_pw[14]) - 9 + 6
a6 = ord(str_w3[1]) - 8 + 9
a7 = ord(str_pw[1]) - 9 + 4
a8 = ord(str_w3[4]) + 9 * 2 + 7

flag = [chr(a0), chr(a1), chr(a2), chr(a3), chr(a4),
        chr(a5), chr(a6), chr(a7), chr(a8)]

print(''.join(flag))