#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int* v = new int[n];
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (v[i] == v[j]){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
