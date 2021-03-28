#include <bits/stdc++.h>
using namespace::std;
 
void solve(){
    int a,b,c,ab,bc,ca;
    scanf("%d %d %d",&a,&b,&c);
    scanf("%d %d %d",&ab,&bc,&ca);
 
    int ans=0;
    for(int i=0; i<=min(a,b); i++)
        for(int j=0; j<=min(b-i,c); j++){
            int k = min(a-i, c-j);
            ans = max(ans, ab*i+bc*j+ca*k);
        }
    
    printf("%d\n",ans);
}
 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}