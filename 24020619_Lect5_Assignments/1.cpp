#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* firstChild;
    Node* nextSibling;
    Node(int value){
        data = value;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};
class Tree{
public:
    Node* root;
    vector<Node*> nodeList;
    vector<bool> isChild;

    Tree(){
        root = nullptr;
    }
    // hàm cật nhật root trong trường hợp root được khai báo sau node khác 
    void updateRoot(){
        for (int i = 0; i < nodeList.size(); i++){
            if (nodeList[i] != nullptr && !isChild[i]){
                root = nodeList[i];
                // thoát ngay khi gặp root
                break;
            }
        }
    }
    void addNode(int parent, int child){
        // thay đổi size của array chứa node và array kiểm tra isChild
        if (parent >= nodeList.size()) nodeList.resize(parent + 1, nullptr);
        if (child >= nodeList.size()) nodeList.resize(child + 1, nullptr);
        if (parent >= isChild.size()) isChild.resize(parent + 1, false);
        if (child >= isChild.size()) isChild.resize(child + 1, false);
        // tạo node mới 
        if (nodeList[parent] == nullptr) nodeList[parent] = new Node(parent);
        if (nodeList[child] == nullptr) nodeList[child] = new Node(child);
        Node* parentNode = nodeList[parent];
        Node* childNode = nodeList[child];
        // kết nối giữa node bố và con cả 
        if (parentNode->firstChild == nullptr) {
            parentNode->firstChild = childNode;
        }
        // kết nối giữa node bố với anh em liền kề 
        else {
            Node* sibling = parentNode->firstChild;
            while (sibling->nextSibling != nullptr) {
                sibling = sibling->nextSibling;
            }
            sibling->nextSibling = childNode;
        }
        isChild[child] = true;
        // update lại để tìm root nếu root
        updateRoot();
    }
    // Sử dụng đệ quy để tính chiều cao từ dưới lên
    int height(Node* node){
        // TH cơ sở: thoát khi node = null
        if (node == nullptr) return 0;
        int maxDepth = 0;
        // Đầu tiên trỏ vào con cả
        Node* child = node->firstChild;
        // Iterate qua tất cả các con và tìm max
        while (child != nullptr){
            maxDepth = max(maxDepth, height(child));
            child = child->nextSibling;
        }
        return maxDepth + 1;
    }
    // sử dụng đệ quy để truy cập preOrder: root -> left -> right
    void preOrder(Node* node){
        // TH cở sở: thoát khi node = null
        if (node == nullptr) return;
        // bắt đầu từ root và print data khi đi qua mỗi node con cả
        cout << node->data << " ";
        // truy cập đến các phần tử con của mỗi node trước rồi đến các anh em của node đó
        preOrder(node->firstChild);
        preOrder(node->nextSibling);
    }
    // postOrder: left -> right -> root
    void postOrder(Node* node){
        if (node == nullptr) return;
        Node* child = node->firstChild;
        while (child != nullptr) {
            postOrder(child);
            child = child->nextSibling;
        }
        cout << node->data << " ";
    }
    bool isBinaryTree(Node* node) {
        if (node == nullptr) return true;
        Node* child = node->firstChild;
        int cnt = 0;
        while (child != nullptr) {
            cnt++;
            // truy cập qua tất cả các node 
            if (!isBinaryTree(child)) return false; 
            child = child->nextSibling;
        }
        return cnt <= 2;
    }
    void inOrder(Node* node) {
        if (node == nullptr) return;
        // Duyệt node con cả trước
        if (node->firstChild != nullptr) inOrder(node->firstChild);
        // Sau đó in node hiện tại
        cout << node->data << " ";
        // Cuối cùng duyệt anh em ngay cạnh bên 
        if (node->firstChild != nullptr) inOrder(node->firstChild->nextSibling);
    }
    
};

int main() {
    int n, m; cin >> n >> m;
    Tree tree;
    for (int i = 0; i < m; i++){
        int parent, child;
        cin >> parent >> child;
        tree.addNode(parent, child);
    }
    cout << tree.height(tree.root) << endl;
    tree.preOrder(tree.root); cout << endl;
    tree.postOrder(tree.root); cout << endl;
    if (tree.isBinaryTree(tree.root)) {
        tree.inOrder(tree.root);
        cout << endl;
    }
    else cout << "NOT BINARY TREE";
    return 0;
}
