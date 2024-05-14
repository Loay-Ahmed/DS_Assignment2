#include "BST.h"

BST::BST() {
    this->root = nullptr;
}

void BST::postOrder(Node *node) {
    if (node != nullptr) {
        postOrder(node->right);
        node->item.print();
        postOrder(node->left);
    }
}

void BST::inOrder(Node *node) {
    if (node != nullptr) {
        inOrder(node->left);
        node->item.print();
        inOrder(node->right);
    }
}

void BST::insertNode(const string& itemName, const string& category, int price) {

}

void BST::deleteNode(const string& name) {

}
