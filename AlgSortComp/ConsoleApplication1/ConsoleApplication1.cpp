#include <iostream>
#include <array>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// Class to represent a dynamic array
class Array
{
private:
    int* data;   // Pointer to the data array
    size_t size; // Size of the array

public:
    // Constructor to initialize the array with a given size
    Array(size_t sz) : size(sz)
    {
        data = new int[size];
    }

    // Destructor to free the allocated memory
    ~Array()
    {
        delete[] data;
    }

    // Overload the subscript operator for array access
    int& operator[](size_t index)
    {
        return data[index];
    }

    // Get the size of the array
    size_t getSize() const
    {
        return size;
    }

    // Get the pointer to the data array
    int* getData() const
    {
        return data;
    }

    // Fill the array with random numbers between 0 and 99
    void fillRandom()
    {
        for (size_t i = 0; i < size; ++i) {
            data[i] = rand() % 100;
        }
    }

    // Print the contents of the array
    void print() const
    {
        for (size_t i = 0; i < size; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// Class to compare different sorting algorithms * late developer 2 commit
class SortingComparison
{
public:
    // Various sorting algorithms
    static void bubbleSort(Array& arr);
    static void shakerSort(Array& arr);
    static void insertionSort(Array& arr);
    static void selectionSort(Array& arr);
    static void mergeSort(Array& arr);
    static void quickSort(Array& arr);
    static void measurePerformance(const string& sortMethodName, const function<void(Array&)>& sortMethod, Array& arr);
private:
    // Helper functions for merge sort and quick sort
    static void mergeSortRecursive(int* arr, size_t left, size_t right);
    static void quickSortRecursive(int* arr, size_t left, size_t right);
    static void swap(int& a, int& b);
};

// Bubble sort algorithm
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

// Shaker sort algorithm (bidirectional bubble sort)
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

// Insertion sort algorithm
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

// Selection sort algorithm
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

// Merge sort algorithm
void SortingComparison::mergeSort(Array& arr)
{
    mergeSortRecursive(arr.getData(), 0, arr.getSize() - 1);
}

// Recursive function for merge sort
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

// Quick sort algorithm
void SortingComparison::quickSort(Array& arr)
{
    quickSortRecursive(arr.getData(), 0, arr.getSize() - 1);
}

// Recursive function for quick sort
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

// Swap two integers
void SortingComparison::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Measure the performance of a sorting algorithm
void SortingComparison::measurePerformance(const string& sortMethodName, const function<void(Array&)>& sortMethod, Array& arr)
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

int main()
{
    srand(time(0)); // Seed the random number generator
    Array arr(100); // Create an array of size 100
    arr.fillRandom(); // Fill the array with random numbers

    cout << "Before sorting:" << endl;
    arr.print(); // Print the array before sorting

    // Measure and print the performance of different sorting algorithms
    SortingComparison::measurePerformance("Bubble Sort", SortingComparison::bubbleSort, arr);
    SortingComparison::measurePerformance("Shaker Sort", SortingComparison::shakerSort, arr);
    SortingComparison::measurePerformance("Insertion Sort", SortingComparison::insertionSort, arr);
    SortingComparison::measurePerformance("Selection Sort", SortingComparison::selectionSort, arr);
    SortingComparison::measurePerformance("Merge Sort", SortingComparison::mergeSort, arr);
    // SortingComparison::measurePerformance("Quick Sort", SortingComparison::quickSort, arr);

    return 0;
}