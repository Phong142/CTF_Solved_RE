a = [0x66746369, 0x736f6a7b, 0x75687065, 0x72705f73, 0x656c626f, 0x70735f6d, 0x5f646565, 0x6f6f6f62, 0x6f6f6f6f, 0x7d74736f]
b = [0x66746369, 0x736f6a7b, 0x75687065, 0x72705f73, 0x656c626f, 0x70735f6d, 0x3f646565, 0x6f6f6f62, 0x6f6f6f6f, 0x7d74736f]
def reverse_hex(hex_str):
    return ''.join(reversed([hex_str[i:i+2] for i in range(0, len(hex_str), 2)]))

def solvenA():
    reversed_strings = [reverse_hex(hex(i)[2:]) for i in a]
    flag = ""
    for i in range(len(reversed_strings)):
        byte_array = bytes.fromhex(reversed_strings[i]).decode()
        flag += byte_array
    print("case 1: " + flag)

def solvenB():
    reversed_strings = [reverse_hex(hex(i)[2:]) for i in b]
    flag = ""
    for i in range(len(reversed_strings)):
        byte_array = bytes.fromhex(reversed_strings[i]).decode()
        flag += byte_array
    print("case 2: " + flag)

solvenA()
solvenB()

