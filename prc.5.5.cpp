#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double Area() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const override { return length * width; }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() const override { return 3.1416 * radius * radius; } // Hardcoded pi
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(4, 5));
    shapes.push_back(new Circle(3));

    for (Shape* s : shapes)
        cout << "Area: " << s->Area() << endl;

    for (Shape* s : shapes)
        delete s;
}

