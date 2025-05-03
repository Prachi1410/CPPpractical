#include <iostream>
#include <stack>
using namespace std;

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload + operator (add two points)
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    // Overload unary - operator (negate point)
    Point operator-() const {
        return Point(-x, -y);
    }

    // Overload == operator (compare points)
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Custom stack for undo functionality
class PointStack {
    stack<Point> s;

public:
    void push(const Point& p) { s.push(p); }
    Point pop() {
        Point p = s.top(); s.pop();
        return p;
    }
    bool empty() const { return s.empty(); }
};

int main() {
    PointStack history;
    Point p1(2, 3), p2(1, -1), result;

    // Operation 1: Add
    result = p1 + p2;
    history.push(p1);  // Save state before operation
    result.display();  // (3, 2)

    // Operation 2: Negate
    history.push(result);  // Save state before negation
    result = -result;
    result.display();  // (-3, -2)

    // Undo last operation
    if (!history.empty()) {
        result = history.pop();
        cout << "Undo: ";
        result.display();  // (3, 2)
    }

    return 0;
}

