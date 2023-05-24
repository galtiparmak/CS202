
/*
* Title: Sorting and Algorithm Efficiency
* Author: Gokberk Altiparmak
* ID: 21901798
* Section: 3
* Assignment: 1
* Description: Calculates the efficiency of four different sorting algorithms(insertion, bubble, merge, quick)
* with three different conditions(random created array, almost sorted array, almost unsorted array).
*/

#include "sorting.h"

// Function to swap the given two integer values.
void sorting::swap(int& x, int& y) {
    int temp = y;
    y = x;
    x = temp;
}

// Insertion sorting algorithm
void sorting::insertionSort(int *arr, const int size, int &compCount, int &moveCount) {
    for (int unsorted = 1; unsorted < size; ++unsorted) {
        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;
        for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc) {
            arr[loc] = arr[loc-1];
            compCount++;
            moveCount++;
        }
        arr[loc] = nextItem;
        moveCount++;
    }
}

// Bubble sorting algorithm
void sorting::bubbleSort(int *arr, const int size, int &compCount, int &moveCount) {
    bool sorted = false;
    for (int pass = 1; (pass < size) && !sorted; ++pass) {
        sorted = true;
        for (int i = 0; i < size-pass; ++i) {
            int nextIndex = i + 1;
            if (arr[i] > arr[nextIndex]) {
                swap(arr[i], arr[nextIndex]);
                sorted = false;
                moveCount += 3;
            }
            compCount++;
        }
    }
}

// Merge sorting algorithm
void sorting::mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

void sorting::mergeSort(int *arr, int first, int last, int &compCount, int &moveCount) {
    if (first < last) {
        int mid = (first + last)/2;
        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid+1, last, compCount, moveCount);
        merge(arr, first, mid, last, compCount, moveCount);
   }
}

// Merge sort helper
void sorting::merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount){
    int first1 = first;
    int first2 = mid+1;
    int *tempArr = new int[last - first + 1];
    int index = 0;
    while (first1 <= (mid) && first2 <= last) {
        if (arr[first2] < arr[first1]) {
            tempArr[index] = arr[first2];
            first2++;
        } else {
            tempArr[index] = arr[first1];
            first1++;
        }
        index++;
        compCount++;
        moveCount++;
    }
    while (first1 <= (mid)) {
        tempArr[index] = arr[first1];
        first1++;
        moveCount++;
        index++;
    }
    while (first2 <= last) {
        tempArr[index] = arr[first2];
        first2++;
        moveCount++;
        index++;
    }

    for (int i = 0; i < index; i++) {
        arr[i + first] = tempArr[i];
        moveCount++;
    }
    delete [] tempArr;
}

// Quick sorting algorithm
void sorting::quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    quickSort(arr, 0, size-1, compCount, moveCount);
}

void sorting::quickSort(int *arr, int first, int last, int &compCount, int &moveCount) {
    int pivotIndex;
    if (first < last) {
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

// Quick sort helper
void sorting::partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    int pivot = arr[first];
    moveCount++;
    int lastS1 = first;
    int firstUnknown = first + 1;
    for (; firstUnknown <= last; ++firstUnknown) {
        if (arr[firstUnknown] < pivot) {
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount += 3;
        }
        compCount++;
    }
    swap(arr[first], arr[lastS1]);
    moveCount += 3;
    pivotIndex = lastS1;
}

// Displays the elements of given array
void sorting::displayArray(const int *arr, const int size){
     for (int i = 0 ; i < size; i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
}

// Creates four identical arrays with random numbers
void sorting::createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    for (int i = 0; i < size; i++) {
        int num = rand() % size * 10 + 1 ;
        arr1[i] = num;
        arr2[i] = num;
        arr3[i] = num;
        arr4[i] = num;
    }
}

// Creates four almost sorted identical arrays
void sorting::createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    const int n = (int) size / 20;
    for (int i = 0; i < size - 1; i++) {
        if (!(i%n)) {
            arr1[i+1] = i;
            arr1[i] = i+1;
            arr2[i+1] = i;
            arr2[i] = i+1;
            arr3[i+1] = i;
            arr3[i] = i+1;
            arr4[i+1] = i;
            arr4[i] = i+1;
            i+=2;
        }
        else {
            arr1[i] = i;
            arr2[i] = i;
            arr3[i] = i;
            arr4[i] = i;
        }
    }
}

// Creates four almost unsorted identical arrays
void sorting::createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    const int n = (int) size / 20;
    for (int i = size - 1; i > -1; i--) {
        if ((i%n) != 0) {
            arr1[i-1] = i;
            arr1[i] = i-1;
            arr2[i-1] = i;
            arr2[i] = i-1;
            arr3[i-1] = i;
            arr3[i] = i-1;
            arr4[i-1] = i;
            arr4[i] = i-1;
            i-=2;
        }
        else {
            arr1[i] = i;
            arr2[i] = i;
            arr3[i] = i;
            arr4[i] = i;
        }
    }
}

// Prints the headers of sorting algorithms
void sorting::sortingInfo(string sortType) {
    if (sortType == "insertion") {
        cout << "-------------------------------" << endl;
        cout << "Analysis of insertion sort" << endl;
        cout << "Array size" << setw(20) << "Elapsed Time" << setw(20) << "compCount" << setw(20) << "moveCount" << endl;
    }
    else if (sortType == "bubble") {
        cout << "-------------------------------" << endl;
        cout << "Analysis of bubble sort" << endl;
        cout << "Array size" << setw(20) << "Elapsed Time" << setw(20) << "compCount" << setw(20) << "moveCount" << endl;
    }
    else if(sortType == "merge") {
        cout << "-------------------------------" << endl;
        cout << "Analysis of merge sort" << endl;
        cout << "Array size" << setw(20) << "Elapsed Time" << setw(20) << "compCount" << setw(20) << "moveCount" << endl;
    }
    else if (sortType == "quick"){
        cout << "-------------------------------" << endl;
        cout << "Analysis of quick sort" << endl;
        cout << "Array size" << setw(20) << "Elapsed Time" << setw(20) << "compCount" << setw(20) << "moveCount" << endl;
    }
    else {
        cout << "No such sorting algorithm" << endl;
    }
}

// Prints the general contents of sorting algorithms with elapsed time.
string sorting::printOut(int *arr, int size, string sortType) {
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > timeElapsed;
    int compCount = 0;
    int moveCount = 0;
    string res = "";
    if (sortType == "insertion") {
        startTime = std::chrono::system_clock::now();
        insertionSort(arr, size, compCount, moveCount);
        timeElapsed = std::chrono::system_clock::now() - startTime;
        res = to_string(size) + "                 " + to_string(timeElapsed.count()) + "ms          " + to_string(compCount) + "           " + to_string(moveCount) + "\n";
    }
    else if (sortType == "bubble") {
        startTime = std::chrono::system_clock::now();
        bubbleSort(arr, size, compCount, moveCount);
        timeElapsed = std::chrono::system_clock::now() - startTime;
        res = to_string(size) + "                 " + to_string(timeElapsed.count()) + "ms           " + to_string(compCount) + "           " + to_string(moveCount) + "\n";
    }
    else if (sortType == "merge") {
        startTime = std::chrono::system_clock::now();
        mergeSort(arr, size, compCount, moveCount);
        timeElapsed = std::chrono::system_clock::now() - startTime;
        res = to_string(size) + "                 " + to_string(timeElapsed.count()) + "ms           " + to_string(compCount) + "           " + to_string(moveCount) + "\n";
    }
    else if (sortType == "quick") {
        startTime = std::chrono::system_clock::now();
        quickSort(arr, size, compCount, moveCount);
        timeElapsed = std::chrono::system_clock::now() - startTime;
        res = to_string(size) + "                 " + to_string(timeElapsed.count()) + "ms           " + to_string(compCount) + "           " + to_string(moveCount) + "\n";
    }
    else {
        cout << "ERROR!!!" << endl;
    }
    return res;
}

// Function to hold the content of printOut function via string array for random created arrays
void sorting::resultsOfRandomCreated(string *arr, int size) {
    int *arr1 = new int[size];
    int *arr2 = new int[size];
    int *arr3 = new int[size];
    int *arr4 = new int[size];
    createRandomArrays(arr1, arr2, arr3, arr4, size);
    string str1 = printOut(arr1, size, "insertion");
    string str2 = printOut(arr2, size, "bubble");
    string str3 = printOut(arr3, size, "merge");
    string str4 = printOut(arr4, size, "quick");
    arr[0] = str1;
    arr[1] = str2;
    arr[2] = str3;
    arr[3] = str4;
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
}

// Function to hold the content of printOut function via string array for almost sorted arrays
void sorting::resultsOfAlmostSorted(string *arr, int size) {
    int *arr1 = new int[size];
    int *arr2 = new int[size];
    int *arr3 = new int[size];
    int *arr4 = new int[size];
    createAlmostSortedArrays(arr1, arr2, arr3, arr4, size);
    string str1 = printOut(arr1, size, "insertion");
    string str2 = printOut(arr2, size, "bubble");
    string str3 = printOut(arr3, size, "merge");
    string str4 = printOut(arr4, size, "quick");
    arr[0] = str1;
    arr[1] = str2;
    arr[2] = str3;
    arr[3] = str4;
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
}

// Function to hold the content of printOut function via string array for almost unsorted arrays
void sorting::resultsOfAlmostUnsorted(string *arr, int size) {
    int *arr1 = new int[size];
    int *arr2 = new int[size];
    int *arr3 = new int[size];
    int *arr4 = new int[size];
    createAlmostUnsortedArrays(arr1, arr2, arr3, arr4, size);
    string str1 = printOut(arr1, size, "insertion");
    string str2 = printOut(arr2, size, "bubble");
    string str3 = printOut(arr3, size, "merge");
    string str4 = printOut(arr4, size, "quick");
    arr[0] = str1;
    arr[1] = str2;
    arr[2] = str3;
    arr[3] = str4;
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
}

// Performs and prints the output of program with calling result functions of three differently sorted arrays.
void sorting::performanceAnalysis() {
    int sizeArr[8] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000};
    string doubleRandom[8][4];
    string doubleAlmostSorted[8][4];
    string doubleAlmostUnsorted[8][4];
    for (int i = 0; i < 8; i++) {
        string random[4];
        string almostSorted[4];
        string almostUnsorted[4];
        resultsOfRandomCreated(random, sizeArr[i]);
        resultsOfAlmostUnsorted(almostUnsorted, sizeArr[i]);
        resultsOfAlmostSorted(almostSorted, sizeArr[i]);
        for (int j = 0; j < 4; j++) {
            doubleRandom[i][j] = random[j];
            doubleAlmostSorted[i][j] = almostSorted[j];
            doubleAlmostUnsorted[i][j] = almostUnsorted[j];
        }
    }

    cout << "------------Random Created Arrays------------" << endl;
    sortingInfo("insertion");
    for (int i = 0; i < 8; i++) {
        cout << doubleRandom[i][0] << endl;
    }
    sortingInfo("bubble");
    for (int i = 0; i < 8; i++) {
        cout << doubleRandom[i][1] << endl;
    }
    sortingInfo("merge");
    for (int i = 0; i < 8; i++) {
        cout << doubleRandom[i][2] << endl;
    }
    sortingInfo("quick");
    for (int i = 0; i < 8; i++) {
        cout << doubleRandom[i][3] << endl;
    }

    cout <<endl<<endl;

    cout << "------------Almost Sorted Arrays------------" << endl;
    sortingInfo("insertion");
    for (int i = 0; i < 8; i++) {
        cout << doubleAlmostSorted[i][0] << endl;
    }
    sortingInfo("bubble");
    for (int i = 0; i < 8; i++) {
        cout << doubleAlmostSorted[i][1] << endl;
    }
    sortingInfo("merge");
    for (int i = 0; i < 8; i++) {
        cout << doubleAlmostSorted[i][2] << endl;
    }
    sortingInfo("quick");
    for (int i = 0; i < 8; i++) {
        cout << doubleAlmostSorted[i][3] << endl;
    }

    cout <<endl<<endl;

    cout << "------------Almost Unsorted Arrays------------" << endl;
    sortingInfo("insertion");
    for (int i = 0; i < 8; i++) {
        cout << doubleAlmostUnsorted[i][0] << endl;
    }
    sortingInfo("bubble");
    for (int i = 0; i < 8; i++) {
        cout << doubleAlmostUnsorted[i][1] << endl;
    }
    sortingInfo("merge");
    for (int i = 0; i < 8; i++) {
        cout << doubleAlmostUnsorted[i][2] << endl;
    }
    sortingInfo("quick");
    for (int i = 0; i < 8; i++) {
        cout << doubleAlmostUnsorted[i][3] << endl;
    }

}



