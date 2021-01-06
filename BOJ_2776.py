test = int(input())
cnt = [0,0,0,0,0]

n = int(input())
lst_1 = [int(n) for n in input().split()]
    
m = int(input())
lst_2 = [int(m) for m in input().split()]

for j in range(0,m) :
    for i in range(0,n) :
        if(lst_2[j]==lst_1[i]) :
            cnt.pop(j)
            cnt.insert(j,1)
        else :
            continue;

for j in range(0,m) :
    print(cnt[j])

    
