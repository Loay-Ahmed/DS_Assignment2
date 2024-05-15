#include "iostream"
#include "Heap.h"

using namespace std;

int main() {
    Heap* heap = new Heap();

    // Heap nodes
    heap->insertNode("Loay", "catsexual and gay", 10000);
    heap->insertNode("Hegazy", "Octosexual", 0);
    heap->insertNode("Ibrahim", "rabbito sexaul",  99100);
    heap->insertNode("Omar", "religious", 991005);

    // Sorting
    heap->heapSort();

    // printing Heap
    heap->print();

    Item item1 = Item("AAA", "", 10);
    Item item2 = Item("BBB", "", 2000000);

    cout << "item1 > item2: " << (item2 < item1) << endl;
    cout << ("a" < "b") << endl;

    return 0;
}