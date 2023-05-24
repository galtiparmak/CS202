/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Standart heap implementation with request object as data values of heap.
*/

#ifndef HEAP
#define HEAP

#include "Request.h"
#include <iostream>
using namespace std;

class Heap {
    public:
        Heap();
        bool heapisEmpty() const;
        void heapInsert(const Request& newItem);
        void heapDelete(Request& rootItem);
        Request* getRequests();
        int getSize();

    protected:
        void heapRebulid(int root);

    private:
        Request* requestArr;
        int size;
};

#endif