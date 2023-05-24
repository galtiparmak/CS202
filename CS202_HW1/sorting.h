
/*
* Title: Sorting and Algorithm Efficiency
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 1
* Description: Calculates the efficiency of four different sorting algorithms(insertion, bubble, merge, quick)
* with three different conditions(random created array, almost sorted array, almost unsorted array).
*/

#ifndef DESTROYER_H
#define DESTROYER__H


#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class sorting {
public:
    void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
    void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
    void quickSort(int *arr, const int size, int &compCount, int &moveCount);
    void displayArray(const int *arr, const int size);
    void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void swap(int& x, int& y);
    void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
    void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
    void sortingInfo(string sortType);
    string printOut(int *arr, int size, string sortType);
    void resultsOfRandomCreated(string *arr, int size);
    void resultsOfAlmostSorted(string *arr, int size);
    void resultsOfAlmostUnsorted(string *arr, int size);
    void performanceAnalysis();
};



#endif // DESTROYER_H
