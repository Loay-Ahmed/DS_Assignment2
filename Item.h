#ifndef DS_ASSIGNMENT2_ITEM_H
#define DS_ASSIGNMENT2_ITEM_H

#include "iostream"

using namespace std;

class Item {
    string itemName;
    string category;
    int price;
public:
    Item(string itemName, string category, int price);

    bool operator<(const Item &);

    void print();
};


#endif //DS_ASSIGNMENT2_ITEM_H
