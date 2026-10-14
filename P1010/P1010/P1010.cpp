#include<iostream>
using namespace std;

void exponent(int x) {
    bool first = true; 
    for (int i = 15; i >= 0; i--) { 
        int j = 1 << i; 
        if (x >= j) {
            if (!first) {
                cout << "+";
            }
            first = false;
            if (i == 0) {
                cout << "2(0)";
            }
            else if (i == 1) {
                cout << "2";
            }
            else {
                cout << "2(";
                exponent(i); 
                cout << ")";
            }
            x -= j;
        }
    }
}

int main() {
    int x;
    cin >> x;
    exponent(x);
    return 0;
}