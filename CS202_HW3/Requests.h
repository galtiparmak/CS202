/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Reads file, takes requests and compute the minimum required computer number.
*/

#ifndef REQUESTS_H
#define REQUESTS_H

#include "PriorityQueue.h"
#include "Request.h"
#include "Computer.h"
#include <fstream>
#include <string>

class Requests{
    public:
    Requests();
    string calculate(ifstream& inFile, string fileName, double avgTime);
    void readFile(ifstream& inFile, string fileName);
    private:
    PriorityQueue pq;
    Request* requests;
    int PQsize;
    int computerSize;
    Computer* computerArr;
};

#endif