#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > v;
vector<int> parents;

void dfs(int x) {
  for(int i = 0; i < v[x].size(); i++) {
    if(!parents[v[x][i]]) {
      parents[v[x][i]] = x;
      dfs(v[x][i]);
    }
  }
}

int main() {
  int n;
  int t1, t2;
  scanf("%d", &n);

  v.resize(n + 1);
  parents.assign(n + 1, 0);
  for(int i = 0; i < n - 1; i++) {
    scanf("%d %d", &t1, &t2);
    v[t1].push_back(t2);
    v[t2].push_back(t1);
  }

  parents[1] = 1;
  dfs(1);
  for(int i = 2; i <= n; i++) {
    printf("%d\n", parents[i]);
  }
}