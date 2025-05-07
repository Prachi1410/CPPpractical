#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // Move in X direction
    Point* moveX(int a) {
        x += a;
        return this; // allows chaining
    }

    // Move in Y direction
    Point* moveY(int b) {
        y += b;
        return this; // allows chaining
    }

    // Move both X and Y
    Point* move(int a, int b) {
        x += a;
        y += b;
        return this;
    }

    // Display coordinates
    void display() {
        cout << "Point is at (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Dynamically allocate a Point object
    Point* p = new Point(10, 20);

    // Apply multiple movements using chaining
    p->moveX(5)->moveY(-10)->move(3, 4);

    // Display the result
    p->display();

    // Free the allocated memory
    delete p;

    return 0;
}

