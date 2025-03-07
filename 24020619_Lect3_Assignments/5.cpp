#include <iostream>
using namespace std;

class Stack{
public:
    // time complexity O(1) || space complexity O(n)
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    // time complexity O(1) || space complexity O(1)
    bool isEmpty(){ 
        return top == -1; 
    }
    // time complexity O(1) || space complexity O(1)
    bool isFull(){
        return top == size - 1;
    }
    // time complexity O(1) || space complexity O(1)
    void Push(int x){
        if (isFull()){
            return;
        }
        arr[++top] = x;
    }
    // time complexity O(1) || space complexity O(1)
    void Pop(){
        if (isEmpty()){
            return;
        }
        top--;
    }
    // time complexity O(1) || space complexity O(1)
    int getTop(){
        return arr[top];
    }
    // time complexity O(n) || space complexity O(1)
    void print(){
        // bottom to top
        for (int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
private:
    int* arr;
    int top;
    int size;
};

// int main(){
//     int n; cin >> n;
//     Stack s(n);
//     for (int i = 0; i < n; i++){
//         int x; cin >> x;
//         s.Push(x);
//     }
//     cout << s.getTop() << '\n';
//     s.Pop();
//     s.print();  
// }

int main(){
    Stack s(5);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.print();
    s.Pop();
    s.Pop();
    s.print();
    s.Push(6);
    s.Push(7);
    s.print();
    return 0;
}