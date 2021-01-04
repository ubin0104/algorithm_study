#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) { // BOJ 4344
	int c, n, sum = 0, student;
	int score[100][100] = {};
	double avg = 0.0;
	double rate = 0.0;

	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		student = 0;
		sum = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &score[i][j]);
			sum += score[i][j];
		}
		avg = (double)sum / n;
		for (int j = 0; j < n; j++) {
			if (avg < score[i][j]) {
				student++;
			}
		}
		rate = (double)student / n * 100;
		printf("%.3f%\n", rate);
	}

}