#include <iostream>
using namespace std;

int calculate1(int n){ // O(n)
    int ret = 1;
    for (int i = 0; i < n; i++){
        ret *= 2;
    }
    return ret;
}
int calculate2(int n){ // O(Log(n))
    if (n == 0) return 1;
    if (n % 2) return 2 * calculate2(n - 1);
    else 
        return calculate2(n / 2) * calculate2(n / 2);
}   

int main(){
    int n; cin >> n;
    if (n < 0) cout << 1.0 / calculate2(abs(n));
    else {
        cout << calculate2(n);
    }
    return 0;
}