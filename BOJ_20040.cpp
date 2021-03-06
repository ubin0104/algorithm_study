#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
	fastio;
	int n, m; cin >> n >> m;
	vector<int> parent(n);

	iota(parent.begin(), parent.end(), 0);
	function<int(int)> Find = [&](int x) -> int {
		return x == parent[x] ? x : parent[x] = Find(parent[x]);
	};
	function<bool(int, int)> Union = [&](int a, int b) -> bool {
		a = Find(a), b = Find(b);
		if (a == b) return 0;
		if (a > b) swap(a, b);
		parent[b] = a;
		return 1;
	};

	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		if (!Union(a, b)) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
}
[출처] [BOJ] 20040번 - 사이클 게임|작성자 박진한