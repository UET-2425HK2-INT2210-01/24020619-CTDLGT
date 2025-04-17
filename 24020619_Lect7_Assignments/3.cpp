#include <iostream>
using namespace std;

int gcd(int a, int b) {
    // thoát đệ quy 
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}