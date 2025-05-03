#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload << operator (output)
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) os << " + " << c.imag << "i";
        else os << " - " << -c.imag << "i";
        return os;
    }

    // Overload >> operator (input)
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};

// Demonstrating batch operations
void batchAdd(const vector<Complex>& numbers) {
    Complex sum;
    for (const Complex& c : numbers) {
        sum = sum + c;
    }
    cout << "\nSum of complex numbers in batch: " << sum << endl;
}

void batchSubtract(const vector<Complex>& numbers) {
    if (numbers.empty()) return;

    Complex result = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        result = result - numbers[i];
    }
    cout << "Subtraction result of complex numbers in batch: " << result << endl;
}

int main() {
    Complex c1, c2;

    // Input two complex numbers
    cout << "Input first complex number:\n";
    cin >> c1;

    cout << "Input second complex number:\n";
    cin >> c2;

    // Perform operations
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    // Display results
    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    // Batch operations
    vector<Complex> collection = {c1, c2, Complex(3.2, -1.1), Complex(-1.0, 2.5)};
    batchAdd(collection);
    batchSubtract(collection);

    return 0;
}

