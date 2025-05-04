#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addItem() {
    string name;
    int qty;
    double price;

    cout << "Item name: "; cin.ignore(); getline(cin, name);
    cout << "Quantity: "; cin >> qty;
    cout << "Price: "; cin >> price;

    ofstream file("inventory.txt", ios::app);
    file << name << "," << qty << "," << price << "\n";
    file.close();
    cout << "Item added.\n";
}

void viewItems() {
    ifstream file("inventory.txt");
    string line;
    cout << "\n--- Inventory ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void searchItem() {
    ifstream file("inventory.txt");
    string line, name, search;
    cout << "Search item name: "; cin.ignore(); getline(cin, search);

    bool found = false;
    while (getline(file, line)) {
        size_t pos = line.find(',');
        name = line.substr(0, pos);
        if (name == search) {
            cout << "Found: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Item not found.\n";
    file.close();
}

int main() {
    int ch;
    do {
        cout << "\n1.Add 2.View 3.Search 4.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) addItem();
        else if (ch == 2) viewItems();
        else if (ch == 3) searchItem();
    } while (ch != 4);
    return 0;
}

