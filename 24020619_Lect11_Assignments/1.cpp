#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
#define INF 10000000

// danh sách cạnh lưu cạnh (u, v) và trọng số w
struct Edge{
    int u, v, w;
    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
// thuật toán Bellman-Ford
// đầu vào: n là số đỉnh, S là đỉnh bắt đầu, e là danh sách cạnh, D là danh sách khoảng cách từ S đến các đỉnh
void bellmanFord(int n, int S, vector<Edge> &e, vector<int> &D, vector<int> &trace) {
    D[S] = 0;
    // duyệt đồ thị n - 1 lần để tìm đường đi ngắn nhất
    for (int i = 1; i < n; i++) {
        for (Edge edge : e) {
            int w = edge.w;
            int u = edge.u;
            int v = edge.v;
            // nếu D[u] != INF và D[v] > D[u] + w thì cập nhật D[v] = D[u] + w
            // và lưu lại đỉnh trước đó của v là u
            if (D[u] != INF && D[v] > D[u] + w) {
                trace[v] = u;
                D[v] = D[u] + w;
            }
        }
    }
}
// truy vết đường đi từ S đến u
vector<int> path(vector<int> &trace, int S, int u) {
    // nếu u không phải là đỉnh S và không có đường đi từ S đến u thì trả về vector rỗng
    if (u != S && trace[u] == -1) return vector<int>(0);
    vector<int> path;
    while (u != -1) {
        path.push_back(u);
        // u = đỉnh trước của u
        u = trace[u];
    }
    // do mảng path chứa đỉnh từ u đến S nên cần đảo ngược lại
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // lấy dữ liệu
    ifstream fin;
    // viết dữ liệu 
    ofstream fout;
    fin.open("dirty.txt");
    fout.open("dirty.out");
    int n, m, s, e; fin >> n >> m >> s >> e;
    vector<Edge> edge; // danh sách cạnh 
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        edge.emplace_back(u, v, w);
    }
    // task 1 
    vector<int> D(n + 1, INF); // tạo mảng D với kích thước n + 1 và gán tất cả các phần tử là INF
    vector<int> trace(n + 1, -1); // tạo mảng trace với kích thước n + 1 và gán tất cả các phần tử là -1
    bellmanFord(n, s, edge, D, trace);
    vector<int> p = path(trace, s, e);
    fout << D[e] << '\n';
    for (int i : p) {fout << i << " ";}
    fout << endl;

    // task 2
    for (int i = 1; i <= n; i++) {
        vector<int> D(n + 1, INF);
        vector<int> trace(n + 1, -1);
        bellmanFord(n, i, edge, D, trace);
        for (int i = 1; i < D.size(); i++) {fout << D[i] << " ";}
        fout << endl;
    }

    return 0;
}