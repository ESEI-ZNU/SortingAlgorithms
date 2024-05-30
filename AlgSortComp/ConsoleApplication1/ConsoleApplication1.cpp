#include <iostream>
#include "Array.h"
#include "SortingComparison.h"
#include <cstdlib>
#include <ctime>
#include <functional>

using namespace std;

int main()
{
    srand(time(0));
    Array arr(100);
    arr.fillRandom();

    cout << "Before sorting:" << endl;
    arr.print();

    SortingComparison::measurePerformance("Bubble Sort", SortingComparison::bubbleSort, arr);
    SortingComparison::measurePerformance("Shaker Sort", SortingComparison::shakerSort, arr);
    SortingComparison::measurePerformance("Insertion Sort", SortingComparison::insertionSort, arr);
    SortingComparison::measurePerformance("Selection Sort", SortingComparison::selectionSort, arr);
    SortingComparison::measurePerformance("Merge Sort", SortingComparison::mergeSort, arr);
    SortingComparison::measurePerformance("Quick Sort", SortingComparison::quickSort, arr);

    return 0;
}
