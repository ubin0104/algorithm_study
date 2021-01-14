#DFS, 재귀

def DFS(i, sum) :
    if i == N+1 :  #현재 N+1이 된 경우 함수 종료
        global answer
        answer = max(answer, sum)
        return
    if i+t[i]<=N+1:  #i번째 날 일 하는 경우
        DFS(i+t[i], sum+p[i])
    if i+1 <= N+1 :  #i번째 날 일 안하는 경우 다음날로 넘어감(재귀)
        DFS(i+1,sum)

N = int(input())
t,p = [0], [0]
for i in range(N) :
    ti,pi = list(map(int,input().split()))
    t.append(ti)
    p.append(pi)

answer = 0
DFS(1,0)
print(answer)
