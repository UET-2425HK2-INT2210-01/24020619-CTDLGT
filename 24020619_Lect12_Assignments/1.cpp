#include <iostream>
#include <vector>
#include <stack>
#include <fstream> 
using namespace std;

// DFS và lưu kết quả từ dưới lên 
void topology(vector<vector<int>> &adj, vector<bool> &isVisited, int node, stack<int> &res) {
    isVisited[node] = true; // Đánh dấu node đã được duyệt
    // Duyệt tất cả các đỉnh kề với node đang xét 
    for (int i : adj[node]) {
        // Nếu đỉnh kề chưa được duyệt thì gọi đệ quy DFS
        if (!isVisited[i]) topology(adj, isVisited, i, res);
    }
    // Sau khi duyệt xong tất cả các đỉnh kề, push node vào stack
    res.push(node);
}
// sắp xếp topo 
void topoSort(vector<vector<int>> &adj, int n, stack<int> &res) {
    vector<bool> isVisited(n + 1, false); // Khởi tạo mảng đánh dấu đã duyệt
    // Duyệt tất cả các đỉnh từ 1 đến n
    for (int i = 1; i <= n; i++) {
        if (!isVisited[i]) topology(adj, isVisited, i, res);
    }
}

int main() {
    ifstream in("jobs.txt");
    ofstream out("jobs.out");
    
    int n, m; in >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y; in >> x >> y;
        adj[x].push_back(y);
    }
    stack<int> res;
    topoSort(adj, n, res);
    while (!res.empty()) {
        out << res.top() << ' ';
        res.pop();
    }

    return 0;
}