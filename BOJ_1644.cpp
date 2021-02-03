#include <cstdio>
#include <vector>
using namespace std;

int n, sum, ans, left, right;
vector<int> a;

void prime() {
    vector<bool> c(n+1);
    for (int i=2; i*i<=n; i++) {
        if (!c[i]) {
            for (int j=i*i; j<=n; j+=i) {
                c[j] = true;
            }
        }
    }
    for (int i=2; i<=n; i++) {
        if (!c[i]) a.push_back(i);
    }
}

void solve() {
    int k = a.size();
    while (true) {
        if (sum >= n) {
            sum -= a[left];
            left++;
        } else {
            if (right == k) break;
            sum += a[right];
            right++;
        }
        if (sum == n) ans++;
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d", &n);
    prime();
    solve();
    return 0;
}


출처: https://rebas.kr/767 [PROJECT REBAS]