/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Object that has its own variables with getter and setter methods.
*/

#ifndef COMPTUER_H
#define COMPUTER_H

#include "Request.h"
#include <iostream>
using namespace std;

class Computer {
    public:
    Computer();
    void setAvailable(bool setav);
    bool getAvailable();
    void setTime(double setTime);
    double getTime();
    private:
    bool available;
    double freeTime;
};

#endif