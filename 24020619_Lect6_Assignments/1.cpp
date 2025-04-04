#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* Insert(Node* node, int key) {
    // TH cơ sở
    if (node == nullptr) return new Node(key);
    // nếu key < node->data thì thêm vào cây con bên trái, ngược lại thêm vào cây con bên phải
    if (key < node->data) node->left = Insert(node->left, key);
    else if (key > node->data) node->right = Insert(node->right, key);
    return node;
}
// Duyệt cây theo thứ tự inorder (trái - gốc - phải)
void Inorder(Node* node) {
    if (node == nullptr) return;
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}
// lấy data của leaf bé nhất bên phải node đang xét
Node* findMin(Node* cur) {
    cur = cur->right;
    while (cur != nullptr && cur->left != nullptr) {
        cur = cur->left;
    }
    return cur;
}
Node* Delete(Node* node, int key) {
    if (node == nullptr) return node;
    // nếu key < node->data thì duyệt bên trái và ngược lại 
    if (key < node->data) node->left = Delete(node->left, key);
    else if (key > node->data) node->right = Delete(node->right, key);
    else {
        // TH có 1 con thì xóa node bố và trả về con còn lại 
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // TH có 2 con 
        // lấy data của lá bé nhất bên phải của Node đang xét (most left child of right subtree)
        Node* temp = findMin(node);
        node->data = temp->data;
        // xóa node lá trong cây con bên phải
        node->right = Delete(node->right, temp->data);
    }
    return node;
}

int main() {
    int n; // số lượng phần tử trong cây
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = Insert(root, x);
    }
    Inorder(root); cout << endl;
    cin >> n; // số lượng phần tử cần xóa
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = Delete(root, x);
    }

    return 0;
}