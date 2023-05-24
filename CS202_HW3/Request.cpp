/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Request object that has its own variables and functions.
*/

#include "Request.h"

Request::Request() {
    id = 0;
    priority = 0;
    reqTime = 0;
    processTime = 0;
    wait = 0;
    add = 0;
    execute = 0;
}

Request::Request(int aid, int apriority, int areqTime, int aprocessTime, int await, int aadd, int aexecute) {
    id = aid;
    priority = apriority;
    reqTime = areqTime;
    processTime = aprocessTime;
    wait = await;
    add = aadd;
    execute = aexecute;
}

int Request::getId() {
    return id;
}

int Request::getPriority() {
    return priority;
}

int Request::getReqTime(){
    return reqTime;
}

int Request::getProcessed() {
    return processTime;
}

int Request::getWait() {
    return wait;
}

int Request::getAdd() {
    return add;
}

int Request::getExecute() {
    return execute;
}
 
void Request::setId(int set) {
    id = set;
}

void Request::setPriority(int set) {
    priority = set;
}

void Request::setReqTime(int set) {
    reqTime = set;
}

void Request::setProcessed(int set) {
    processTime = set;
}

void Request::setAdd(int set) {
    add = set;
}

void Request::setExecute(int set) {
    execute = set;
}

int Request::calculateWait() {
    wait = execute - add;
    return wait;
}