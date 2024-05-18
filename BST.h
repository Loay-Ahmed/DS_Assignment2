#ifndef DS_ASSIGNMENT2_BST_H
#define DS_ASSIGNMENT2_BST_H

#include"Item.h"
#include<string>


class BST
{
private:
	struct Node {
		Item item;
		Node* left;
		Node* right;
	};
	Node* root;


	void deletC(Node* prev, Node* node, string itm);

public:
	Node*& getRoot();
	BST();
	void deleteNode(string DI);
	void delet(Node* prev, Node* node);
	Item findMin(Node* node);
	void printInOrder(Node* nude);
	void printInOrderDES(Node* node);
	void insertNode(const string& itemName, const string& category, int price);
	void insert(Node*& node, const Item& itm);
	void insertByPrice(Node*& node, const Item& itm);
	void printPreOrder(Node* node);
	void copy(Node*& root, Node* node);
};

#endif //DS_ASSIGNMENT2_BST_H
