
/*
* Title: CS202 HW4
* Author: Gökberk Altıparmak
* ID: 21901798
* Section: 3
* Assignment: 4
* Description: Doing some operations on graph.
*/


#include "graph.h"

graph::graph(int num) {
    //visited = new bool[5];
    //for (int i = 0; i < 5; i++) {
    //    visited[i] = false;
    //}

    head = new node*[num];
    for(int i = 0; i < num; i++) {
        head[i] = NULL;
    }
    size = num;
}

void graph::insert(int airport1, int airport2, int duration) {
    node *src;
    node *destination1 = new node(airport2, duration);
    node *destination2 = new node(airport1, duration);
    if (head[airport1] == NULL && head[airport2] == NULL) { 
        head[airport1] = destination1;
        head[airport2] = destination2;
    }
    else if (head[airport1] == NULL && head[airport2] != NULL) {
        head[airport1] = destination1;
        src = head[airport2];
        while (src->next != NULL)
            src = src->next;
        src->next = destination2;
    }
    else if (head[airport1] != NULL && head[airport2] == NULL) {
        head[airport2] = destination2; 
        src = head[airport1];
        while (src->next != NULL)
            src = src->next;
        src->next = destination1;
    }
    else {
        src = head[airport1];
        while (src->next != NULL)
            src = src->next;
        src->next = destination1;
        src = head[airport2];
        while (src->next != NULL)
            src = src->next;
        src->next = destination2;
    }
    cout << "Inserted a new flight between " << airport1 << " " << airport2 << endl;
}

void graph::listFlights(int airport) {
    int count = 0;
    node *ptr = head[airport];
    if (ptr == NULL) {
        cout << "No flight from " << airport << endl;
    }
    else {
        cout << "List of flights from " << airport << endl;
        while (ptr != NULL) {
            cout << airport << " to " << ptr->airport << " with a duration of " << ptr->duration << endl;
            count++;
            ptr = ptr->next;
        }
    }
    cout << "The number of flights is " << count << endl;
}

void graph::readFile(ifstream& inFile, string fileName) {
    inFile.open(fileName);
    if (!inFile) {
        cout << "unable to open file" << endl;
    }
    int airports, operations;
    inFile >> airports >> operations;
    string op;
    int airport1, airport2, duration;
    while (!inFile.eof()) {
        inFile >> op;
        if (op == "I") {
            inFile >> airport1 >> airport2 >> duration;
            insert(airport1, airport2, duration);
        }
        else if (op == "L") {
            inFile >> airport1;
            listFlights(airport1);
        }
        else if (op == "S") {
            cout << "Shortest path is not working" << endl;
        }
        else if (op == "M") {
            cout << "Minimum cost is not working" << endl;
        }
    }
}

void graph::dfs(int v) {
    static bool visited[5];
    visited[v] = true;
    cout << "Airport " << v << " visited" << endl;
    node* ptr = head[v];
    while(ptr != NULL) {
        if(!visited[ptr->airport]) {
            dfs(ptr->airport);
        }
        ptr = ptr->next;
    }
}



