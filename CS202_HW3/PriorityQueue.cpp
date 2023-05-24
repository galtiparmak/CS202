/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Standart heap based priority queue implementation.
*/

#include "PriorityQueue.h"

bool PriorityQueue::pqIsEmpty() const {
    return h.heapisEmpty();
}

void PriorityQueue::pqInsert(const Request& newItem) {
    h.heapInsert(newItem);
}

void PriorityQueue::pqDelete(Request& priorityItem) {
    h.heapDelete(priorityItem);
}

Heap PriorityQueue::getHeap() {
    return h;
}