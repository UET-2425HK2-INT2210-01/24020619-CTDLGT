#include <iostream>
using namespace std;

class Queue{
public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
        head = 0;
        tail = -1;
    }
    bool isEmpty(){ 
        return head > tail;
    }
    bool isFull(){
        return tail == size - 1;
    }
    void Enqueue(int x){
        if (isFull()){
            return;
        }
        arr[++tail] = x;
    }
    void Dequeue(){
        if (isEmpty()){
            return;
        }
        tail--;
        for (int i = head; i <= tail; i++){
            arr[i] = arr[i + 1];
        }
    }
    int getHead(){
        return arr[head];
    }
    void print(){
        for (int i = head; i <= tail; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
private:
    int* arr;
    int head;
    int tail;
    int size;
};

// int main(){
//     int n; cin >> n;
//     Queue q(n);
//     for (int i = 0; i < n; i++){
//         int x; cin >> x;
//         q.Enqueue(x);
//     }
//     cout << q.getHead() << '\n';
//     q.Dequeue();
//     q.print();

//     return 0;
// }
