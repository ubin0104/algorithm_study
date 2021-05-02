#include <stdio.h>
#include <algorithm>

int rope[100001];

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &rope[i]);

	int result = 0;
	std::sort(rope, rope + N);

	for (int i = 0; i < N; i++)
	{
		if (result < (N - i) * rope[i])
			result = (N - i) * rope[i];
	}

	printf("%d", result);
	
	return 0;
}