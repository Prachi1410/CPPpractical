#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 50;

class Product {
public:
    int id, qty;
    float price;
    char name[20];

    Product() {}

    Product(int i, const char n[], int q, float p) {
        id = i;
        strcpy(name, n);
        qty = q;
        price = p;
    }

    void update(int q) {
        qty += q;
    }

    float value() {
        return qty * price;
    }

    void show() {
        cout << id << " " << name << " " << qty << " ₹" << price << endl;
    }
};

class Inventory {
    Product p[MAX];
    int count = 0;

public:
    void add(int id,  const char name[], int qty, float price) {
        if (count < MAX)
            p[count++] = Product(id, name, qty, price);
    }

    void updateQty(int id, int qty) {
        for (int i = 0; i < count; i++)
            if (p[i].id == id)
                p[i].update(qty);
    }

    void display() {
        for (int i = 0; i < count; i++)
            p[i].show();
    }

    float totalValue() {
        float sum = 0;
        for (int i = 0; i < count; i++)
            sum += p[i].value();
        return sum;
    }
};

int main() {
    Inventory inv;
    inv.add(1, "bottal", 68, 2.5);
    inv.add(2, "bol", 39, 1.2);
    inv.updateQty(2, 29);

    inv.display();
    cout << "Total Value: ₹" << inv.totalValue() << endl;

    return 0;
}
