
/*
* Title: Trees
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 2
* Description: BST nodes
*/

#include "BinaryNode.h"

BinaryNode::BinaryNode(){}

BinaryNode::BinaryNode(const int &nodeItem, BinaryNode *left, BinaryNode *right, BinaryNode *aParent, int aSize) {
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
    parent = aParent;
    size = aSize;
}