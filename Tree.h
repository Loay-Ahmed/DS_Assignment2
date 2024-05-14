#ifndef DS_ASSIGNMENT2_TREE_H
#define DS_ASSIGNMENT2_TREE_H

#include "iostream"

using namespace std;

class Tree {
    virtual void insertNode(const string& itemName, const string& category, int price) const = 0;
    virtual void deleteNode(const string& name) const = 0;
};

#endif //DS_ASSIGNMENT2_TREE_H
