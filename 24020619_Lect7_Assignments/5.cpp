#include <iostream>
#include <string>
#include <vector>
using namespace std;

string num;
// ktra xem số đó đã đc sd hay chưa 
vector<bool> used;

void gen(int pos, int n) {
    // đk thoát đệ quy 
    if (pos > n) {
        cout << num << '\n';
        return;
    }
    // quay lui 
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            num += to_string(i);
            gen(pos + 1, n);
            num.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    num = "";
    used.resize(n + 1, false);
    gen(1, n);

    return 0;
}