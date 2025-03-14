#include <iostream>
using namespace std;

class Node  {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
class linkedList{
private:
    Node* head;
public:
    linkedList() {
        head = nullptr;
    }
    void append_x(int x) {
        if (head == nullptr) {
            head = new Node(x);
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(x);
    }
    bool search(int x) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == x) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void reverse() {
        Node* prev = nullptr;
        Node* cur = head;
        Node* next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    // Node* reverse() {
    //     Node* p = nullptr;
    //     Node* temp = head;
    //     while (temp != nullptr) {
    //         Node* newNode = new Node(temp->data);
    //         newNode->next = p;
    //         p = newNode;
    //         temp = temp->next;
    //     }
    //     return p;
    // }
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    linkedList list;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (s == "append"){
            int x; cin >> x;
            list.append_x(x);
        }
        else if (s == "search"){
            int x; cin >> x;
            cout << list.search(x) << '\n';
        }
        else if (s == "reverse"){
            // list.print(list.reverse());
            list.reverse();
            list.print();
        }
    }

    return 0;
}

