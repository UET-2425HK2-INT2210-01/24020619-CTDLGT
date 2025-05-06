#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &num, int x, int n, vector<vector<int>> &memo) { 
    // trường hợp cơ sở 
    if (x == 0) return true;
    if (n == 0) return false;
    // sử dụng memozation để lưu kết quả 
    if (memo[n][x] != -1) return memo[n][x];
    // nếu có số thỏa mãn thì ta lây x - num[n-1], nếu không thì bỏ qua 
    if (num[n - 1] > x) {
        memo[n][x] = check(num, x, n - 1, memo);
        return memo[n][x];
    }
    else {
        // kiểm tra cả trường hợp nếu không trọn 
        memo[n][x] = check(num, x, n - 1, memo) || check(num, x - num[n - 1], n - 1, memo);
    }
    return memo[n][x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> num(n);
    vector<vector<int>> memo(n + 1, vector<int>(x + 1, -1));
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    if (check(num, x, n, memo)) {
        cout << "YES" << endl;
    } 
    else cout << "NO" << endl;

    return 0;
}