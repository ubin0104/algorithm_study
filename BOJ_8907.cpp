#include <bits/stdc++.h>
using namespace::std;
 
int n, sum;
int cnt[1005];
 
void solve(){
    scanf("%d",&n);
    
    sum=0;
    for(int i=0; i<n; i++)
        cnt[i] = 0;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int in;
            scanf("%d",&in);
            cnt[i]+=in;
            cnt[j]+=in;
        }
    }
    for(int i=0; i<n; i++)
        sum+=cnt[i]*(n-1-cnt[i]);
    printf("%d\n",n*(n-1)*(n-2)/6-sum/2);
}
 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
