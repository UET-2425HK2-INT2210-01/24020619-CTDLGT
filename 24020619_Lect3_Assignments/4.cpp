#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Queue{
public:
    Queue(){
        size = 0;
        head = nullptr;
    }
    bool isEmpty(){
        return head == nullptr;
    }
    void Enqueue(int x){
        if (isEmpty()){
            head = new Node(x);
        }
        else{
            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = new Node(x);
        }
    }
    void Dequeue(){
        if (isEmpty()){
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    int getFront(){
        return head->data;
    }
    void Print(){
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
private:
    Node* head;
    int size;
};

// int main(){
//     Queue q;
//     q.Enqueue(1);
//     q.Enqueue(2);
//     q.Enqueue(3);
//     q.Enqueue(4);
//     q.Enqueue(5);
//     q.Print();
//     q.Dequeue();
//     q.Dequeue();
//     q.Print();
//     q.Enqueue(6);
//     q.Enqueue(7);
//     q.Print();
// }