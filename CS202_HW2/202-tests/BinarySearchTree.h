
/*
* Title: Trees
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 2
* Description: Header file of BST class
*/

#include <iostream>
#include <string>
#include "BinaryNode.h"
using namespace std;

#ifndef GEKO2001_H
#define GEKO2001_H

class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& tree);
    void copyTree(BinaryNode* treePtr, BinaryNode*& newPtr) const;
    ~BinarySearchTree();
    void destroyTree(BinaryNode*& treePtr);
    bool isEmpty();
    int getHeight();
    int getHeight(BinaryNode*& root);
    int getNumberOfNodes();
    int getNumberOfNodes(BinaryNode*& root);
    bool add(int newEntry);
    bool add(BinaryNode*& treePtr, int newEntry);
    bool remove(int anEntry);
    bool deleteItem(BinaryNode*& treePtr, int anEntry);
    void deleteNodeItem(BinaryNode*& nodePtr);
    void processLeftMost(BinaryNode*& nodePtr, int& item);
    bool contains(int anEntry);
    bool contains(BinaryNode* treePtr, int anEntry);
    void inorderTraverse();
    void inorderTraverse(BinaryNode* nodePtr);
    int getWidth();
    int getWidth(BinaryNode* nodePtr);
    int getWidth(BinaryNode* nodePtr, const int lvl);
    int count(BinaryNode*& nodePtr, int a, int b);
    int count(int a, int b);
    void select(BinaryNode* nodePtr, int anEntry, int& index);
    int select(int anEntry);
    BinaryNode* getMostLeft(BinaryNode*& nodePtr);
    void successor(BinaryNode* nodePtr, BinaryNode*& targetPtr, int anEntry);
    int successor(int anEntry);
private:
    BinaryNode* root;
};

#endif // GEKO2001_H