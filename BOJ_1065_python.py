num = int(input())
cnt = 0

for i in range(1,num+1) :
    a = i//100
    b = i%100 // 10
    c = i %10
    if a > 0 and a < 10 :
        if (a-b) == (b-c) :
            cnt = cnt + 1
    elif a == 0 :
        cnt = cnt + 1
    else :
        continue;
 
print(cnt)



