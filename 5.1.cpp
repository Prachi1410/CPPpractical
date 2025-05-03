#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Calculator {
private:
    vector<string> results;

public:
    // Overloaded add methods
    int add(int a, int b) {
        int result = a + b;
        storeResult("int + int", a, b, result);
        return result;
    }

    float add(float a, float b) {
        float result = a + b;
        storeResult("float + float", a, b, result);
        return result;
    }

    double add(double a, double b) {
        double result = a + b;
        storeResult("double + double", a, b, result);
        return result;
    }

    double add(int a, double b) {
        double result = a + b;
        storeResult("int + double", a, b, result);
        return result;
    }

    double add(double a, int b) {
        double result = a + b;
        storeResult("double + int", a, b, result);
        return result;
    }

    float add(int a, float b) {
        float result = a + b;
        storeResult("int + float", a, b, result);
        return result;
    }

    float add(float a, int b) {
        float result = a + b;
        storeResult("float + int", a, b, result);
        return result;
    }

    // Display all stored results
    void displayResults() {
        cout << "\nCalculation Results:\n";
        for (const string& res : results) {
            cout << res << endl;
        }
    }

private:
    // Helper method to store result as a string
    template <typename T1, typename T2, typename T3>
    void storeResult(const string& operation, T1 a, T2 b, T3 result) {
        results.push_back(operation + ": " + to_string(a) + " + " + to_string(b) + " = " + to_string(result));
    }
};

// Test the functionality
int main() {
    Calculator calc;

    calc.add(5, 3);             // int + int
    calc.add(2.5f, 3.1f);       // float + float
    calc.add(4.2, 3.8);         // double + double
    calc.add(7, 2.5);           // int + double
    calc.add(3.6, 4);           // double + int
    calc.add(2, 3.3f);          // int + float
    calc.add(4.4f, 6);          // float + int

    calc.displayResults();

    return 0;
}

