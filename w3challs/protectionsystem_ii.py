
import string
import random

def create_str(login):
    while True:
        ret = ''
        for i in range(len(login)):
            ret += random.choice(string.ascii_lowercase)

        if ascii_sum(ret) == ascii_sum(login) and verify_password(ret) == verify_login(login) and check_same_value(login, ret) == True and verify_password2(ret) == True: break

    return ret

def check_same_value(string_a, string_b):
    for a in string_a:
        if a in string_b: return False

    return True

def ascii_sum(string):
    result = 0
    for s in string:
        result += ord(s)

    return result

def verify_password(password):
    ret = ord(password[0])
    for i in range(len(password) - 1):
        if i % 2 == 0:
            ret = ret - ord(password[i + 1])

        else: # i % 2 == 1
            ret = ret + ord(password[i + 1])

    return ret

def verify_password2(password):
    len_p = len(password)
    for i in range(1, len(password) - 2):
        if i % 2 == 1: # s[i + 2] < s[i]
            if ord(password[i + 2]) >= ord(password[i]): return False

        else: # (2, 4) s[i + 2] > s[i]
            if ord(password[i + 2]) <= ord(password[i]): return False
        
    return ord(password[0]) > ord(password[-1:]) # s[0] > s[-1:]
    

def verify_login(login):
    ret = ord(login[0])
    for j in range(len(login) - 1):
        if j % 2 == 1:
            ret = ret - ord(login[j + 1])

        else:
            ret = ret + ord(login[j + 1])

    return ret

login = 'usera'

print("login : %s / password : %s" % (login, create_str(login)))
