
/*
* Title: Sorting and Algorithm Efficiency
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 1
* Description: Calculates the efficiency of four different sorting algorithms(insertion, bubble, merge, quick)
* with three different conditions(random created array, almost sorted array, almost unsorted array).
*/

#include <iostream>
#include "sorting.h"
using namespace std;

// driver function
int main() {
    sorting s;
    int compCount = 0;
    int moveCount = 0;
    int temp1[16] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int temp2[16] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int temp3[16] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int temp4[16] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    cout << "-------------- Insertion Sort --------------" << endl;
    s.insertionSort(temp1, 16, compCount, moveCount);
    s.displayArray(temp1, 16);
    cout << "Compare count = " << compCount << "  Move count = " << moveCount << endl;

    compCount = 0;
    moveCount = 0;

    cout << "-------------- Bubble Sort --------------" << endl;
    s.bubbleSort(temp2, 16, compCount, moveCount);
    s.displayArray(temp2, 16);
    cout << "Compare count = " << compCount << "  Move count = " << moveCount << endl;

    compCount = 0;
    moveCount = 0;

    cout << "-------------- Merge Sort --------------" << endl;
    s.mergeSort(temp3, 16, compCount, moveCount);
    s.displayArray(temp3, 16);
    cout << "Compare count = " << compCount << "  Move count = " << moveCount << endl;

    compCount = 0;
    moveCount = 0;

    cout << "-------------- Quick Sort --------------" << endl;
    s.quickSort(temp4, 16, compCount, moveCount);
    s.displayArray(temp4, 16);
    cout << "Compare count = " << compCount << "  Move count = " << moveCount << endl;

    cout << endl;
    s.performanceAnalysis();
    return 0;
}

