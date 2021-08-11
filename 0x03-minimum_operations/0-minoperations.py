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
    copy = n
    operations = 0
    while copy > 1:
        if is_prime(copy):
            operations += copy
            copy = int(copy / copy)
        else:
            divisor = min_divisor(copy)
            operations += divisor
            copy = int(copy / divisor)
    return int(operations)


def min_divisor(num):
    """function to calculate the min divisor"""
    for i in range(2, num+1):
        if num % i == 0:
            return i
