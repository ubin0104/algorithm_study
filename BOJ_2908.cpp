#include <iostream>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	
	int _A = 0, _B = 0;
	for (int i = 0; i < 3; i++) {
		int mul = 1;
		for (int j = i; j > 0; j--) {
			mul *= 10;
		}
		_A += (A[i] - '0') * mul;
		_B += (B[i] - '0') * mul;
	}
	if (_A > _B) cout << _A;
	else cout << _B;
	return 0;
}