#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

void insert(Node* head, int x){
    Node* newNode = new Node(x);
    Node* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}
void deleteNode(Node*& head){
    if (head == nullptr) return;
    head = head->next;
}

int main(){
    int ops; cin >> ops;
    cin.ignore();
    Node* head = nullptr;
    for (int i = 0; i < ops; i++){
        string op;
        cin >> op;
        if (op == "enqueue"){
            if (head == nullptr){
                int x;
                cin >> x;
                head = new Node(x);
            }
            else {
                int x;
                cin >> x;
                insert(head, x);
            }
        }
        else if (op == "dequeue"){
            deleteNode(head);
        }
    }
    while (head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}
