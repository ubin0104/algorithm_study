#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int solution(int n, int m) {
    //answer�� ��� �������µ� �ɸ��� ��¥
    int answer = 0;
    // m�Ͽ� �� �� ��� ������ ��¥ flag
    int p = 0;
    // (1) ��� 0�� �ɶ����� �ݺ� 
    while (n) {
        //(2) ���� 1�� ����, ��¥�� 1�� ���� 
        n--;
        answer++;
        p++;
        // (3) ���� m���� ������ ��� n�� 1����, ��¥ p�� �ٽ� 0
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