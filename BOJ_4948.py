def prime_num(n) : #소수 판별 함수
    if n!=1 :
        for j in range(2,n) :
            if n%j == 0 :
                return 'np' #소수 아님
    else :
        return 'np'
    return 'p'


while True :  #0입력시까지 계속됨
    n = int(input())
    cnt = 0
    if n==0 :
        break
    else:
        for i in range(n,2*n+1) :
            if prime_num(i) == 'p' :
                cnt += 1

    print(cnt)
            
