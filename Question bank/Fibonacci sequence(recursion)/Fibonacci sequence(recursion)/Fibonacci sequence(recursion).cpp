#include<iostream>
using namespace std;
int Fibonacci(int x) {
	if (x == 0) {
		return 0;
	}
	if(x == 1) {
		return 1;
	}
	if (x >= 2) {
		return Fibonacci(x - 1) + Fibonacci(x - 2);
	}
	return -1;
}
int main() {
	int x;
	cin >> x;
	cout << Fibonacci(x)<< endl;
	return 0;
}