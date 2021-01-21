import sys
import copy

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs():
    global answer
    q = copy.deepcopy(virus)
    tmp = [[0] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            tmp[i][j] = arr[i][j]

    while len(q) != 0:
        t = q.pop()
        x = t[0]
        y = t[1]

        for t in range(4):
            nx = x + dx[t]
            ny = y + dy[t]
            if -1 < nx < n and -1 < ny < m:
                if tmp[nx][ny] == 0:
                    tmp[nx][ny] = 2
                    q.append([nx, ny])

    cnt = 0
    for i in tmp:
        for j in i:
            if j == 0:
                cnt += 1
    answer = max(cnt, answer)


def wall(x):
    if x == 3:
        bfs()
        return

    for i in range(n):
        for j in range(m):
            if arr[i][j] == 0:
                arr[i][j] = 1
                wall(x + 1)
                arr[i][j] = 0


n, m = map(int, sys.stdin.readline().split())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
answer = 0
virus = []

for i in range(n):
    for j in range(m):
        if arr[i][j] == 2:
            virus.append([i, j])

wall(0)
print(answer)