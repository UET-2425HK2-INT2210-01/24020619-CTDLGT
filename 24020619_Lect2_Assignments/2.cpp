#include <iostream>
#include <string>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void insert(node *head, int p, int x){
    node *newNode = new node(x);
    node *temp = head;
    for (int i = 0; i < p - 1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_node(node *head, int p){
    node *temp = head;
    for (int i = 0; i < p - 1; i++){
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

int main(){
    int ops;
    cin >> ops;
    cin.ignore();
    node* head = nullptr;
    for (int i = 0; i < ops; i++){
        string op;
        cin >> op;
        if (op == "insert"){
            int p, x;
            cin >> p >> x;
            if (head == nullptr){
                head = new node(x);
            }
            else{
                insert(head, p, x);
            }
        }
        else if (op == "delete"){
            int p;
            cin >> p;
            delete_node(head, p);
        }
    }
    while (head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
}
