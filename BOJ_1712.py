#시간초과 안나는 코드
A, B, C = map(int, input().split()) #한줄에 한번에 입력받는 함수

if C-B<=0 :
    print('-1')
else :
    print(-A//(B-C)+1)



#시간초과 남
#A, B, C = map(int, input().split()) 
#x = 1
#if C-B<=0 :
#    print('-1') 
#while True :
#    if A+B*x < C*x :
#        print(x)
#        break
#    else :
#        x = x+1
        
