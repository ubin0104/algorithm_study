#최소힙 
import sys
import heapq

N = int(input())
numbers = []

for _ in range(N):
    temp = int(sys.stdin.readline())
    if temp > 0:
        heapq.heappush(numbers, temp)
    elif temp == 0:
        if len(numbers) == 0:
            print(0)
        else:
            print(heapq.heappop(numbers))
