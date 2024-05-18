#ifndef AVL_H
#define AVL_H

#include "Item.h"
#include <iostream>
#include <vector>

class AVL {
private:
    struct Node {
        Item item;
        Node* left;
        Node* right;
        int height;

        Node(const Item& item) : item(item), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int height(Node* node);
    int balanceFactor(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* balance(Node* node);
    Node* insert(Node* node, const Item& item);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* root, const string& itemName);
    void inOrder(Node* node, vector<Item>& items);
    void postOrder(Node* node, vector<Item>& items);

public:
    AVL();
    void insertNode(const string& itemName, const string& category, int price);
    void deleteNode(const string& itemName);
    void displayInOrder();
    void displayPostOrder();
    void displayItemsSortedByNameAscending();
    void displayItemsSortedByNameDescending();
    void displayItemsSortedByPriceAscending();
    void displayItemsSortedByPriceDescending();
};

#endif // AVL_H