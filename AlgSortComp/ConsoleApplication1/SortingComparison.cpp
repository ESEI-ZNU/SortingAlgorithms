#include "SortingComparison.h"
#include <chrono>
#include <iostream>

void SortingComparison::bubbleSort(Array& arr)
{
    size_t n = arr.getSize();
    int* data = arr.getData();
    for (size_t i = 0; i < n - 1; ++i)
    {
        for (size_t j = 0; j < n - i - 1; ++j)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void SortingComparison::shakerSort(Array& arr)
{
    size_t n = arr.getSize();
    int* data = arr.getData();
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < n - 1; ++i) {
            if (data[i] > data[i + 1]) {
                swap(data[i], data[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        for (size_t i = n - 1; i > 0; --i) {
            if (data[i - 1] > data[i]) {
                swap(data[i - 1], data[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

void SortingComparison::insertionSort(Array& arr)
{
    size_t n = arr.getSize();
    int* data = arr.getData();
    for (size_t i = 1; i < n; ++i)
    {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

void SortingComparison::selectionSort(Array& arr)
{
    size_t n = arr.getSize();
    int* data = arr.getData();
    for (size_t i = 0; i < n - 1; ++i)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < n; ++j)
        {
            if (data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(data[i], data[minIndex]);
        }
    }
}

void SortingComparison::mergeSort(Array& arr)
{
    mergeSortRecursive(arr.getData(), 0, arr.getSize() - 1);
}

void SortingComparison::mergeSortRecursive(int* arr, size_t left, size_t right)
{
    if (left < right)
    {
        size_t middle = left + (right - left) / 2;
        mergeSortRecursive(arr, left, middle);
        mergeSortRecursive(arr, middle + 1, right);

        int* temp = new int[right - left + 1];
        size_t i = left, j = middle + 1, k = 0;

        while (i <= middle && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }

        while (i <= middle)
        {
            temp[k++] = arr[i++];
        }

        while (j <= right)
        {
            temp[k++] = arr[j++];
        }

        for (i = left; i <= right; ++i)
        {
            arr[i] = temp[i - left];
        }

        delete[] temp;
    }
}

void SortingComparison::quickSort(Array& arr)
{
    quickSortRecursive(arr.getData(), 0, arr.getSize() - 1);
}

void SortingComparison::quickSortRecursive(int* arr, size_t left, size_t right)
{
    if (left < right)
    {
        int pivot = arr[left];
        size_t i = left, j = right;
        while (i <= j)
        {
            while (arr[i] < pivot) ++i;
            while (arr[j] > pivot) --j;
            if (i <= j)
            {
                swap(arr[i], arr[j]);
                ++i;
                --j;
            }
        }
        if (left < j) quickSortRecursive(arr, left, j);
        if (i < right) quickSortRecursive(arr, i, right);
    }
}

void SortingComparison::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SortingComparison::measurePerformance(const std::string& sortMethodName, const std::function<void(Array&)>& sortMethod, Array& arr)
{
    Array copy(arr.getSize());
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        copy[i] = arr[i];
    }
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sortMethod(copy);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Time taken for " << sortMethodName << ": " << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << endl;
    copy.print();
}
