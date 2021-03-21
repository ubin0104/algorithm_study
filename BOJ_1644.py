n = int(input())
a = []

def prime():
    c = [False]*(n+1)
    for i in range(2, n+1):
        if i*i > n:
            break
        if not c[i]:
            for j in range(i*i, n+1, i):
                c[j] = True
    for i in range(2, n+1):
        if not c[i]:
            a.append(i)

def solve():
    left = right = ans = s = 0
    k = len(a)
    while True:
        if s >= n:
            s -= a[left]
            left += 1
        else:
            if right == k:
                break
            s += a[right]
            right += 1
        if s == n:
            ans += 1
    print(ans)

prime()
solve()