#ifndef DS_ASSIGNMENT2_BST_H
#define DS_ASSIGNMENT2_BST_H

#include "Item.h"
#include "Tree.h"

class BST : Tree {
private:
    struct Node {
        Item item;
        Node* left;
        Node* right;
    };
    Node* root;
public:
    BST();
    void inOrder(Node* node);
    void postOrder(Node* node);
    void insertNode(const string& itemName, const string& category, int price) override;
    void deleteNode(const string& name) ;
};


#endif //DS_ASSIGNMENT2_BST_H
