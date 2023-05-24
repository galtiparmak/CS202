/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Request object that has its own variables and functions.
*/

#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
using namespace std;

class Request {
    public:
        Request();
        Request(int aid, int apriority, int areqTime, int aprocessTime, int await, int aadd, int aexecute);
        int getId();
        int getPriority();
        int getReqTime();
        int getProcessed();
        int getWait();
        int getAdd();
        int getExecute();
        void setId(int set);
        void setPriority(int set);
        void setReqTime(int set);
        void setProcessed(int set);
        void setAdd(int set);
        void setExecute(int set);
        int calculateWait();
    private:
        int id;
        int priority;
        int reqTime;
        int processTime;
        int wait;
        int add;
        int execute;
};

#endif