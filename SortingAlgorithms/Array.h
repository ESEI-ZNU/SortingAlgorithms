#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//Author - Hnybidenko
//Array class with iterator, constructor, overloaded assignment operator
class Array 
{
private:
    int* arr;  //Link to the array
    int N;  //The number of elements in the array
public:

    //Author - Hnybidenko and Bigun
    //The structure of the iterator, its category, the type referenced and overloaded operators for the operation of the iterator
    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = int*;
        using reference = int&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const {
            return *m_ptr;
        }
        pointer operator->() {
            return m_ptr;
        }
        Iterator& operator++() {
            m_ptr++; return *this;
        }
        Iterator operator++(int) {
            Iterator tmp = *this;
            (*this)++; return tmp;
        }

        friend bool operator== (const Iterator& a, const Iterator& b) {
            return a.m_ptr == b.m_ptr;
        };
        friend bool operator!= (const Iterator& a, const Iterator& b) {
            return a.m_ptr != b.m_ptr;
        };
    private:
        pointer m_ptr;
    };

    //Author - Hnybidenko
    ///<summary>
    ///Getter function for the number of elements
    ///</summary>
    /// <returns> number of elements of the array </returns>
    int Size() {
        return N;
    }
    Iterator begin() {
        return Iterator(&arr[0]);
    }
    Iterator end() {
        return Iterator(&arr[N]);
    }

    //Author - Hnybidenko
    ///<summary>
    ///Overloading the assignment operator for the Array class
    ///</summary>
    Array& operator=(Array B) {
        if (N)delete arr;
        N = B.N;
        arr = new int[N];

        for (int i = 0; i < N; i++)
            arr[i] = B.arr[i];
        return *this;
    }

    //Author - Hnybidenko
    ///<summary>
    ///Constructor
    ///</summary>
    Array() {
        N = 0;
        arr = NULL;
    }

    //Author - Hnybidenko
    ///<summary>
    ///Constructor for manual input
    ///</summary>
    ///<param name="n"> - number of elements </param>
    Array(int n) {
        N = n;
        arr = new int[N];
        set();
    }

    //Author - Hnybidenko
    ///<summary>
    ///Constructor for random values
    ///</summary>
    ///<param name="n"> - number of elements </param>
    ///<param name="widerand"> - flag </param>
    Array(int n, int widerand) {
        N = n;
        if (widerand < 1)
            widerand = 1;

        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = rand() % widerand;
    }

    //Author - Hnybidenko
    ///<summary>
    ///Constructor for copying
    ///</summary>
    ///<param name="B"> - link to an array for a copy </param>
    Array(const Array& B) {
        N = B.N;
        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = B.arr[i];
    }

    //Author - Hnybidenko
    ///<summary>
    ///Destructor
    ///</summary>
    ~Array() {
        delete[] arr; 
    }

    //Author - Hnybidenko
    ///<summary>
    ///Print array elements using an iterator
    ///</summary>
    void print_array() {
        for (Iterator it = begin(); it != end(); ++it)
            cout << *it << " ";
    }

    //Author - Hnybidenko
    ///<summary>
    ///Filling the array with elements entered by the user
    ///</summary>
    void set() {
        for (int i = 0; i < N; i++) {
            cout << "Enter " << i << " element of array: ";
            cin >> arr[i];
        }
    }

    //Author - Ryabko
    ///<summary>
    ///Bubble sort method
    ///</summary>
    ///<param name="iterations"> - number of iterations </param>
    ///<param name="comparisons"> - number of comparisons </param>
    ///<param name="shuffle"> - number of shuffle </param>
    void bubble_sort(long long int& iterations, long long int& comparisons, long long int& shuffle) {
        int i, j, x, k;
        for (i = 1; i < N; i++)
        {
            iterations++;
            for (j = N - 1; j >= i; j--) {
                comparisons++;
                if (arr[j - 1] > arr[j]) {
                    shuffle++;
                    x = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = x;
                }
            }

        }
    }

    //Author - Ryabko
    ///<summary>
    ///Coctail sort method
    ///</summary>
    ///<param name="iterations"> - number of iterations </param>
    ///<param name="comparisons"> - number of comparisons </param>
    ///<param name="shuffle"> - number of shuffle </param>
    void cocktail_sort(long long int& iterations, long long int& comparisons, long long int& shuffle) {
        int i = N - 1, j, k, x, l, r;
        l = 1;
        r = N - 1;
        do {
            for (j = r; j >= l; j--) {
                comparisons++;
                if (arr[j - 1] > arr[j])
                {
                    shuffle++;
                    x = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = x;
                    i = j;
                }
            }
            iterations++;
            l = i + 1;

            for (j = l; j <= r; j++) {
                comparisons++;
                if (arr[j - 1] > arr[j])
                {
                    shuffle++;
                    x = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = x;
                    i = j;
                }
            }
            iterations++;
            r = i - 1;
        } while (l <= r);
    }

    //Author - Tsiluiko
    ///<summary>
    ///Selection sort method
    ///</summary>
    ///<param name="iterations"> - number of iterations </param>
    ///<param name="comparisons"> - number of comparisons </param>
    ///<param name="shuffle"> - number of shuffle </param>
    void selection_sort(long long int& iterations, long long int& comparisons, long long int& shuffle) {
        int i, j, x, k, m;
        iterations++;

        for (i = 0; i < N - 1; i++) {
            x = arr[i];
            k = i;

            for (j = i + 1; j < N; j++) {
                comparisons++;
                if (arr[j] < x) {
                    k = j;
                    x = arr[k];

                }
            }
            shuffle++;
            arr[k] = arr[i];
            arr[i] = x;
        }
    }

    //Author - Tsiluiko
    ///<summary>
    ///Insertion sort method
    ///</summary>
    ///<param name="iterations"> - number of iterations </param>
    ///<param name="comparisons"> - number of comparisons </param>
    ///<param name="shuffle"> - number of shuffle </param>
    void insertion_sort(long long int& iterations, long long int& comparisons, long long int& shuffle) {
        int i, j, x, k;

        for (i = 1; i < N; i++) {
            iterations++;
            x = arr[i]; 
            j = i;
            comparisons++;

            while ((j > 0) && (x < arr[j - 1])) {
                comparisons++;
                shuffle++;
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = x;
        }
    }
    //Author - Smirnov
    ///<summary>
    ///Merge sort method
    ///</summary>
    ///<param name="iterations"> - number of iterations </param>
    ///<param name="comparisons"> - number of comparisons </param>
    ///<param name="shuffle"> - number of shuffle </param>
    void merge_sort(long long int& iterations, long long int& comparisons, long long int& shuffle) {
        int A, p, r, q;
        int n1, n2;
        n1 = q - p;
        n2 = r - q;
        int* L = new int[n1];
        int* R = new int[n2];
        for (int i = 0; i <= n1; ++i)
            L[i] = A[i];

        for (int j = 0; j <= n2; ++j)
            R[j] = A[j + q + 1];
            n1 = n2 = 1;
        for (int k = p; k < r; ++k)
        {
        if (L[n1] > R[n2] && n1 < l && n1 < k)
            {
                A[k] = L[n1];
                n1++;
            }
            else
            {
                A[k] = R[n2];
                n2++;
            }
        }
    }

    //Author - Smirnov
   ///<summary>
   ///Merge quick method
   ///</summary>
   ///<param name="iterations"> - number of iterations </param>
   ///<param name="comparisons"> - number of comparisons </param>
   ///<param name="shuffle"> - number of shuffle </param>
    void quick_sort(long long int& iterations, long long int& comparisons, long long int& shuffle) {
        int i = low;
        int j = high;
        int pivot = array[(i + j) / 2];
        int temp;

        while (i <= j)
        {
            while (array[i] < pivot)
                i++;
            while (array[j] > pivot)
                j--;
            if (i <= j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }
        if (j > low)
            quickSort(array, low, j);
        if (i < high)
            quickSort(array, i, high);
    
    }
    /// 
    //Author - Hnybidenko
    ///<summary>
    ///Find the maximum among the elements of the array using an iterator
    ///</summary>
    int Max()
    {
        int max = *begin();
        for (Iterator it = begin(); it != end(); ++it) {
            if (max < *it) {
                max = *it;
            }
        }
        return max;

    }

    //Author - Hnybidenko
    ///<summary>
    ///Find the minimum among the elements of the array using an iterator
    ///</summary>
    int Min()
    {
        int min = *begin();
        for (Iterator it = begin(); it != end(); ++it) {
            if (min > *it) {
                min = *it;
            }
        }
        return min;
    }
};