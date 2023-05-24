
/*
* Title: CS202 HW4
* Author: Gökberk Altıparmak
* ID: 21901798
* Section: 3
* Assignment: 4
* Description: Doing some operations on graph.
*/

#ifndef DESTROYER_PM
#define DESTROYER_PM

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
class node {
private:
    node *next;
    int airport;
    int duration;
    bool visited;
public:
    friend class graph;
    node() {
        next = NULL;
        airport = -1;
        duration = -1;
        visited = false;
    }
    node(int airport, int duration) {
        next = NULL;
        this->airport = airport;
        duration = duration;
        visited = false;
    }
};
class graph {
private:
    node **head;
    int size;
    //bool* visited;
public:
    graph(int num);
    void insert(int airport1, int airport2, int duration);
    void listFlights(int index);
    void readFile(ifstream& inFile, string fileName);
    void dfs(int v);
    void dfsIT(int v);
};

#endif // DESTROYER_PM