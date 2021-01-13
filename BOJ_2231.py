def dec(num):
    sum = num
    while True:
        if num <= 0:
            break
        sum += num % 10
        num = num // 10
    return sum
n = int(input())
c = 0
for i in range(1, n + 1):
    b = dec(i)
    if b == n:
        c = i
        break
if c == 0:
    print(0)
else:
    print(c)
