#ifndef DS_ASSIGNMENT2_HEAP_H
#define DS_ASSIGNMENT2_HEAP_H


#include <deque>
#include "Item.h"
#include "Tree.h"

class Heap : public Tree {
private:
    deque<Item> arr;
    int size;
public:
    Heap();

    explicit Heap(deque<Item> &arr);

    void heapify(int i, int n);

    void heapSort();

    void insertNode(const string &itemName, const string &category, int price) override;

    void deleteNode(const string &name);

    void print();
};


#endif //DS_ASSIGNMENT2_HEAP_H
