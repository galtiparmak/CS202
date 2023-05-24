/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Standart heap implementation with request object as data values of heap.
*/

#include "Heap.h"

Heap::Heap() {
    size = 0;
    requestArr = new Request[100];
}

bool Heap::heapisEmpty() const {
    return size == 0;
}

void Heap::heapInsert(const Request& newItem) {
    if (size >= 100) {
        cout << "size problem" << endl;
    }
    requestArr[size] = newItem;
    int place = size;
    int parent = (place-1) / 2;
    while ((place > 0) && (requestArr[place].getPriority() > requestArr[parent].getPriority())) {
        Request temp = requestArr[place];
        requestArr[place] = requestArr[parent];
        requestArr[parent] = temp;
        place = parent;
        parent = (place-1) / 2;
    }
    size++;
}

void Heap::heapDelete(Request& rootItem) {
    if (heapisEmpty()) {
        cout << "Heap is empty" << endl;
    }
    else {
        rootItem = requestArr[0];
        Request* delPtr = &requestArr[0];
        requestArr[0] = requestArr[size];
        size--;
        delPtr = NULL;
        delete delPtr;
        heapRebulid(0);
    }
}

void Heap::heapRebulid(int root){
    int child = 2 * root + 1;
    if (child < size) {
        int rightChild = child + 1;
        if ((rightChild < size) && (requestArr[rightChild].getPriority() > requestArr[child].getPriority())) {
            child = rightChild;
        }
        if (requestArr[root].getPriority() < requestArr[child].getPriority()) {
            Request temp = requestArr[root];
            requestArr[root] = requestArr[child];
            requestArr[child] = temp;
            heapRebulid(child);
        }
    }       
}

Request* Heap::getRequests() {
    return requestArr;
}

int Heap::getSize() {
    return size;
}