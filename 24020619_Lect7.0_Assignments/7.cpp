#include <iostream>
#include <cmath>
using namespace std;

int reversereverse(int n) {
    if (n < 10) return n;
    int temp = n;
    // đếm số lượng chữ số trong n
    int cnt = 0;
    while (temp != 0) {
        temp /= 10;
        cnt++;
    }
    int digit = n % 10;
    // n * 10^(cnt - 1)
    return digit * pow(10, cnt - 1) + reversereverse(n / 10);
}

int main() {
    int n; cin >> n;
    cout << reversereverse(n);

    return 0;
}