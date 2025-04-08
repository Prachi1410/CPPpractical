#include <iostream>
#include <string>
using namespace std;

class Rectangle {
private:
    string name;
    double length;
    double width;

public:
    void setDetails(string n, double l, double w) {
        name = n;
        length = l;
        width = w;
    }

    void display() {
        cout << "Rectangle Name: " << name << endl;
        cout << "Area: " << length * width << endl;
        cout << "Perimeter: " << 2 * (length + width) << endl;
    }
};

int main() {
    Rectangle r;
    string name;
    double length, width;

    cout << "Enter rectangle name: ";
    getline(cin, name);
    cout << "Enter length and width: ";
    cin >> length >> width;

    r.setDetails(name, length, width);
    r.display();

    return 0;
}
