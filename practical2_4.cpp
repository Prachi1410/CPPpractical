#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    int id;
    string name;
    float price;
    int quantity;

    void addItem(int i, string n, float p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    void restock(int q) {
        quantity += q;
    }

    void sell(int q) {
        if (q > quantity)
            cout << "Not enough stock"<<endl;
        else
            quantity -= q;
    }

    void show() {
        cout << "ID: " << id << endl;
       cout<< "Name: " << name<<endl;
          cout   << "Price: " << price <<endl;
          cout<< "Stock: " << quantity << endl;
    }
};

int main() {
    Item item;
    item.addItem(1, "bottal", 10.5, 100);
    item.restock(50);
    item.sell(30);
    item.show();
    return 0;
    }
