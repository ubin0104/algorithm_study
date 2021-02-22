#include<iostream>
#include<cmath>
 
#define endl "\n"
#define MAX 30
using namespace std;
 
int N, M;
int Weight[MAX];
int Find[7];
bool Visit[MAX + 1][MAX * 500 + 1];
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Weight[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> Find[i];
    }
}
 
void Make_Weight(int Cnt, int Result)
{
    if (Cnt > N) return;
    if (Visit[Cnt][Result] == true) return;
 
    Visit[Cnt][Result] = true;
 
    Make_Weight(Cnt + 1, Result + Weight[Cnt]);
    Make_Weight(Cnt + 1, Result);
    Make_Weight(Cnt + 1, abs(Result - Weight[Cnt]));
}
 
void Solution()
{
    Make_Weight(0, 0);
    for (int i = 0; i < M; i++)
    {
        if (Find[i] > MAX * 500) cout << "N ";
        else if (Visit[N][Find[i]] == true) cout << "Y ";
        else cout << "N ";
    }
    cout << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
