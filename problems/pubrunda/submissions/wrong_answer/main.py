#!/usr/bin/env python3

longest = 0
pub = ""
for _ in range(int(input())):
    p, k, t = input().split()
    if int(k) * int(t) >= longest:
        longest = int(k) * int(t)
        pub = p
print(pub)