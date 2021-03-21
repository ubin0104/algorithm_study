#include <iostream>
#include <algorithm>
using namespace std;

int N, C, ans, idx, aSize, bSize;
int wt[31], aSum[33000], bSum[33000];

void calcLeft(int i, int sum) {
	if (sum > C) return;
	if (i == N / 2) {
		aSum[aSize++] = sum;
		return;
	}
	calcLeft(i + 1, sum + wt[i]);
	calcLeft(i + 1, sum);
}

void calcRight(int i, int sum) {
	if (sum > C) return;
	if (i == N) {
		bSum[bSize++] = sum;
		return;
	}
	calcRight(i + 1, sum + wt[i]);
	calcRight(i + 1, sum);
}

void binarySearch(int st, int ed, long long val) {
	if (st > ed) return;
	int mid = (st + ed) / 2;

	if (bSum[mid] + val <= C) {
		idx = mid;
		binarySearch(mid + 1, ed, val);
	}
	else return binarySearch(st, mid - 1, val);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> wt[i];
	}

	calcLeft(0, 0);
	calcRight(N / 2, 0);
	sort(bSum + 0, bSum + bSize);

	ans = 0;
	for (int i = 0; i < aSize; i++) {
		idx = -1;
		binarySearch(0, bSize - 1, aSum[i]);
		ans += (idx + 1);
	}
	cout << ans << '\n';

	return 0;
}