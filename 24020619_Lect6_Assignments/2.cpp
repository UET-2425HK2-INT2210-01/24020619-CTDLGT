#include <iostream>
#include <vector>
using namespace std;

class minHeap {
private:
    //cài đặt minHeap bằng mảng
    vector<int> heap;
    // nếu con là i thì bố là (i - 1) / 2
    int parent(int i) { return (i - 1) / 2; }
    // nếu bố là i thì con trái là 2*i + 1, con phải là 2*i + 2
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    // hàm đảm bảo tính chất con bé hơn cha
    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    // hàm đảm báo tính chất con bé hơn cha
    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);
        // tìm con bé nhất
        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;
        // đổi chỗ con bé nhất và bố
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }
public:
    void Insert(int key) {
        heap.push_back(key);
        int keyPos = heap.size() - 1;
        heapifyUp(keyPos);
    }
    void Delete(int key) {
        // Tìm vị trí của key trong heap
        int index = -1;
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == key) {
                index = i;
                break;
            }
        }
        if (index == -1) return;
        
        // Thay thế key bằng phần tử cuối cùng trong heap
        heap[index] = heap.back();
        // Xóa phần tử cuối cùng
        heap.pop_back();
        
        if (!heap.empty() && index < heap.size()) {
            if (index > 0 && heap[index] < heap[parent(index)])
                heapifyUp(index);
            else
                heapifyDown(index);
        }
    }
    void Print() {
        for (auto data : heap) {
            cout << data << " ";
        }
    }
};

int main() {
    int n;
    cout << "Enter number of insert value: ";
    cin >> n;
    minHeap minHeap;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        minHeap.Insert(x);
    }
    minHeap.Print();
    cout << endl;
    cout << "Enter number of delete value: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        minHeap.Delete(x);
    }

    return 0;
}