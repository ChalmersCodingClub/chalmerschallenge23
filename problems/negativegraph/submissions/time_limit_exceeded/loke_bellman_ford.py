#!/usr/bin/env python3

N, M, K, A, B = [int(x) for x in input().split()]
graph = [[] for _ in range(N)]
for i in range(M):
    a,b,c = [int(x) for x in input().split()]
    graph[a].append((c,b))

dist = [1e18 for _ in range(N)]
dist[A] = 0
# This is quadratic time, gives TLE
for _ in range(N-1):
    for a in range(N):
        for c,b in graph[a]:
            dist[b] = min(dist[b], dist[a]+c)

for a in range(N):
    for c,b in graph[a]:
        # If we have not yet converged, there must be a cycle
        if dist[a]+c < dist[b]:
            print("NEGATIVE CYCLE")
            exit()
if dist[B] == 1e18:
    print("INFINITY")
else:
    print(dist[B])
