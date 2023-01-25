#!/usr/bin/env python3

N, M, K, A, B = [int(x) for x in input().split()]
graph = [[] for _ in range(N)]
for i in range(M):
    a,b,c = [int(x) for x in input().split()]
    graph[a].append((c,b))

dist = [1e18 for _ in range(N)]
dist[A] = 0
# This is quadratic time, gives TLE
for _ in range(N):
    for a in range(N):
        if dist[a] == 1e18:
            continue
        for c,b in graph[a]:
            dist[b] = min(dist[b], dist[a]+c)
dist_b_before = dist[B]
for _ in range(N):
    for a in range(N):
        if dist[a] == 1e18:
            continue
        for c,b in graph[a]:
            dist[b] = min(dist[b], dist[a]+c)
dist_b_after = dist[B]

if dist_b_after == 1e18:
    print("POSITIVE INFINITY")
elif dist_b_after != dist_b_before:
    print("NEGATIVE INFINITY")
else:
    print(dist[B])
