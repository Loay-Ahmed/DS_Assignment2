#include "Item.h"

Item::Item(string itemName, string category, int price) {
    this->itemName = std::move(itemName);
    this->category = std::move(category);
    this->price = price;
}

bool Item::operator<(const Item& item) const {
    return (this->itemName < item.itemName);
}

bool Item::operator>(const Item& item) const {
    return (this->price > item.price);
}

bool Item::operator==(const Item& item) const {
    return (this->itemName == item.itemName);
}

void Item::print() {
    cout << "Name: " << itemName << ", Category: " << category << ", Price: " << price << endl;
}

Item::Item() {
    this->itemName = "";
    this->category = "";
    this->price = 0;
}
