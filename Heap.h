#ifndef DS_ASSIGNMENT2_HEAP_H
#define DS_ASSIGNMENT2_HEAP_H


#include "Item.h"
#include "Tree.h"

class Heap : Tree {
private:
    struct Node {
        Item item;
        Node* left;
        Node* right;
    };
    Node* root;
public:
    Heap();
    void insertNode(const string& itemName, const string& category, int price) const override;
    void deleteNode(const string& name) const override;
};


#endif //DS_ASSIGNMENT2_HEAP_H
