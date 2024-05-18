#ifndef DS_ASSIGNMENT2_HEAP_H
#define DS_ASSIGNMENT2_HEAP_H


#include <deque>
#include "Item.h"

class Heap {
private:
    deque<Item> arr;
    int size;
public:
    Heap();

    explicit Heap(deque<Item> &arr);
    Heap(Heap* heap);

    void heapifyName(int i, int n);
    void heapifyPrice(int i, int n);

    void heapSort(int n);

    void insertNode(const string &itemName, const string &category, int price);

    void deleteNode(const string &name);

    void print(int n);
};


#endif //DS_ASSIGNMENT2_HEAP_H
