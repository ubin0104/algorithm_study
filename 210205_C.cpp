#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int solution(int n, int m) {
    //answer은 재고가 떨어지는데 걸리는 날짜
    int answer = 0;
    // m일에 한 번 재고가 들어오는 날짜 flag
    int p = 0;
    // (1) 재고가 0이 될때까지 반복 
    while (n) {
        //(2) 재고는 1씩 감소, 날짜는 1씩 증가 
        n--;
        answer++;
        p++;
        // (3) 만약 m일이 지나면 재고 n은 1증가, 날짜 p는 다시 0
        if (p == m) {
            n++;
            p = 0;
        }
    }
    return answer;
}

int main() {
    int m;
    int n;
    int answer;
    scanf("%d %d", &n, &m);
    answer = solution(n, m);
    printf("%d", answer);
    return 0;
}