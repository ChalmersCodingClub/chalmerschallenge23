#!/usr/bin/env python3

from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
sums = [int(input()) for _ in range(n)]
graph = {}
for _ in range(m):
    i, j = map(int, input().split())
    if i in graph:
        graph[i].add(j)
    else:
        graph[i] = set([j])
    if j in graph:
        graph[j].add(i)
    else:
        graph[j] = set([i])

v = set()
def susdfs(node, amount):
    if node in v:
        return amount
    v.add(node)
    s = 0
    for i in graph[node]:
        s += susdfs(i, sums[i])

    return amount + s

best = 0
student = -1

for i in range(n):
    v = set()
    a = susdfs(i, 100)
    if best < a:
        best = a
        student = i
print(student)

