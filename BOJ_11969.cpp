#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int cow[4][100001];
 
int main() {
    int n, q;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        cow[num][i]++;
        cow[1][i] += cow[1][i - 1];
        cow[2][i] += cow[2][i - 1];
        cow[3][i] += cow[3][i - 1];
    }
    while (q--)
    {
        int a;
        int b;
        cin >> a>> b;
        int cnt = 0;
        cout << cow[1][b]-cow[1][a-1] << ' ' << cow[2][b]-cow[2][a-1] << ' ' << cow[3][b]-cow[3][a-1];
        cout << '\n';
    }
}