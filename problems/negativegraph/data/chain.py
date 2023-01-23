import sys
from random import randint, seed, shuffle, random
from math import isqrt

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed(int(cmdlinearg('seed', sys.argv[-1])))

K = randint(50, 100)
N = 2*K+1
M = 3*K
A = 0
B = N-1
edges = []
for i in range(K):
    weight = K+1-i
    edges.append([2*i, 2*i+2, 1])
    edges.append([2*i, 2*i+1, weight])
    edges.append([2*i+1, 2*i+2, -weight])

relabel = list(range(N))
shuffle(relabel)
A = relabel[A]
B = relabel[B]
for i in range(N):
    edges[i][0] = relabel[edges[i][0]]
    edges[i][1] = relabel[edges[i][1]]
shuffle(edges)

print(N, M, K, A, B)
for a, b, c in edges:
    print(a, b, c)
