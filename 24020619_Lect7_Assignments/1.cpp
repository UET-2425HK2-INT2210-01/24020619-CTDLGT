#include <iostream>
#include <fstream>
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
    for (int i = 0; i < temp.size(); i++) {
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
    // lấy dữ liệu
    ifstream fin;
    // viết dữ liệu 
    ofstream fout;
    fin.open("numbers.txt");
    vector<int> v;
    int x;
    while(fin >> x) {
        v.push_back(x);
    }
    mergeSort(v, 0, v.size() - 1);
    fout.open("numbers.sorted");
    for (int i = 0; i < v.size(); i++) {
        fout << v[i] << " ";
    }

    return 0;
}