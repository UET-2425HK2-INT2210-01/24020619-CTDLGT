#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findShortestPath(int n, int X, int Y, vector<vector<int>> adj) {
    if (X == Y) return 0; // Nếu X == Y thì đường đi ngắn nhất là 0
    queue<int> q; // sử dụng BFS
    q.push(X); // bắt đầu đi từ vị trí X
    vector<int> distance(n + 1, -1); // mảng lưu khoảng cách từ X đến các node khác 
    distance[X] = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        // Duyệt hàng hàng xóm của node hiện tại 
        for (int neighbor : adj[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1; // cật nhật khoảng cách
                if (neighbor == Y) return distance[neighbor];
                q.push(neighbor);
            }
        }
    }
    return -1; // đồ thị ko liên thông 
}

int main() {
    int n, m, X, Y; cin >> n >> m >> X >> Y;
    vector<vector<int>> adj(n + 1);
    // danh sách kề 
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y); // hướng từ x -> y 
    }
    cout << findShortestPath(n, X, Y, adj);

    return 0;
}