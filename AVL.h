#ifndef DS_ASSIGNMENT2_AVL_H
#define DS_ASSIGNMENT2_AVL_H


#include "Item.h"
#include "Tree.h"

class AVL : Tree {
private:
    struct Node {
        Item item;
        Node* left;
        Node* right;
    };
    Node* root;
public:
    AVL();
    void inOrder(Node* node);
    void postOrder(Node* node);
    void balanceTree();
    void insertNode(const string& itemName, const string& category, int price) override;
    void deleteNode(const string& name) const override;
};


#endif //DS_ASSIGNMENT2_AVL_H
