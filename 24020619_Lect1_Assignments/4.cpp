#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
    for (int val : a){
        cout << val << " ";
    }

    return 0;
}