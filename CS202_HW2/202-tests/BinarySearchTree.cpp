
/*
* Title: Trees
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 2
* Description: Binary Search Tree with functions
* Note: My select function is not working
*/

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree) {
    copyTree(tree.root, root);
}

void BinarySearchTree::copyTree(BinaryNode* treePtr, BinaryNode*& newTreePtr) const {
    if (treePtr != NULL) {
        newTreePtr = new BinaryNode(treePtr->item);
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    }
    else {
        newTreePtr = NULL;
    }
}

BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

void BinarySearchTree::destroyTree(BinaryNode*& treePtr) {
    if(treePtr != NULL) {
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}

bool BinarySearchTree::isEmpty() {
    return root == NULL;
}

int BinarySearchTree::getHeight(BinaryNode*& root) {
    if (root == NULL) {
        return 0;
    }
    else {
        return 1 + max(getHeight(root->leftChildPtr), getHeight(root->rightChildPtr));
    }
}

int BinarySearchTree::getHeight() {
    return getHeight(root);
}

int BinarySearchTree::getNumberOfNodes(BinaryNode*& root) {
    if (root == NULL) {
        return 0;
    }
    else {
        return 1 + getNumberOfNodes(root->leftChildPtr) + getNumberOfNodes(root->rightChildPtr);
    }
}

int BinarySearchTree::getNumberOfNodes() {
    return getNumberOfNodes(root);
}

bool BinarySearchTree::add(BinaryNode*& treePtr, int newEntry) {
    if (newEntry > 0) {
        if (treePtr == NULL) {
            treePtr = new BinaryNode(newEntry);
            return true;
        }
        else {
            if (newEntry == treePtr->item) {
                return false;
            }
            if (newEntry < treePtr->item) {
                treePtr->size++;
                return add(treePtr->leftChildPtr, newEntry);
            }
            else {
                treePtr->size++;
                return add(treePtr->rightChildPtr, newEntry);
            }
        }
    }
    else {
        return false;
    }
}

bool BinarySearchTree::add(int newEntry) {
    return add(root, newEntry);
}

void BinarySearchTree::processLeftMost(BinaryNode*& nodePtr, int& item) {
    if (nodePtr->leftChildPtr == NULL) {
        item = nodePtr->item;
        BinaryNode* delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    else {
        processLeftMost(nodePtr->leftChildPtr, item);
    }
}

void BinarySearchTree::deleteNodeItem(BinaryNode*& nodePtr) {
    BinaryNode* delPtr;
    int replacementItem;

    if (nodePtr->rightChildPtr == NULL && nodePtr->leftChildPtr == NULL) {
        nodePtr = NULL;
        delete nodePtr;
    }
    else if (nodePtr->leftChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    else if (nodePtr->rightChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }
    else {
        processLeftMost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}

bool BinarySearchTree::deleteItem(BinaryNode*& treePtr, int anEntry) {
    if (treePtr == NULL) {
        return false;
    }
    else if (treePtr->item == anEntry) {
        deleteNodeItem(treePtr);
        return true;
    }
    else if(treePtr->item < anEntry) {
        treePtr->size--;
        return deleteItem(treePtr->rightChildPtr, anEntry);
    }
    else {
        treePtr->size--;
        return deleteItem(treePtr->leftChildPtr, anEntry);
    }
}

bool BinarySearchTree::remove(int anEntry) {
    return deleteItem(root, anEntry);
}

bool BinarySearchTree::contains(BinaryNode* treePtr, int anEntry) {
    if (treePtr == NULL) {
        return false;
    }
    else if (treePtr->item == anEntry) {
        return true;
    }
    else if (treePtr->item < anEntry) {
        return contains(treePtr->rightChildPtr, anEntry);
    }
    else {
        return contains(treePtr->leftChildPtr, anEntry);
    }
}

bool BinarySearchTree::contains(int anEntry) {
    if (root == NULL) {
        return false;
    }
    else {
        return contains(root, anEntry);
    }
}

void BinarySearchTree::inorderTraverse(BinaryNode* nodePtr) {
    if (nodePtr != NULL) {
        inorderTraverse(nodePtr->leftChildPtr);
        cout << nodePtr->item << " ";
        inorderTraverse(nodePtr->rightChildPtr);
    }
}

void BinarySearchTree::inorderTraverse() {
    inorderTraverse(root);
}

int BinarySearchTree::getWidth(BinaryNode* nodePtr, const int lvl) {
    if (lvl > -1) {
        if (nodePtr == NULL) {
            return 0;
        }
        if (lvl == 1) {
            return 1;
        }
        else if (lvl > 1) {
            return getWidth(nodePtr->rightChildPtr, lvl - 1) + getWidth(nodePtr->leftChildPtr, lvl - 1);
        }
    }
    else {
        return -1;
    }
}

int BinarySearchTree::getWidth(BinaryNode* nodePtr) {
    int max = 0;
    int width;
    int height = getHeight(nodePtr);

    for (int i = 1; i <= height; i++) {
        width = getWidth(nodePtr, i);
        if (width > max) {
            max = width;
        }
    }
    return max;
}

int BinarySearchTree::getWidth() {
    if (root == NULL) {
        return 0;
    }
    else {
        return getWidth(root);
    }
}

int BinarySearchTree::count(BinaryNode*& nodePtr, int a, int b) {
    if (nodePtr == NULL) {
        return 0;
    }
    else if (nodePtr->item == a && nodePtr->item == b) {
        return 1;
    }
    else if (nodePtr->item >= a && nodePtr->item <= b) {
        return 1 + count(nodePtr->leftChildPtr, a, b) + count(nodePtr->rightChildPtr, a ,b);
    }
    else if (nodePtr->item > a) {
        return count(nodePtr->leftChildPtr, a, b);
    }
    else {
        return count(nodePtr->rightChildPtr, a, b);
    }
}

int BinarySearchTree::count(int a, int b) {
    if (root == NULL) {
        return 0;
    }
    else {
        return count(root, a, b);
    }
}

//PROBLEM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void BinarySearchTree::select(BinaryNode* nodePtr, int anEntry, int& index) {
    static int a = 0;
    if (nodePtr->item == anEntry) {
        a = 1;
        return;
    }
    if (nodePtr != NULL) {
        select(nodePtr->leftChildPtr, anEntry, index);
        if (!a) {
            index++;
        }
        select(nodePtr->rightChildPtr, anEntry, index);
    }
}

int BinarySearchTree::select(int anEntry) {
    if (root == NULL) {
        return -1;
    }
    else if(!contains(anEntry)) {
        return -1;
    }
    else {
        int index = 0;
        select(root, anEntry, index);
        return index;
    }
}

BinaryNode* BinarySearchTree::getMostLeft(BinaryNode*& nodePtr) {
    while (nodePtr->leftChildPtr) {
        nodePtr = nodePtr->leftChildPtr;
    }
    return nodePtr;
}

void BinarySearchTree::successor(BinaryNode* nodePtr, BinaryNode*& targetPtr, int anEntry) {
    if (nodePtr == NULL) {
        return;
    }
    if (nodePtr->item == anEntry) {
        if (nodePtr->rightChildPtr != NULL) {
            targetPtr = getMostLeft(nodePtr->rightChildPtr);
        }
    }
    else if (nodePtr->item > anEntry) {
        targetPtr = nodePtr;
        successor(nodePtr->leftChildPtr, targetPtr, anEntry);
    }
    else {
        successor(nodePtr->rightChildPtr, targetPtr, anEntry);
    }
}

int BinarySearchTree::successor(int anEntry) {
    if (!contains(anEntry)) {
        return -1;
    }
    BinaryNode* targetPtr = NULL;
    successor(root, targetPtr, anEntry);
    if (targetPtr == NULL) {
        return -2;
    }
    return targetPtr->item;
}
