import sys
from random import randint, seed
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed(int(cmdlinearg('seed', sys.argv[-1])))

N = int(cmdlinearg('N'))

print(N)
print(*[randint(0,10**9) for _ in range(N)], sep="\n")

adj = []
for i in range(1, N):
    adj.append([i, randint(0,i-1)])
    random.shuffle(adj[-1])
random.shuffle(adj)

for u,v in adj:
    print(u+1, v+1)
