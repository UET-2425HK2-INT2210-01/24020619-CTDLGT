#include <iostream>
#include <vector>
using namespace std;


// Hoare partition
void quickSort(vector<int> &a, int left, int right) {
    // chia mảng thành 2 phần
    int i = left, j = right;
    // chọn pivot là phần tử giữa
    int pivot = a[(right + left) / 2];
    // chia dãy thành 2 phần
    while (i <= j) {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;

        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    // Gọi đệ quy để sắp xếp các nửa
    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);
}

int main() {
    int n; cin >> n;
    vector <int> v(n); 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    quickSort(v, 0, v.size() - 1);
    for (int data : v) {
        cout << data << " ";
    }

    return 0;
}