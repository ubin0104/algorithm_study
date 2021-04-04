#include <iostream>
using namespace std;
 
int main() {
    int N, K, big = -101, sum = 0;
    cin >> N >> K;
    int *tmp = new int[N];
    for (int i = 0; i < N; i++)
        cin >> tmp[i];
    for (int i = 0; i <= N - K; i++)
    {
        for (int j = i; j < i + K; j++)
        {
            sum += tmp[j];
        }
        if (big < sum)
        {
            big = sum;
        }
        sum = 0;
    }
    cout << big;
}