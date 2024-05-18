#include "Heap.h"


Heap::Heap() {
    this->arr = deque<Item>();
    this->size = 0;
}


void Heap::insertNode(const string &itemName, const string &category, int price) {
    Item item = Item(itemName, category, price);

    // Insert Item in the end of the array and then Heapify it
    heapifyName(0, size - 1);
    arr.push_back(item);
    heapifyName(0, size - 1);
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


void Heap::heapSort(int n) {
    // Heap sort algorithm
    switch (n) {
        case 4:
        case 5: {
            heapifyName(0, size - 1);
            for (int i = 0, max = (size - 1); i < size; i++, max--) {
                swap(arr[0], arr[max]);
                heapifyName(0, max);
            }
            break;
        }
        case 6:
        case 7: {
            heapifyPrice(0, size);
            for (int i = 0, max = (size - 1); i < size; i++, max--) {
                swap(arr[0], arr[max]);
                heapifyPrice(0, max);
            }
            break;
        }
    }
}

void Heap::heapifyName(int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if (l < n && arr[max] < arr[l]) {
        swap(arr[l], arr[max]);
        max = l;
        heapifyName(max, n);
    } else if (r < n && arr[max] < arr[r]) { // Loay < Omar
        swap(arr[r], arr[max]);
        max = r;
        heapifyName(max, n);
    }
}

void Heap::heapifyPrice(int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if (l < n && arr[l] > arr[max]) {
        swap(arr[l], arr[max]);
        max = l;
        heapifyPrice(max, n);
    } else if (r < n && arr[r] > arr[max]) {
        swap(arr[r], arr[max]);
        max = r;
        heapifyPrice(max, n);
    }
}

void printRec(deque<Item> arr, int size, int i) {
    if (i < size) {
        printRec(arr, size, i + 1);
        arr[i].print();
    }
}

void Heap::print(int n) {
    heapSort(n);
    switch (n) {
        case 4:
        case 6: {
            for (Item item: arr) {
                item.print();
            }
            break;
        }
        case 5:
        case 7: {
            for (int i = (int) arr.size() - 1; i >= 0; i--) {
                arr[i].print();
            }
            break;
        }
    }
}


Heap::Heap(deque<Item> &arr) {
    this->arr = arr;
    this->size = (int) arr.size();
}
