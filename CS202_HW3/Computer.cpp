/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Object that has its own variables with getter and setter methods.
*/

#include "Computer.h"

Computer::Computer() {
    freeTime = 0;
    available = true;
}

void Computer::setAvailable(bool setav) {
    available = setav;
}

void Computer::setTime(double setTime) {
    freeTime = setTime;
}

bool Computer::getAvailable() {
    return available;
}

double Computer::getTime() {
    return freeTime;
}