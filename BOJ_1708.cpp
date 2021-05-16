typedef long double ld;
typedef pair<ld, ld> P;
typedef pair<P, P> PP;
vector<P> v;
vector<int> st;
int startPoint,res;
ld x, y;
bool cmp(const P a, const P b) {
	if ((x - b.first)*(y - a.second) == (x - a.first)*(y - b.second)) {
		if (a.second == b.second)
			return a.first< b.first;
		else
			return a.second < b.second;
	}
	else {
		return (x - b.first)*(y - a.second) < (x - a.first)*(y - b.second);			
	}
}
ld ccw(PP a,P b) {
	P a1 = a.first,a2=a.second;
	ld ccw11 = (a1.first*a2.second + a2.first*b.second + b.first*a1.second)
		- (a2.first*a1.second + b.first*a2.second + a1.first*b.second);

	return ccw11;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ld q, w;
		cin >> q >> w;
		v.push_back({ q,w });
		if (v[startPoint].second > w ||(v[startPoint].second==w && v[startPoint].first> q)) {
			startPoint = i;
		}
	}
	x = v[startPoint].first;
	y = v[startPoint].second;
	sort(v.begin(), v.end(), cmp);
	st.push_back(0);
	st.push_back(1);
	int t = 1;
	int idx = 2;
	while (1) {
		if (idx == n) break;
		ld ccwV = ccw(make_pair(v[st[t-1]], v[st[t]]), v[idx]);
		if (ccwV>0) {
			st.push_back(idx);
			idx++;
			t++;
		}
		else if (ccwV == 0) {
			st.pop_back();
			st.push_back(idx);
			idx++;
		}
		else {
			st.pop_back();
			t--;
		}
	}
	cout << st.size() << '\n';
	return 0;
}