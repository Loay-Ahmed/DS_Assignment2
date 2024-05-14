#ifndef DS_ASSIGNMENT2_HEAP_H
#define DS_ASSIGNMENT2_HEAP_H


#include "Item.h"

class Heap {
private:
    struct Node {
        Item item;
        Node* left;
        Node* right;
    };
    Node* root;
public:
    Heap();
    void insertNode(const string& itemName, const string& category, int price);
    void deleteNode(const string& name);
};


#endif //DS_ASSIGNMENT2_HEAP_H
