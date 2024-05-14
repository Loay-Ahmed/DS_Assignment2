#include "Heap.h"

#include <utility>
#include "queue"

Heap::Heap() {
    this->root = nullptr;
    this->size = 0;
}

void Heap::insertNode(const string &itemName, const string &category, int price) {
    if (root) {
        Item item = Item(itemName, category, price);
        auto *newNode = new Heap::Node(item);

        // create array to find parent
        deque<Node *> arr = readToArray();

        heapify(arr, 0, size - 1);
        arr.push_back(newNode);

        // find the parent index
        int childIndex = (int) arr.size() - 1;
        int parentIndex = (childIndex - 1) / 2;
        auto parent = arr[parentIndex];

        // Inserting newNode in the Tree
        if (parent->left == nullptr) {
            parent->left = newNode;
            this->size++;
        } else if (parent->right == nullptr) {
            parent->right = newNode;
            this->size++;
        }
    } else { root = new Node(Item(itemName, category, price)); }
}

void Heap::deleteNode(const string &name) const {

}

void Heap::heapSort() {
    cout << "In HeapSort" << endl;
    /// Get the array of items from the Heap Tree
    deque<Node *> arr = readToArray();

    /// Heap sort algorithm
    heapify(arr, 0, size);
    for (int i = 0, max = (size - 1); i < size; i++, max--) {
        swap(arr[0]->item, arr[max]->item);
        heapify(arr, 0, max + 1);
    }
    /// End of Heap sort

    // readToNode(arr);
}

void Heap::heapify(deque<Heap::Node *> &arr, int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if (l < n && !(arr[l]->item < arr[max]->item)) {
//        swap(arr[l]->item, arr[max]->item);
        Item temp = arr[l]->item;
        arr[l]->item = arr[max]->item;
        arr[max]->item = temp;
        max = l;
        heapify(arr, max, n);
    } else if (r < n && !(arr[r]->item < arr[max]->item)) {
//        swap(arr[r]->item, arr[max]->item);
        Item temp = arr[r]->item;
        arr[r]->item = arr[max]->item;
        arr[max]->item = temp;
        max = r;
        heapify(arr, max, n);
    }
}

deque<Heap::Node *> Heap::readToArray() {
    deque<Node *> arr;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *current = q.front();
        q.pop();

        arr.push_back(current);

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
    return arr;
}

void Heap::print() {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *current = q.front();
        q.pop();
        current->item.print();
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

Heap::Node::Node(Item item, Node *left, Node *right) {
    this->item = std::move(item);
    this->left = left;
    this->right = right;
}
