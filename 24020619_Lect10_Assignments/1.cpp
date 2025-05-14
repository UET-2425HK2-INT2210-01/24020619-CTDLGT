#include <iostream>
#include <vector>
using namespace std;

// duyệt cây dfs 
void dfs(vector<vector<int>> &adj, vector<bool> &isVisited, int node) {
    // đánh dấu node đã được visit 
    isVisited[node] = true;
    // duyệt tất cả node hàng xóm
    for (int neighbor : adj[node]) {
        if (!isVisited[neighbor]) 
            // dfs tất cả node hàng xóm để đánh dấu 1 đồ thị liên thông tất cả các node là visited
            dfs(adj, isVisited, neighbor);
    } 
}
// đếm số lượng đồ thị liên thông 
int count(vector<vector<int>> adj, int n) {
    vector<bool> isVisited(n + 1, false);
    int cnt = 0;
    for (int i = 1; i < n + 1; i++) {
        // nếu node chưa đc visited thì nghĩa là có 1 đồ thị liên thông khác 
        if (!isVisited[i]) {
            cnt++;
            // kiểm tra tất cả node liên thông 
            dfs(adj, isVisited, i);
        }
    }
    return cnt;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    // danh sách kề 
    for (int i = 1; i < m + 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << count(adj, n);

    return 0;
}