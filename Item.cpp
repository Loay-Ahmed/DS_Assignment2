#include "Item.h"

Item::Item(string itemName, string category, int price) {
    this->itemName = itemName;
    this->category = category;
    this->price = price;
}

bool Item::operator<(const Item &) {
    return false;
}

void Item::print() {
    cout << "Name: " << itemName << ", Category: " << category << ", Price: " << price << endl;
}
