#include <iostream>
#include <stack>


using namespace std;

int main(int argc, char**argv) {

	ios::sync_with_stdio(0);
	cin.tie(0);
		
	stack<int> S;
	int K;
	int sum=0;
	
	cin >> K;
	
	while(K--){
		int N;
		cin >> N;
		
		if(N){
			S.push(N);
			sum+=N;
		}
		
		else{
			if(!S.empty()){
				sum-=S.top();
				S.pop();
			}
		}
	}
	
	cout << sum;
	
	return 0;
}