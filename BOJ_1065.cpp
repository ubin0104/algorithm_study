#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void num(int n) {
	int i, cnt = 0;
	for (i = 1; i <= n; i++) {
		if (i < 100) cnt++;
		else {
			if ((i / 100) - (i % 100 / 10) == (i % 100 / 10) - (i % 10)) cnt++;
		}
	}
	printf("%d", cnt);
}
int main() {
	int n;
	scanf("%d", &n);
	num(n);

	return 0;
}