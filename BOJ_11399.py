#그리디알고리즘

N = int(input())
times_list = list(map(int, input().split()))
times_list.sort()

sum = 0
cnt = 0
for t in times_list:
    cnt += t
    sum += cnt
print(sum)
