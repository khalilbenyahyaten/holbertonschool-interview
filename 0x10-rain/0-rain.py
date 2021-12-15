#!/usr/bin/python3
"""Rain distribution"""


def light(down, up):
    """Light"""
    if (up >= down):
        return (down)
    else:
        return (up)
    return (up)


def rain(walls):
    """rain"""
    res = 0
    x = 0
    for i in range(1, len(walls) - 1):
        l = walls[i]
        r = walls[i]
        for j in range(0, i):
            if (walls[j] > l):
                l = walls[j]
        for k in range(i + 1, len(walls)):
            if (walls[k] > r):
                r = walls[k]
        x = light(l, r) - walls[i]
        res += x
    return(res)
