#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool scompare(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	int N;
	cin >> N;

	string *sorted = new string[N + 1];
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		sorted[i] = word;
	}
	sort(sorted, sorted + N, scompare);
	for (int i = 0; i < N; i++) {
		if (sorted[i] != sorted[i + 1]) {
			if (i == N - 1) cout << sorted[i];
			else cout << sorted[i] << endl;
		}
	}
	return 0;
}