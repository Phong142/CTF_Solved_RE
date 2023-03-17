import hashlib
import base64

key1 = "picoCTF{1n_7h3_|<3y_of_"
key2 = "xxxxxxxx"
key3 = "}"

user=b"FREEMAN"     #FREEMAN? hash256?

flag=""
stt = [4,5,3,6,2,7,1,8]
for i in stt:
    flag+= hashlib.sha256(user).hexdigest()[i]

key=key1+flag+key3
print(key)
