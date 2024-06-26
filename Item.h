#ifndef DS_ASSIGNMENT2_ITEM_H
#define DS_ASSIGNMENT2_ITEM_H

#include "iostream"

using namespace std;
class Item
{
    string itemName;
    string category;
    int price;
public:
    Item();
    string ItemName() const { return this->itemName; };
    string Category() { return this->category; };
    int Price() const { return this->price; };
    Item(string itemName, string category, int price);
    bool operator>(const Item& item) const;
    bool operator<(const Item& item) const;
    bool operator==(const Item& item) const;
    void print();
};


#endif //DS_ASSIGNMENT2_ITEM_H
