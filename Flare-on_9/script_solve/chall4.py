a = [0x50, 0x5E, 0x5E, 0xa3, 0x4f, 0x5b, 0x51, 0x5e, 0x5e, 0x97, 0xa3, 0x80, 0x90, 0xa3, 0x80, 0x90, 0xa3, 0x80, 0x90, 0xa3, 0x80, 0x90, 0xa3, 0x80, 0x90, 0xa3, 0x80, 0x90, 0xa3, 0x80, 0x90, 0xa2, 0xa3, 0x6b, 0x7f]

for i in a:
	print(chr(0xC3-i), end="")