X = input()
if X[0] == '0' :
    if X[1] == 'x' :  #16진수
        print(int(X,16))
    else : #8진수
        print(int(X,8))
else :
    print(X)
    
