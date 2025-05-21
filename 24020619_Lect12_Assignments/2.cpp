#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// lưu danh sách cạnh
struct Edge{
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
// hàm so sánh trọng số của cạnh
bool compareEdges(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

// cấu trúc dữ liệu DisjoinSet
class DisjoinSet{
private:
    vector<int> rank, parent; // 
public:
    DisjoinSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i; // cha của đỉnh i là chính nó 
        }
    }
    int find(int node) {
        if (parent[node] != node) { // nếu cha của node không phải là chính nó thì tìm gọi đệ quy để tìm node đại diện 
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    // kiểm tra xem 2 node có cùng 1 tập hợp không 
    bool sameSet(int x, int y) {
        return find(x) == find(y);
    }
    // hợp 2 tập hợp lại với nhau
    void unionSet(int x, int y) {
        int rootX = find(x); // đại diện của x
        int rootY = find(y); // đại diện của y
        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX; // nếu rank của rootX lớn hơn rootY thì gán cha của rootY là rootX
        else if (rank[rootY] > rank[rootX]) parent[rootX] = rootY; // và ngược lại 
        else { // TH bằng thì gán ngẫu nhiên và tăng rank của bố 
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};
// thuật toán Kruskal
int minimumCost(vector<Edge> &edges, int n) {
    // sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), compareEdges);
    vector<Edge> result; // lưu các cạnh đã chọn;
    DisjoinSet D(n);
    int ret = 0; // kết quả
    int cnt = 0; // số cạnh đã chọn
    for (Edge e : edges) {
        // kiểm tra xem đồ thị có liên thông không
        // nếu 2 đỉnh của cạnh không thuộc cùng 1 tập hợp thì nối chúng lại
        if (!D.sameSet(e.u, e.v)) {
            D.unionSet(e.u, e.v);
            ret += e.w;
            cnt++;
            result.push_back(e); // thêm cạnh vào kết quả
        }
        // nếu đã chọn đủ n - 1 cạnh thì dừng lại
        if (cnt == n - 1) break;
    }
    if (cnt != n - 1) return -1; 
    edges = result; // lưu lại các cạnh đã chọn
    return ret;
}

int main() {
    ifstream fin;
    fin.open("connection.txt");
    int n, m; fin >> n >> m;
    vector<Edge> edges;
    for (int i = 1; i <= m; i++) {
        int u, v, w; fin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    ofstream fout;
    fout.open("connection.out");
    fout << minimumCost(edges, n) << endl;
    for (int i = 0; i < n - 1; i++) {
        fout << edges[i].u << " " << edges[i].v << " " << edges[i].w << " " << endl;
    }   


    return 0;
}