#include <iostream>
#include <string>
using namespace std;

string bits;

void gen(int pos, int n) {
    // điều kiện thoát đệ quy 
    if (pos > n) {
        cout << bits << '\n';
        return;
    }
    for (int i = '0'; i <= '1'; i++) {
        bits += i;
        // thêm chữ số 
        gen(pos + 1, n);
        // xóa (quay lui)
        bits.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    bits = "";
    gen(1, n);

    return 0;
}