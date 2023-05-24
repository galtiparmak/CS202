/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Reads file, takes requests and compute the minimum required computer number.
*/

#include "Requests.h"

Requests::Requests() {
    PQsize = 0;
    computerSize = 1;
    requests = NULL;
}
void Requests::readFile(ifstream& inFile, string fileName) {
    inFile.open(fileName);
    if (!inFile) {
        cout << "unable to open file" << endl;
    }
    int max;
    int id, priority, reqTime, processed;
    inFile >> max;
    PQsize = max;
    int in = 0;
    requests = new Request[PQsize];
    while (!inFile.eof()) {
        inFile >> id >> priority >> reqTime >> processed;
        Request* req = new Request(id, priority, reqTime, processed, 0, 0, 0);
        requests[in] = *req;
        in++;
    }
}

string Requests::calculate(ifstream& inFile, string fileName, double avgTime) {
    string str = "";
    str += "Minimum number of computers required: " + to_string(computerSize) + "\n";
    str += "Simulation with " + to_string(computerSize) + " computers\n"; 
    static int a = 1;
    if (a == 1) {
        readFile(inFile, fileName);
        a++;
    }
    computerArr = new Computer[computerSize];
    int sum = 0;
    double avg;
    int size = 0;
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < PQsize; j++) {
            if (requests[j].getReqTime() == i) {
                pq.pqInsert(requests[j]);
                size++;
                requests[j].setAdd(i);
            }
        }
        if (!pq.pqIsEmpty()) {
            for (int j = 0; j < computerSize; j++) {
                if (computerArr[j].getAvailable() && pq.getHeap().getSize() != 0) {
                    Request del;
                    pq.pqDelete(del);
                    del.setExecute(i);
                    str += "Computer " + to_string(j) + " takes request " + to_string(del.getId()) + " at " + to_string(i) + " ms (wait: " + to_string(del.calculateWait()) + " ms)\n";
                    sum += del.calculateWait();
                    computerArr[j].setAvailable(false);
                    computerArr[j].setTime(i + del.getProcessed());
                }
            }
        }
        for (int j = 0; j < computerSize; j++) {
            if (computerArr[j].getTime() == i) {
                computerArr[j].setAvailable(true);
                computerArr[j].setTime(0);
            }
        }
    }

    avg = sum / PQsize;

    if (avg > avgTime) {
        computerSize++;
        delete [] computerArr;
        computerArr = NULL;
        return calculate(inFile, fileName, avgTime);
    }
    else {
        str += "Average waiting time is: " + to_string(avg) + " ms\n";
        return str;
    }
}