
/*
* Title: Trees
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 2
* Description: Analyzes the relation between insertion and deletion of bst and height of tree
*/

#include "BinarySearchTree.h"

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void analyzeBST() {
    const int n = 10000;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 10);
    }
    BinarySearchTree bst;
    cout << "Random BST size vs. height (Insertion)" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        bst.add(arr[i]);
        if (!(i % 100) && i != 0) {
            cout << bst.getNumberOfNodes() << "  " << bst.getHeight() << endl;
        }
    }

    for (int i = 0; i < n/2; i++) {
        swap(arr[i], arr[n-i-1]);
    }

    cout << "Random BST size vs. height (Deletion)" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = n - 1; i > -1; i--) {
        bst.remove(arr[i]);
        if (!(i % 100) && i != 0) {
            cout << bst.getNumberOfNodes() << "  " << bst.getHeight() << endl;
        }
    }
    delete [] arr;
}

int main() {
    analyzeBST();
    return -1;
}