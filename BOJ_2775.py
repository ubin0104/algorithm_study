T = int(input())
people = [[0]*15 for i in range(15)]

for j in range(1,15) :
    people[0][j] = j
        
for j in range(1, 15) :  #0층부터 k층까지
    for x in range(1,15) :  #1호부터 n호까지
            people[j][x] = people[j][x-1] + people[j-1][x] #j층의 x호의 사람수는 j-1층의 x호 사람들 + j층의 x-1호 사람

for i in range(0,T) :
    k = int(input())
    n = int(input())            
    print(people[k][n])
