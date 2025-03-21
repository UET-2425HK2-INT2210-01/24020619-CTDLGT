#include <iostream>
#include <string>
#include <cstring>
#define MAX_NAME_LENGTH 100
#define MAX_CLASS_LENGTH 30
#define MAX_SIZE 10000

using namespace std;

class Node {
    public:
        int ID;
        string name;
        string Class;
    
        Node(int id, string studentName, string className) : ID(id), name(studentName), Class(className) {}
    };
    
    class studentList {
    private:
        Node* list[MAX_SIZE];
    public:
        studentList() {
            for (int i = 0; i < MAX_SIZE; i++) {
                list[i] = nullptr;
            }
        }
    
        int hashFunc(int id) {
            return id % MAX_SIZE;
        }
    
        void Insert(int id, string nameArr, string ClassArr) {
            int i = hashFunc(id);
            while (list[i] != nullptr && i < MAX_SIZE) {
                if (list[i]->ID == id) {
                    list[i]->name = nameArr;
                    list[i]->Class = ClassArr;
                    return;
                }
                i = (i + 1) % MAX_SIZE;
            }
            if (i < MAX_SIZE) {
                list[i] = new Node(id, nameArr, ClassArr);
            }
        }
    
        void Delete(int id) {
            int i = hashFunc(id);
            while (list[i] != nullptr) {
                if (list[i]->ID == id) {
                    delete list[i];
                    list[i] = nullptr;
                    return;
                }
                i = (i + 1) % MAX_SIZE;
            }
        }
    
        void Infor(int id) {
            int i = hashFunc(id);
            while (list[i] != nullptr) {
                if (list[i]->ID == id) {
                    cout << list[i]->name << "," << list[i]->Class << endl;
                    return;
                }
                i = (i + 1) % MAX_SIZE;
            }
            cout << "NA,NA" << endl;
        }
    };

// int main() {
//     studentList List;
//     cout << "Enter exit to out";
//     while(1){
//         string op; cin >> op;
//         if (op.substr(0, 6) == "Insert"){
//             string temp = "";
//             int cnt = 7;
//             int id;
//             string studentName;
//             string className;
//             for (int i = 7; i < (int)op.length(); i++){
//                 cnt++;
//                 if (op[i] == ',') break;
//                 temp += op[i];
//             }
//             id = stoi(temp);
//             int cnt2 = cnt;
//             int j = 0;
//             for (int i = cnt; i < (int)op.length(); i++){
//                 cnt2++;
//                 if (op[i] == ',') break;
//                 studentName[j++] = op[i];
//             }
//             j = 0;
//             for (int i = cnt2; i < (int)op.length(); i++){
//                 if (op[i] == ')') break;
//                 className[j++] = op[i];
//             }
//             List.Insert(id, studentName, className);
//         }
//         else if(op.substr(0, 5) == "Infor"){
//             int id;
//             string temp = "";
//             for (int i = 6; i < (int)op.length(); i++){
//                 if (op[i] == ')') break;
//                 temp += op[i];
//             }
//             id = stoi(temp);
//             List.Infor(id);
//         }
//         else if(op.substr(0, 6) == "Delete"){
//             int id;
//             string temp = "";
//             for (int i = 7; i < (int)op.length(); i++){
//                 if (op[i] == ')') break;
//                 temp += op[i];
//             }
//             id = stoi(temp);
//             List.Delete(id);
//         }
//         else if(op == "exit") break;    
//     }
    
//     return 0;
// }


// đoạn này em generate từ chatgpt do không biết làm như nào ạ :(
void parseInsertOperation(const string& op, int& id, string& name, string& className) {
    size_t firstComma = op.find(',');
    size_t secondComma = op.find(',', firstComma + 1);
    size_t paren = op.find(')');

    id = stoi(op.substr(7, firstComma - 7));
    name = op.substr(firstComma + 1, secondComma - (firstComma + 1));
    className = op.substr(secondComma + 1, paren - (secondComma + 1));
}

int main() {
    studentList List;
    while (true) {
        string op;
        cin >> op;
        if (op.substr(0, 6) == "Insert") {
            int id;
            string name, className;
            parseInsertOperation(op, id, name, className);
            List.Insert(id, name, className);
        } else if (op.substr(0, 5) == "Infor") {
            int id;
            size_t paren = op.find(')');
            id = stoi(op.substr(6, paren - 6));
            List.Infor(id);
        } else if (op.substr(0, 6) == "Delete") {
            int id;
            size_t paren = op.find(')');
            id = stoi(op.substr(7, paren - 7));
            List.Delete(id);
        } else if (op == "exit") {
            break;
        }
    }
    return 0;
