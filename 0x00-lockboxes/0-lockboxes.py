#!/usr/bin/python3
"""Task 0 module"""


def canUnlockAll(boxes):
    """Can unlock"""
    keychain = {0}
    for _ in boxes:
        keychain = unlocker(boxes, keychain)
    return (len(keychain) is len(boxes))


def unlocker(boxes, keychain):
    """Unlocker"""
    padlocks = list(range(len(boxes)))
    for padlock in padlocks:
        if padlock in keychain:
            keychain.update(boxes[padlock])
    return keychain
