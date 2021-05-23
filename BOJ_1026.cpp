#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
bool comp(int a, int b) {
    return a > b;
}
 
int main() {
    int n, sum = 0;
    vector<int> a, b;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
 
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
 
    sort(a.begin(), a.end(), comp);
    sort(b.begin(), b.end());
 
    for (int i = 0; i < n; i ++)
        sum += a[i] * b[i];
 
    cout << sum;
 
    return 0;
}