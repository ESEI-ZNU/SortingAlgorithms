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
    /// <returns> number of elements of the array </returns>
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
    ///Ñonstructor
    ///</summary>
    Array() {
        N = 0;
        arr = NULL;
    }

    //Author - Hnybidenko
    ///<summary>
    ///Ñonstructor for manual input
    ///</summary>
    ///<param name="n"> - number of elements </param>
    Array(int n) {
        N = n;
        arr = new int[N];
        set();
    }

    //Author - Hnybidenko
    ///<summary>
    ///Ñonstructor for random values
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
    ///Ñonstructor for copying
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
                if (arr[j - 1] > arr[j])
                {
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
    void cocktail_sort(long long int& iterations, long long int& comparisons, long long int& shuffle)
    {
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
    void onemore_sort0(long long int& iterations, long long int& comparisons, long long int& shuffle) {}
    void onemore_sort1(long long int& iterations, long long int& comparisons, long long int& shuffle) {}

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