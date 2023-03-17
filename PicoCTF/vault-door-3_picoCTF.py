flag='jU5t_a_sna_3lpm12g94c_u_4_m7ra41'
passs=[None]*32

for i in range(0,8):
    passs[i]=flag[i]
for i in range(8,16):
    passs[i]=flag[23-i]
for i in range(16,32,2):
    passs[i]=flag[46-i]
for i in range(31,16,-2):
    passs[i]=flag[i]

print("picoCTF{{{}}}".format(''.join(passs)))