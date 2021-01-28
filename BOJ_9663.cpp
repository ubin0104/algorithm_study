#include <cstdio>

int n, ans;
bool a[14], b[27], c[27];

void solve(int i) {
    if (i == n) {
        ans++;
        return;
    }
    for (int j=0; j<n; j++) {
        if (a[j] || b[i+j] || c[i-j+n-1]) continue;
        a[j] = b[i+j] = c[i-j+n-1] = true;
        solve(i+1);
        a[j] = b[i+j] = c[i-j+n-1] = false;
    }
}

int main() {
    scanf("%d", &n);
    solve(0);
    printf("%d\n", ans);
    return 0;
}


출처: https://rebas.kr/761 [PROJECT REBAS]