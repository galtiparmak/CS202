
/*
* Title: CS202 HW4
* Author: Gökberk Altıparmak
* ID: 21901798
* Section: 3
* Assignment: 4
* Description: Doing some operations on graph.
*/

#include "graph.h"

int main(int argc, char **argv) {
    //string fileName = argv[1];
    //ifstream file(fileName);
    //int airports;
    //file >> airports;
    //ifstream inFile;
    //graph g(airports);
    //g.readFile(inFile, fileName);
    graph g(5);
    g.insert(0, 1, 4);
    g.insert(0, 2, 5);
    g.insert(0, 3, 1);
    g.insert(2, 1, 8);
    g.insert(3, 4, 2);
    //for (int i = 0; i < 5; i++) {
    //    g.listFlights(i);
    //}
    cout<<endl;
    g.dfs(0);
    return -1;
}

// g++ -o mm graph.cpp main.cpp