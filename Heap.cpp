#include "Heap.h"


Heap::Heap() {
    this->arr = deque<Item>();
    this->size = 0;
}


void Heap::insertNode(const string &itemName, const string &category, int price) {
    Item item = Item(itemName, category, price);

    // Insert Item in the end of the array and then Heapify it
    heapify(0, size - 1);
    arr.push_back(item);
    heapify(0, size - 1);
    size++;
}


void Heap::deleteNode(const string &name) {
    for (int i = 0; i < size; i++) {
        if (arr[i].ItemName() == name) {
            arr[i] = arr[size - 1];
            arr.pop_back();
        }
    }
    size = size - 1;
}


void Heap::heapSort() {
    cout << "In HeapSort" << endl;
    /// Get the array of items from the Heap Tree


    /// Heap sort algorithm
    heapify(0, size);
    for (int i = 0, max = (size - 1); i < size; i++, max--) {
        swap(arr[0], arr[max]);
        heapify(0, max);
    }
    /// End of Heap sort

}


void Heap::heapify(int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if (l < n && arr[l].Price() > arr[max].Price()) {
        swap(arr[l], arr[max]);
//        Item temp = arr[l];
//        arr[l] = arr[max];
//        arr[max] = temp;
        max = l;
        heapify(max, n);
    } else if (r < n && arr[r].Price() > arr[max].Price()) {
        swap(arr[r], arr[max]);
//        Item temp = arr[r];
//        arr[r] = arr[max];
//        arr[max] = temp;
        max = r;
        heapify(max, n);
    }
}


void Heap::print() {
    for (Item item: arr) {
        item.print();
    }
}


Heap::Heap(deque<Item> &arr) {
    this->arr = arr;
    this->size = (int) arr.size();
}
