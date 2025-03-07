#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Stack{
private:
    Node* top;
    int size;
public:
    Stack(){
        size = 0;
        top = nullptr;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    bool isFull(){
        return size == 0;
    }
    void Push(int x){
        if (isEmpty()){
            top = new Node(x);
        } 
        else{
            Node* temp = new Node(x);
            temp->next = top;
            top = temp;
            size++;
        }
    }
    void Pop(){
        if (isEmpty()){
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int getTop(){
        return top->data;
    }
    void print(){
        Node* temp = top;
        // top to bottom
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// int main(){
//     int n; cin >> n;
//     Stack s;
//     for (int i = 0; i < n; i++){
//         int x; cin >> x;
//         s.Push(x);
//     }
//     cout << s.getTop() << '\n';
//     s.Pop();
//     s.print();
// }

int main() {
    Stack s;
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