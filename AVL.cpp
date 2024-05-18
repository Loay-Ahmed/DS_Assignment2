#include <algorithm>
#include "AVL.h"

AVL::AVL() {
    root = nullptr;
}

int AVL::height(Node *node) {
    return node ? node->height : 0;
}

int AVL::balanceFactor(Node *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVL::Node *AVL::rotateRight(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVL::Node *AVL::rotateLeft(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVL::Node *AVL::balance(Node *node) {
    int balance = balanceFactor(node);

    if (balance > 1 && balanceFactor(node->left) >= 0)
        return rotateRight(node);

    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && balanceFactor(node->right) <= 0)
        return rotateLeft(node);

    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

AVL::Node *AVL::insert(Node *node, const Item &item) {
    if (!node)
        return new Node(item);

    if (item < node->item)
        node->left = insert(node->left, item);
    else if (node->item < item)
        node->right = insert(node->right, item);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    return balance(node);
}

void AVL::insertNode(const string &itemName, const string &category, int price) {
    Item item(itemName, category, price);
    root = insert(root, item);
}

AVL::Node *AVL::minValueNode(Node *node) {
    Node *current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

AVL::Node *AVL::deleteNode(Node *root, const string &itemName) {
    if (!root)
        return root;

    if (itemName < root->item.ItemName())
        root->left = deleteNode(root->left, itemName);
    else if (root->item.ItemName() < itemName)
        root->right = deleteNode(root->right, itemName);
    else {
        if (!root->left || !root->right) {
            Node *temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node *temp = minValueNode(root->right);

            root->item = temp->item;

            root->right = deleteNode(root->right, temp->item.ItemName());
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    return balance(root);
}

void AVL::deleteNode(const string &itemName) {
    root = deleteNode(root, itemName);
}

void AVL::inOrder(Node *node, vector<Item> &items) {
    if (node) {
        inOrder(node->left, items);
        items.push_back(node->item);
        inOrder(node->right, items);
    }
}

void AVL::postOrder(Node *node, vector<Item> &items) {
    if (node) {
        postOrder(node->right, items);
        items.push_back(node->item);
        postOrder(node->left, items);
    }
}

void AVL::displayInOrder() {
    vector<Item> items;
    inOrder(root, items);
    for (auto &item: items) {
        item.print();
    }
}

void AVL::displayPostOrder() {
    vector<Item> items;
    postOrder(root, items);
    for (auto &item: items) {
        item.print();
    }
}

void AVL::displayItemsSortedByNameAscending() {
    vector<Item> items;
    inOrder(root, items);
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.ItemName() < b.ItemName();
    });
    for (auto &item: items) {
        item.print();
    }
}

void AVL::displayItemsSortedByNameDescending() {
    vector<Item> items;
    inOrder(root, items);
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.ItemName() > b.ItemName();
    });
    for (auto &item: items) {
        item.print();
    }
}

void AVL::displayItemsSortedByPriceAscending() {
    vector<Item> items;
    inOrder(root, items);
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.Price() < b.Price();
    });
    for (auto &item: items) {
        item.print();
    }
}

void AVL::displayItemsSortedByPriceDescending() {
    vector<Item> items;
    inOrder(root, items);
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.Price() > b.Price();
    });
    for (auto &item: items) {
        item.print();
    }
}