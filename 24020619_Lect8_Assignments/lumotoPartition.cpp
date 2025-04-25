#include <iostream>
using namespace std;
#include <vector>

// Lomuto partition
int partition(vector<int>& vec, int left, int right) {
    int pivot = vec[right]; // Chọn pivot là phần tử cuối
    int i = left - 1; // Chỉ số của phần tử nhỏ hơn pivot
    for (int j = left; j < right; j++) {
        if (vec[j] < pivot) { // Nếu phần tử nhỏ hơn pivot, hoán đổi
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[right]); // Đặt pivot vào đúng vị trí
    return i + 1; // Trả về chỉ số vị trí của pivot
}

// Đệ quy quickSort
void quickSort(vector<int>& vec, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(vec, left, right); // Chia mảng thành 2 phần
        quickSort(vec, left, pivotIndex - 1); // Sắp xếp phần trái của pivot
        quickSort(vec, pivotIndex + 1, right); // Sắp xếp phần phải của pivot
    }
}

int main() {
    int n; cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    quickSort(vec, 0, n - 1); 
    for (int data : vec) {
        cout << data << " "; 
    return 0;
}