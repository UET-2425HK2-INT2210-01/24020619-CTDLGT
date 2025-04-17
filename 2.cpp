#include <iostream>
using namespace std;

long long factorial(int n) {
    // 0! = 1 
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n; cin >> n;
    cout << factorial(n);

    return 0;
}