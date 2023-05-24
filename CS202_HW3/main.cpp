/*
* Title: Priority Queue
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 3
* Description: Main function of program.
*/


#include <fstream>
#include <iostream>
using namespace std;
#include "Requests.h"


int main(int argc, char **argv) {
    double maxAvg = stod(argv[2]);
    Requests r;
    ifstream inFile;
    string fileName = argv[1];
    cout << r.calculate(inFile, fileName, maxAvg);
    return -1;
}
