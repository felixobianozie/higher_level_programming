#!/usr/bin/python3
def uppercase(str):
    casechangevalue = 32
    t = ''
    for i in str:
        if ord('a') <= ord(i) <= ord('z'):
            t = t + chr(ord(i) - casechangevalue)
        else:
            t = t + i
    print("{}".format(t))
uppercase('best man')
