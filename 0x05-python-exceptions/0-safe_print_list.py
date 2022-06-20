#!/usr/bin/python3

def safe_print_list(my_list=[1,2], x=3):
    count = 0
    if (x > 0):
        for i in range(x):
            try:
                print(f"{my_list[i]}")
                count = count + 1
            except:
                break
    return count
