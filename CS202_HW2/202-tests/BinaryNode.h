
/*
* Title: Trees
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 2
* Description: Header file of BinaryNode class
*/

#include <iostream>
#include <string>
using namespace std;

#ifndef DESTROYER_H
#define DESTROYER_H


class BinaryNode{
private:
    int item;
    BinaryNode *leftChildPtr;
    BinaryNode *rightChildPtr;
    BinaryNode *parent;
    int size;
    BinaryNode();
    BinaryNode(const int &nodeItem, BinaryNode *left = NULL, BinaryNode *right = NULL, BinaryNode *parent = NULL, int size = 0);
    
    friend class BinarySearchTree;
};


#endif // DESTROYER_H