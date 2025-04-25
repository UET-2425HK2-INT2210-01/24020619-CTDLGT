#include <iostream>
#include <vector>
using namespace std;

// hàm merge để gộp các mảng con đã đc sắp xếp 
void merge(vector<int>& v, int left, int mid, int right) {
    int i = left; int j = mid + 1;
    // biến tạm lưu mảng sắp xếp 
    vector<int> temp;
    // dùng pp 2 con trỏ để so sánh 
    while(i <= mid && j <= right) {
        if (v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else {
            temp.push_back(v[j]);
            j++;
        }
    }
    // thêm phần từ còn lại vào mảng temp 
    while(j <= right) {
        temp.push_back(v[j]);
        j++;
    }
    while(i <= mid) {
        temp.push_back(v[i]);
        i++;
    }
    for (int i = 0; i < temp.size() - 1; i++) {
        v[left + i] = temp[i];
    }
}
// tách 
void mergeSort(vector<int>& v, int left, int right) {
    // thoát đệ quy 
    if (left >= right) return;
    int mid = (left + right) / 2;
    // tách mảng 
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    // ghép 
    merge(v, left, mid, right);
}

int main() {
    int n; cin >> n;
    vector<int> v(n); 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    mergeSort(v, 0, v.size() - 1);
    for (int data : v) {
        cout << data << " ";
    }

    return 0;
}