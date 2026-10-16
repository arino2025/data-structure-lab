#include<iostream>
using namespace std;

void Fibonacci(int x) {
	
	if (x == 0) {
		cout << 0;
		return;
	}
	if (x == 1) {
		cout << 1;
		return;
	}
		
	
	if (x >= 2) {
		int temp1 = 0;
		int temp2 = 1;
		int figure = 0;
		for (int i = 1; i <x;i++){
			figure = temp1 + temp2;
			temp1 = temp2;
			temp2 = figure;
		}
		cout << figure;
	}
	
}
	
int main() {
	int x;
	cin >> x;
	Fibonacci(x);
	return 0;
}