#include "AVL.h"

AVL::AVL() {
    this->root = nullptr;
}

void AVL::inOrder(AVL::Node *node) {
    if(node != nullptr) {
        inOrder(node->left);
        node->item.print();
        inOrder(node->right);
    }
}

void AVL::postOrder(AVL::Node *node) {
    if(node != nullptr) {
        postOrder(node->right);
        node->item.print();
        postOrder(node->left);
    }
}

void AVL::balanceTree() {

}

void AVL::insertNode(const string &itemName, const string &category, int price) const {

}

void AVL::deleteNode(const string &name) const {

}
