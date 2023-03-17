a=int('0xcafe', 16)
hash=a*31337+(25%17)*11+7-1615810207

print(hex(hash))