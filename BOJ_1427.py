num = input("num : ")
answer = ''

sort_num = sorted(num, reverse=True)

for i in sort_num:
    answer += i

print(int(answer))