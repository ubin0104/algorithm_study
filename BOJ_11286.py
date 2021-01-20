import sys
sys.stdin = open("input.txt", 'r')

import heapq

N = int(sys.stdin.readline())
arr = []
i = 0
while i < N:
    n = int(sys.stdin.readline())
    if n:
        heapq.heappush(arr, (abs(n), 1 if n > 0 else -1))
    else:
        try:
            r = heapq.heappop(arr)
            print(r[0]*r[1])
        except:
            print(0)
    i += 1
