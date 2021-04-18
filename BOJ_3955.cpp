#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int T, K, C;

int GCD(int x, int y){
	if(y==0) return x;
	else return GCD(y, x%y);
return 0;
}
// ax+by=gcd(a,b) 가 되는 x, y 를 구함
pii ext_gcd(int a,int b){
    if(b){
        pii tmp = ext_gcd(b, a%b);
        return pii(tmp.second, tmp.first - (a/b) * tmp.second);
    } else return pii(1, 0);
}
// ax = 1 (mod M) 을 만족하는 x 구함, gcd(x,M)=1 일때만 해가 있다.
ll mod_inv(int a, int M){
    return (ext_gcd(a, M).first + M) % M;
}
int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
cin>>T;
while(T--){
	cin >> K >> C;
	if(GCD(C,K)!=1){
		cout << "IMPOSSIBLE" << '\n';
		continue;
	}
	// Cx = 1 (mod K) 를 구하는 문제이지만 사탕을 K명에게 나누어주려면 Cx > K
	ll ans = mod_inv(C,K);
	while(C*ans<=K) ans+=K;
	if(ans>1e9) cout << "IMPOSSIBLE" << '\n';
	else cout << ans << '\n';
}
return 0;
}