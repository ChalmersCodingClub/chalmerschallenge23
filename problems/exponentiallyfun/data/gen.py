import sys
from random import randint, seed

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed(int(cmdlinearg('seed', sys.argv[-1])))

N = randint(2, 50_000)
print(N)
