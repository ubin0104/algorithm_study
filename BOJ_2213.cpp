#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> vt, chd;
int n, g[10001], dp[10001][2], x, y, visited[10001];
pair<int, int> back[10001][2];
vector<int> r;
void dfs(int here, int par) {
    visited[here] = 1;
    if (here != 1)chd[par].push_back(here);
    for (auto next : vt[here]) {
        if (!visited[next])
            dfs(next, here);
    }
}
int func(int pos, int state) {
    int &ret = dp[pos][state];
    if (ret != -1)return ret;
    ret = 0;
    if (state) {
        ret = g[pos];
        for (auto next : chd[pos])
            ret += func(next, 0);
    }
    else {
        for (auto next : chd[pos])
            ret += max(func(next, 1), func(next, 0));
    }
    return ret;
}
void ff(int pos, int state) {
    if (state) {
        r.push_back(pos);
        for (auto next : chd[pos])
            ff(next, 0);
    }
    else {
        for (auto next : chd[pos]) {
            if (dp[next][1] >= dp[next][0])
                ff(next, 1);
            else
                ff(next, 0);
        }
    }
}
int main() {
    scanf("%d", &n);
    vt.resize(n + 1);
    chd.resize(n + 1);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
        scanf("%d", &g[i]);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    dfs(1, 0);
    int x = func(1, 0);
    int y = func(1, 1);
    if (x >= y)
        ff(1, 0);
    else
        ff(1, 1);
    printf("%d\n", max(x, y));
    sort(r.begin(), r.end());
    for (auto h : r)
        printf("%d ", h);
    return 0;
}
