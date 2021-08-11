#!/usr/bin/python3
"""Minumun operations module"""


def is_prime(n):
    """Prime function"""
    if n == 2 or n == 3:
        return True
    if n < 2 or n % 2 == 0:
        return False
    if n < 9:
        return True
    if n % 3 == 0:
        return False
    r = int(n**0.5)
    f = 5
    while f <= r:
        #        print('\t', f)
        if n % f == 0:
            return False
        if n % (f+2) == 0:
            return False
        f += 6
    return True


def minOperations(n):
    """Min op function"""
    copy = int(n)
    operations = 0
    while copy > 1:
        if is_prime(copy):
            operations += copy
            copy = copy / copy
        elif copy % 2 == 0:
            operations += 2
            copy = int(copy / 2)
        elif copy % 3 == 0:
            operations += 3
            copy = int(copy / 3)
        elif copy % 5 == 0:
            operations += 5
            copy = int(copy / 5)
        elif copy % 7 == 0:
            operations += 7
            copy = int(copy / 7)
    return operations

def is_div(num):
    """Dunction"""
    for i in range(2, num):
        if num % i == 0:
            return i 
