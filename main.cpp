#include "iostream"
#include "Heap.h"

using namespace std;

int main() {
    Heap* heap = new Heap();

    // Heap nodes
    heap->insertNode("Loay", "catsexual and gay", 10000);
    heap->insertNode("Hegazy", "Octosexual", 0);
    heap->insertNode("Ibrahim", "rabbito sexaul",  991000);
    heap->insertNode("Omar", "religious", 999999999);

    // Sorting
    heap->heapSort();

    // printing Heap
    heap->print();
    return 0;
}