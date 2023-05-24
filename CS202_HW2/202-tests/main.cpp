#include "BinarySearchTree.h"

int main() {
    BinarySearchTree bst;
    bst.add(5);
    bst.add(15);
    bst.add(2);
    bst.add(1);
    bst.add(11);
    bst.add(17);
    bst.add(4);
    bst.inorderTraverse();
    cout << endl;
    return -1;
}