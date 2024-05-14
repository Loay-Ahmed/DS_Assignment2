#ifndef DS_ASSIGNMENT2_HEAP_H
#define DS_ASSIGNMENT2_HEAP_H


#include <deque>
#include "Item.h"
#include "Tree.h"

class Heap : public Tree {
private:
    struct Node {
        Item item;
        Node* left;
        Node* right;
        explicit Node(Item item, Node* left = nullptr, Node* right = nullptr);
    };
    Node* root;
    int size;
public:
    Heap();
    void heapify(deque<Heap::Node*>& arr, int i, int n);
    void heapSort();
    deque<Heap::Node*> readToArray();
    void insertNode(const string& itemName, const string& category, int price) override;
    void deleteNode(const string& name) const override;
    void print();
};


#endif //DS_ASSIGNMENT2_HEAP_H
