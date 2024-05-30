#ifndef SORTINGCOMPARISON_H
#define SORTINGCOMPARISON_H

#include "Array.h"
#include <functional>
#include <string>

class SortingComparison
{
public:
    static void bubbleSort(Array& arr);
    static void shakerSort(Array& arr);
    static void insertionSort(Array& arr);
    static void selectionSort(Array& arr);
    static void mergeSort(Array& arr);
    static void quickSort(Array& arr);
    static void measurePerformance(const std::string& sortMethodName, const std::function<void(Array&)>& sortMethod, Array& arr);
private:
    static void mergeSortRecursive(int* arr, size_t left, size_t right);
    static void quickSortRecursive(int* arr, size_t left, size_t right);
    static void swap(int& a, int& b);
};

#endif 

