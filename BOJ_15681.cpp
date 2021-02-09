#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100001

int len[MAXN];
struct Tree{
    int par=-1;
    vector<int> children;
};
int N,R,Q;
vector<int> adj[MAXN];
Tree tree[MAXN];

void makeTree(int root, int par){
    for (int i = 0;i<adj[root].size(); i++){
        int next = adj[root][i];
        if (next != par){
            tree[root].children.push_back(next);
            tree[next].par = root;
            makeTree(next,root);
        }
    }
}
void countSubtreeNodes(int root){
    len[root] = 1;
    for (auto x : tree[root].children){
        countSubtreeNodes(x);
        len[root] += len[x];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> R >> Q;
    for (int i = 0 ;i <N-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    makeTree(R,-1);
    countSubtreeNodes(R);
    for (int i = 0 ;i <Q; i++){
        int num;
        cin >> num;
        cout << len[num]<<"\n";
    }
    return 0;
}