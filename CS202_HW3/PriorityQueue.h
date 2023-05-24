/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Standart heap based priority queue implementation.
*/

#ifndef PQ
#define PQ

#include "Heap.h"

class PriorityQueue {
    public:
        bool pqIsEmpty() const;
        void pqInsert(const Request& newItem);
        void pqDelete(Request& priorityItem);
        Heap getHeap();
    private:
        Heap h;
};

#endif