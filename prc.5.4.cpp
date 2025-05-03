#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit;

class Celsius {
public:
    double val;
    Celsius(double v = 0) : val(v) {}
    operator Fahrenheit();
    bool operator==(Fahrenheit f);
};

class Fahrenheit {
public:
    double val;
    Fahrenheit(double v = 32) : val(v) {}
    operator Celsius() { return Celsius((val - 32) * 5 / 9); }
};

Celsius::operator Fahrenheit() { return Fahrenheit(val * 9 / 5 + 32); }
bool Celsius::operator==(Fahrenheit f) {
    return abs(val - ((f.val - 32) * 5 / 9)) < 0.01;
}

int main() {
    Celsius c(100);
    Fahrenheit f = c;
    cout << c.val << "°C = " << f.val << "°F\n";

    Celsius c2 = Fahrenheit(212);
    cout << "Equal? " << (c == Fahrenheit(212) ? "Yes" : "No") << endl;

    // Queue example
    queue<Fahrenheit> q;
    q.push(Fahrenheit(32));
    q.push(Fahrenheit(212));

    while (!q.empty()) {
        Fahrenheit temp = q.front(); q.pop();
        Celsius conv = temp;
        cout << temp.val << "°F = " << conv.val << "°C\n";
    }

    return 0;
}
