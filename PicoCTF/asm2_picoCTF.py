e4=int('0x2e', 16)
e8=int('0x39', 16)

while e8<=int('0x63f3', 16):
    e4+=int('0x1', 16)
    e8+=int('0x80', 16)

print(hex(e4))


'''
asm2:   asm2(0xb,0x2e)
	<+0>:	push   ebp
	<+1>:	mov    ebp,esp
	<+3>:	sub    esp,0x10
	<+6>:	mov    eax,DWORD PTR [ebp+0xc]		    ;0x2e
	<+9>:	mov    DWORD PTR [ebp-0x4],eax		    ;0x2e	
	<+12>:	mov    eax,DWORD PTR [ebp+0x8]		    ;0x39
	<+15>:	mov    DWORD PTR [ebp-0x8],eax		    ;0x39
	<+18>:	jmp    0x509 <asm2+28>			
	<+20>:	add    DWORD PTR [ebp-0x4],0x1		    ;0x2f
	<+24>:	sub    DWORD PTR [ebp-0x8],0xffffff80	;add 0x80
	<+28>:	cmp    DWORD PTR [ebp-0x8],0x63f3	    ;!=
	<+35>:	jle    0x501 <asm2+20>
	<+37>:	mov    eax,DWORD PTR [ebp-0x4]
	<+40>:	leave  
	<+41>:	ret    
'''