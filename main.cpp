#include "BST.h"
#include "Item.h"
#include "Heap.h"
#include "AVL.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template<typename t>
void readFromFile(istream &input, t &tree) {
    string name, category;
    int price, size;
    input >> size;
//    cout << size << endl;
    for (int i = 0; i < size; i++) {
        input.ignore();
        getline(input, name);
        getline(input, category);
        input >> price;
        name[0] = tolower(name[0]);
        tree.insertNode(name, category, price);
    }
}

void avlTreeMenu() {
    AVL avl;
    while (true) {
        cout << "\nAVL Tree Menu:\n";
        cout << "1. Add item\n";
        cout << "2. Remove item\n";
        cout << "3. Display items (in order)\n";
        cout << "4. Display items (post order)\n";
        cout << "5. Display items sorted by name ascending\n";
        cout << "6. Display items sorted by name descending\n";
        cout << "7. Display items sorted by price ascending\n";
        cout << "8. Display items sorted by price descending\n";
        cout << "9. Load items from file\n";
        cout << "10. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string itemname, category;
            int price;
            cout << "Enter item name: ";
            getline(cin, itemname);
            cout << "Enter category: ";
            getline(cin, category);
            cout << "Enter price: ";
            cin >> price;
            cin.ignore();
            avl.insertNode(itemname, category, price);
        } else if (choice == 2) {
            string itemname;
            cout << "Enter item name to remove: ";
            getline(cin, itemname);
            avl.deleteNode(itemname);
        } else if (choice == 3) {
            avl.displayInOrder();
        } else if (choice == 4) {
            avl.displayPostOrder();
        } else if (choice == 5) {
            avl.displayItemsSortedByNameAscending();
        } else if (choice == 6) {
            avl.displayItemsSortedByNameDescending();
        } else if (choice == 7) {
            avl.displayItemsSortedByPriceAscending();
        } else if (choice == 8) {
            avl.displayItemsSortedByPriceDescending();
        } else if (choice == 9) {
            cout << "Enter file path: ";
            string filePath;
            cin >> filePath;
            ifstream file(filePath);
            if (file.is_open()) {
                readFromFile(file, avl);
                file.close();
            } else {
                cout << "Unable to open file." << endl;
            }
        } else if (choice == 10) {
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }
}

int main() {

//    Heap *heap = new Heap();

//    heap->insertNode("Loayc", "Prog", 100);
//    heap->insertNode("Loayb", "Prog", 400);
//    heap->insertNode("Loaya", "Prog", 300);
//    ifstream file("D:\\Coding\\clion_files\\DS_Assignment2\\items.txt");
//    readFromFile(file, *heap);

//     4 -> name asc
//     5 -> name des
//     6 -> price asc
//     7 -> price des
//    heap->print(7);
//    cout << "----------------------" << endl;
//    heap->print(4);
//
//    Heap *heap = new Heap();
//    heap->insertNode("Loayc", "Prog", 100);
//    heap->insertNode("Loayb", "Prog", 400);
//    heap->insertNode("Loaya", "Prog", 300);
//    ifstream file("D:\\Coding\\clion_files\\DS_Assignment2\\items.txt");
//    readFromFile(file, *heap);

//     4 -> name asc
//     5 -> name des
//     6 -> price asc
//     7 -> price des
//    heap->print(7);
//    cout << "----------------------" << endl;
//    heap->print(4);

    int choice;
    bool exitFlag = false;

    while (!exitFlag) {
        cout << "Menu:" << endl;
        cout << "1. Binary Search Trees (BST)" << endl;
        cout << "2. AVL Trees" << endl;
        cout << "3. Heaps" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
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

                if (bstChoice == 1) {
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
                    } else {
                        cout << "Enter file path: ";
                        string filePath;
                        cin >> filePath;
                        ifstream file(filePath);
                        if (!file.is_open()) {
                            cout << "Can't open the file\n";
                        } else {
                            readFromFile(file, bst);
                        }
                    }
                }
                if (bstChoice == 2) {
                    string deleteItem;
                    cout << "input item name you want to delete: \n";
                    cin >> deleteItem;
                    bst.deleteNode(deleteItem);

                }
                if (bstChoice == 3) {
                    cout << "Items in BST:" << endl;
                    bst.printPreOrder(bst.getRoot());

                }
                if (bstChoice == 4) {
                    cout << "Items in BST sorted by name ascending: \n";
                    bst.printInOrder(bst.getRoot());

                }
                if (bstChoice == 5) {
                    cout << "Items in BST sorted by name descending: \n";
                    bst.printInOrderDES(bst.getRoot());
                    break;
                }
                if (bstChoice == 6) {
                    BST bstPrice;
                    bstPrice.copy(bstPrice.getRoot(), bst.getRoot());
                    cout << "Items in BST sorted by price ascending: \n";
                    bstPrice.printInOrder(bstPrice.getRoot());
                    break;
                }
                if (bstChoice == 7) {
                    BST bstPrice;
                    bstPrice.copy(bstPrice.getRoot(), bst.getRoot());
                    cout << "Items in BST sorted by price descending: \n";
                    bstPrice.printInOrderDES(bstPrice.getRoot());
                }
                if (bstChoice == 8) {
                    bstExitFlag = true;

                }
            }
        }
        if (choice == 2) {
            //the code of AVL with the same pattern as BST
            avlTreeMenu();
        }
        if (choice == 3) {
            //the code of heaps with the same pattern as BST
            Heap *heap = new Heap();
            int heapChoice;
            bool heapExitFlag = false;

            while (!heapExitFlag) {
                cout << "HEAP Menu:" << endl;
                cout << "1. Add item data" << endl;
                cout << "2. Remove item data" << endl;
                cout << "3. Display the item data normally" << endl;
                cout << "4. Display all items sorted by their name ascending" << endl;
                cout << "5. Display all items sorted by their name descending" << endl;
                cout << "6. Display all items sorted by their prices ascending" << endl;
                cout << "7. Display all items sorted by their prices descending" << endl;
                cout << "8. Go back to main menu" << endl;
                cout << "Enter your choice:" << " ";
                cin >> heapChoice;

                if (heapChoice == 1) {
                    cout << "you want to add manually or by file: \n1-manual\n2-by file\nChoice:";
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
                        heap->insertNode(name, category, price);
                    } else {
                        cout << "Enter file path: ";
                        string filePath;
                        cin >> filePath;
                        ifstream file(filePath);
                        if (!file.is_open()) {
                            cout << "Can't open the file\n";
                        } else {
                            readFromFile(file, *heap);
                        }
                    }
                }
                if (heapChoice == 2) {
                    string deleteItem;
                    cout << "Input item name you want to delete: \n";
                    cin >> deleteItem;
                    heap->deleteNode(deleteItem);
                }
                if (heapChoice == 3) {
                    cout << "Items in Heap:" << endl;
                    heap->print(5);
                }
                if (heapChoice == 4 && heapChoice == 5 && heapChoice == 6 && heapChoice == 7) {
                    cout << "Items in HEAP sorted by price descending: \n";
                    heap->print(heapChoice);
                }
                if (heapChoice == 8) {
                    heapExitFlag = true;
                }
            }
        }
        if (choice == 4) {
            exitFlag = true;
        }
    }
}