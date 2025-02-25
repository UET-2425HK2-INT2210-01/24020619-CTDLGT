#include <iostream>
using namespace std;

class Point{
    public: 
        double x, y;
        void import(){
            cin >> x >> y;
        }
};

class Line{ // y = ax + b
    public: 
        double a, b;
        Line(Point p1, Point p2){
            a = (p2.y - p1.y) / (p2.x - p1.x);
            b = p1.y - a * p1.x;
        }
};

void findInsertionPoint(Line l1, Line l2){
    if (l1.a == l2.a && l1.b == l2.b){
        cout << "MANY";
    }
    else if (l1.a == l2.a && l1.b != l2.b){
        cout << "NO";
    }
    else{
        double x, y;
        x = (l1.b - l2.b) / (l2.a - l1.a);
        y = l1.a * x - l1.b;
        cout << x << " " << y;
    }
}

int main(){
    Point p1, p2, p3, p4;
    p1.import();
    p2.import();
    p3.import();
    p4.import();
    Line l1(p1, p2), l2(p3, p4);
    findInsertionPoint(l1, l2);

    return 0;
}