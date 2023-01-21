#!/usr/bin/env python3
from heapq import heappush, heappop

N, M, K, A, B = [int(x) for x in input().split()]
graph = [[] for _ in range(N)]
for i in range(M):
    a,b,c = [int(x) for x in input().split()]
    graph[a].append((c,b))

# Dijstra from A until we meet reach node through negative edge.
# Then restart Dijstra from both A and this node, removing the negative edge.
# Restart again whenever we reach a node through a negative edge.
# We will perform at most K Dijstras.

def try_dijkstra(starts):
    dist = [1e18]*N
    pq = starts[:]
    negtraversal = []
    for d,i in starts:
        dist[i] = d
    while len(pq) > 0:
        d,i = heappop(pq)
        for c,j in graph[i]:
            if d+c >= dist[j]:
                continue
            if c < 0:
                heappush(negtraversal, (d+c, j))
                continue
            dist[j] = d+c
            heappush(pq, (d+c, j))
    if len(negtraversal) > 0:
        for (d,i) in starts:
            if i == negtraversal[0][1]:
                assert negtraversal[0][0] < d
                print("NEGATIVE CYCLE")
                exit()
        heappush(starts, negtraversal[0])
    else:
        if dist[B] == 1e18:
            print("INFINITY")
        else:
            print(dist[B])
        exit()

starts = [(0, A)]
while True:
    try_dijkstra(starts)
