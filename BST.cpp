#include "BST.h"

using namespace std;
BST::BST() {
    root = nullptr;
}

BST::Node*& BST::getRoot() {
    return root;
}

void BST::insertNode(const string& itemName, const string& category, int price) {
    const Item temp(itemName, category, price);
    insert(root, temp);

}

void BST::insert(Node*& node, const Item& i) {
    if (node == nullptr) {
        node = new Node;
        node->item = i;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (i < (node->item)) {
        insert(node->left, i);
    }
    else {
        insert(node->right, i);
    }
}



void BST::printInOrder(Node* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        node->item.print();
        printInOrder(node->right);
    }

}

void BST::deleteNode(string itm) {
    if (root == nullptr) {
        return;
    }
    else if (itm == root->item.ItemName()) {
        delet(nullptr, root);
    }
    else if (itm < root->item.ItemName()) {

        deletC(root, root->left, itm);
    }
    else {
        deletC(root, root->right, itm);
    }
}

void BST::deletC(Node* prev, Node* node, string itm) {
    if (node == nullptr) {
        return;
    }
    else if (itm == node->item.ItemName()) {

        delet(prev, node);
    }
    else if (itm < node->item.ItemName()) {
        prev = node;
        deletC(prev, node->left, itm);
    }
    else {
        prev = node;
        deletC(prev, node->right, itm);
    }
}

void BST::delet(Node* prev, Node* node) {
    if (node == nullptr) {
        return;
    }
    else if (node->right == nullptr && node->left == nullptr) {
        if (prev->right == node) {
            prev->right = nullptr;
            delete node;
        }
        else {
            prev->left = nullptr;
            delete node;
        }
    }
    else if (node->left == nullptr) {
        if (prev->right == node) {
            prev->right = node->right;
            delete node;
        }
        else {
            prev->left = node->right;
            delete node;
        }
    }
    else if (node->right == nullptr) {
        if (prev->right == node) {
            prev->right = node->left;
            delete node;
        }
        else {
            prev->left = node->left;
            delete node;
        }
    }
    else {
        node->item = findMin(node->right);
    }
}

Item BST::findMin(Node* node) {
    if (node->left == nullptr) {
        Item temp = node->item;
        deleteNode(node->item.ItemName());
        return temp;
    }
    else {
        return findMin(node->left);
    }
}

void BST::printInOrderDES(Node* node) {
    if (node != nullptr) {
        printInOrderDES(node->right);
        node->item.print();
        printInOrderDES(node->left);
    }
}

void BST::insertByPrice(Node*& node, const Item& i) {
    if (node == nullptr) {
        node = new Node;
        node->item = i;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (i > (node->item)) {
        insertByPrice(node->right, i);
    }
    else {
        insertByPrice(node->left, i);
    }
}

void BST::printPreOrder(Node* node) {
    if (node != nullptr) {
        node->item.print();
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void BST::copy(Node*& root, Node* node) {
    if (node != nullptr) {
        const Item& temp = node->item;
        insertByPrice(root, temp);
        copy(root, node->left);
        copy(root, node->right);
    }
}
