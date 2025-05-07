#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base constructor called" << endl;
    }

    // Virtual destructor to ensure proper cleanup
    virtual ~Base()
    {
        cout << "Base destructor called" << endl;
    }

    virtual void show()
    {
        cout << "Base show function" << endl;
    }
};

class Derived : public Base
{
    int* data;

public:
    Derived()
    {
        data = new int[5];  // Dynamic allocation
        cout << "Derived constructor called (memory allocated)" << endl;
    }

    ~Derived()
    {
        delete[] data;  // Clean up memory
        cout << "Derived destructor called (memory freed)" << endl;
    }

    void show() override
    {
        cout << "Derived show function" << endl;
    }
};

int main()
{
    Base* ptr = new Derived();  // Base class pointer to derived class object

    ptr->show();  // Calls Derived::show() due to virtual function

    delete ptr;   // Ensures Derived destructor is called because base has virtual destructor

    return 0;
}
