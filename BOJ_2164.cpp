#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(void) {
    int* arr;
    arr = (int*)malloc(sizeof(int) * 1000000);
    int i, front = 1, back, cnt = 0;
    scanf("%d", &back);

    for (i = 1; i <= back; i++) {
        arr[i] = i;
    }
    if (back == 1) {
        printf("1");
    }
    while (front != back) {

        arr[front] = 0;
        front++;
        if (front == back) {
            printf("%d", arr[front]);
            break;
        }
        back++;
        arr[back] = arr[front];
        arr[front] = 0;
        front++;
    }
    free(arr);
}