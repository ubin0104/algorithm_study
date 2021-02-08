#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,-1,0,1 };

int n, m, k, cnt, a[111][111];
vector<int> v;

int dfs(int x, int y) {
    int ret = 1;
    a[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (!a[nx][ny]) ret += dfs(nx, ny);
    }
    return ret;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    while (k--) {
        int e, b, c, d;
        scanf("%d %d %d %d", &e, &b, &c, &d);
        for (int i = b; i < d; i++)
            for (int j = e; j < c; j++)
                a[i][j] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!a[i][j]) v.push_back(dfs(i, j));

    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for (auto now : v) printf("%d ", now);

    return 0;
}