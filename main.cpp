#include "BST.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template<typename t>
void readFromFile(istream& input, t& tree) {
    string name, category;
    int price, size;
    input >> size;
    for (int i = 0; i < size; i++) {
        input.ignore();
        getline(input, name);
        getline(input, category);
        input >> price;
        name[0] = tolower(name[0]);
        tree.insertNode(name, category, price);
    }
}


int main()
{

    int choice;
    bool exitFlag = false;

    while (!exitFlag)
    {
        cout << "Menu:" << endl;
        cout << "1. Binary Search Trees (BST)" << endl;
        cout << "2. Heaps" << endl;
        cout << "3. AVL Trees" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            BST bst;
            int bstChoice;
            bool bstExitFlag = false;

            while (!bstExitFlag) {
                cout << "BST Menu:" << endl;
                cout << "1. Add item data" << endl;
                cout << "2. Remove item data" << endl;
                cout << "3. Display the item data normally" << endl;
                cout << "4. Display all items sorted by their name ascending" << endl;
                cout << "5. Display all items sorted by their name descending" << endl;
                cout << "6. Display all items sorted by their prices ascending" << endl;
                cout << "7. Display all items sorted by their prices descending" << endl;
                cout << "8. Go back to main menu" << endl;
                cout << "Enter your choice: ";
                cin >> bstChoice;

                switch (bstChoice)
                {
                case 1:
                {
                    cout << "you want to add manually or by file: \n1-manual\n2-by file ";
                    int inputChoice;
                    cin >> inputChoice;
                    if (inputChoice == 1) {
                        string name, category;
                        int price;
                        cout << "Enter item name: ";
                        cin >> name;
                        cout << "Enter item category: ";
                        cin >> category;
                        cout << "Enter item price: ";
                        cin >> price;
                        bst.insertNode(name, category, price);
                    }
                    else {
                        string filePath = "G:\\items.txt";
                        ifstream file(filePath);
                        if (!file.is_open()) {
                            cout << "Can't open the file\n";
                        }
                        else {
                            readFromFile(file, bst);
                        }
                    }
                    break;
                }
                case 2:
                {
                    string deleteItem;
                    cout << "input item name you want to delete: \n";
                    cin >> deleteItem;
                    bst.deleteNode(deleteItem);
                    break;
                }
                case 3:
                {
                    cout << "Items in BST:" << endl;
                    bst.printPreOrder(bst.getRoot());
                    break;
                }
                case 4: {
                    cout << "Items in BST sorted by name ascending: \n";
                    bst.printInOrder(bst.getRoot());
                    break;
                }
                case 5: {
                    cout << "Items in BST sorted by name descending: \n";
                    bst.printInOrderDES(bst.getRoot());
                    break;
                }
                case 6: {
                    BST bstPrice;
                    bstPrice.copy(bstPrice.getRoot(), bst.getRoot());
                    cout << "Items in BST sorted by price ascending: \n";
                    bstPrice.printInOrder(bstPrice.getRoot());
                    break;
                }
                case 7: {
                    BST bstPrice;
                    bstPrice.copy(bstPrice.getRoot(), bst.getRoot());
                    cout << "Items in BST sorted by price descending: \n";
                    bstPrice.printInOrderDES(bstPrice.getRoot());
                    break;
                }
                case 8: {
                    bstExitFlag = true;
                    break;
                }
                }
            }
        }
        case 2: {
            //the code of heaps with the same pattern as BST
        }
        case 3: {
            //the code of AVL with the same pattern as BST
        }
        case 4: {
            exitFlag = true;
        }
        }
    }
}
