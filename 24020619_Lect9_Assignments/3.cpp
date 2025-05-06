#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt, int n) {
    // Base Case
    if (n == 0 || W == 0)
        return 0;
    int pick = 0; // lưu giá trị của vật nếu pick

    // nếu vật bé hơn Weigth hiện tại thì chọn
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsack(W - wt[n - 1], val, wt, n - 1);
    
    // Không chọn vật 
    int notPick = knapsack(W, val, wt, n - 1);
    // chọn value lớn nhất 
    return max(pick, notPick);
}

int main() {
    int n, X; cin >> n >> X;
    vector<int> w(n);
    vector<int> v(n);
    for (int i = 0;i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << knapsack(X, v, w, n);

    return 0;
}

