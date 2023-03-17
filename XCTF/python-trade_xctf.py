import base64
correct ='XlNkVmtUI1MgXWBZXCFeKY+AaXNt'
first=base64.b64decode(correct)
s=''
for i in first:
    s+=chr((i-16)^32)
print(s)
