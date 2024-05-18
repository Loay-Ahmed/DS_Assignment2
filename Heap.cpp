//#include "Heap.h"
//
//
//Heap::Heap() {
//    this->arr = deque<Item>();
//    this->size = 0;
//}
//
//
//void Heap::insertNode(const string &itemName, const string &category, int price) {
//    Item item = Item(itemName, category, price);
//
//    // Insert Item in the end of the array and then Heapify it
//    heapifyName(0, size - 1);
//    arr.push_back(item);
//    heapifyName(0, size - 1);
//    size++;
//}
//
//
//void Heap::deleteNode(const string &name) {
//    for (int i = 0; i < size; i++) {
//        if (arr[i].ItemName() == name) {
//            arr[i] = arr[size - 1];
//            arr.pop_back();
//        }
//    }
//    size = size - 1;
//}
//
//
//void Heap::heapSort(int n) {
//    if (n == 4 || n == 5) {
//        // Sort by name
//        heapifyName(0, size - 1);
//        for (int i = size - 1; i >= 0; i--) {
//            swap(arr[0], arr[i]);
//            heapifyName(0, i);
//        }
//    } else if (n == 6 || n == 7) {
//        // Sort by price
//        heapifyPrice(0, size - 1);
//        for (int i = size - 1; i >= 0; i--) {
//            swap(arr[0], arr[i]);
//            heapifyPrice(0, i);
//        }
//    }
//}
//
//
//void Heap::heapifyName(int i, int n) {
//    int largest = i;
//    int l = 2 * i + 1;
//    int r = 2 * i + 2;
//    if (l < n && arr[l] < arr[largest]) {
//        largest = l;
//    }
//    if (r < n && arr[r] < arr[largest]) {
//        largest = r;
//    }
//    if (largest != i) {
//        swap(arr[i], arr[largest]);
//        heapifyName(largest, n);
//    }
//}
//
//
//void Heap::heapifyPrice(int i, int n) {
//    int largest = i;
//    int l = 2 * i + 1;
//    int r = 2 * i + 2;
//    if (l < n && arr[l] > arr[largest]) {
//        largest = l;
//    }
//    if (r < n && arr[r] > arr[largest]) {
//        largest = r;
//    }
//    if (largest != i) {
//        swap(arr[i], arr[largest]);
//        heapifyPrice(largest, n);
//    }
//}
//
//
//void printRec(deque<Item> arr, int size, int i) {
//    if (i < size) {
//        printRec(arr, size, i + 1);
//        arr[i].print();
//    }
//}
//
//void Heap::print(int n) {
//    heapSort(n);
//    switch (n) {
//        case 4:
//        case 6:
//            for (Item item: arr) {
//                item.print();
//            }
//            break;
//        case 5:
//        case 7:
//            for (int i = (int) arr.size() - 1; i >= 0; i--) {
//                arr[i].print();
//            }
//            break;
//    }
//}
//
//
//Heap::Heap(deque<Item> &arr) {
//    this->arr = arr;
//    this->size = (int) arr.size();
//}
//
//Heap::Heap(Heap *heap) {
//    this->arr = heap->arr;
//    this->size = heap->size;
//}

#include "Heap.h"

Heap::Heap() {
    this->arr = deque<Item>();
    this->size = 0;
}

void Heap::insertNode(const string &itemName, const string &category, int price) {
    Item item = Item(itemName, category, price);

    // Insert Item at the end of the array and then Heapify it
    arr.push_back(item);
    size++;
    heapifyName(0, size - 1);
}

void Heap::deleteNode(const string &name) {
    for (int i = 0; i < size; i++) {
        if (arr[i].ItemName() == name) {
            arr[i] = arr[size - 1];
            arr.pop_back();
            size--;
            heapifyName(0, size - 1);
            break;
        }
    }
}

void Heap::heapSort(int n) {
    if (n == 4 || n == 5) {
        // Sort by name
        heapifyName(0, size - 1);
        for (int i = size - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapifyName(0, i);
        }
    } else if (n == 6 || n == 7) {
        // Sort by price
        heapifyPrice(0, size - 1);
        for (int i = size - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapifyPrice(0, i);
        }
    }
}

void Heap::heapifyName(int i, int n) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] < arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyName(largest, n);
    }
}

void Heap::heapifyPrice(int i, int n) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyPrice(largest, n);
    }
}

void Heap::print(int n) {
    heapSort(n);
    switch (n) {
        case 4:
        case 6:
            for (Item item: arr) {
                item.print();
            }
            break;
        case 5:
        case 7:
            for (int i = (int) arr.size() - 1; i >= 0; i--) {
                arr[i].print();
            }
            break;
    }
}

Heap::Heap(deque<Item> &arr) {
    this->arr = arr;
    this->size = (int) arr.size();
}

Heap::Heap(Heap *heap) {
    this->arr = heap->arr;
    this->size = heap->size;
}