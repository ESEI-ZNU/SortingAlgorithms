#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Array //класс массива с итератором, кострукторами, перегруженным оператором присваивания
{
private:
    int* arr; //ссылка на массив
    int N;  //кол-во элемнтов вмассиве
public:
    struct Iterator //структура итератора, его катоегория тип на который ссылается и перегруженные операторы для работы итератора
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = int*;
        using reference = int&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator& operator++() { m_ptr++; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; (*this)++; return tmp; }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
    private:
        pointer m_ptr;
    };
    int Size() { return N; }
    Iterator begin() { return Iterator(&arr[0]); }
    Iterator end() { return Iterator(&arr[N]); }
    Array& operator=(Array B) //перегрузка оператора присваивания для нашего класса
    {
        if (N)delete arr;
        N = B.N;
        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = B.arr[i];
        return *this;
    }
    Array() //конструктор без параметров
    {
        N = 0;
        arr = NULL;
    }
    Array(int n) //конструктор с одним параметром и ручным вводом массива. далее по коду будет возможность использовать и этот метод ввода
    {
        N = n;
        arr = new int[N];
        set();
    }
    Array(int n, int widerand) //конструктор с двумя параметрами. второй параметр задает разброс рандомных значений в массиве. если задать 1 или менее = массив будет нулевой
    {
        N = n;
        if (widerand < 1)widerand = 1;
        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = rand() % widerand;
    }
    Array(const Array& B) //конструктор копирования
    {
        N = B.N;
        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = B.arr[i];
    }
    ~Array() //деструктор
    {
        delete[] arr; //освобождение памяти
    }
    void print_array() //печать массива массива с использовнием итератора
    {
        for (Iterator it = begin(); it != end(); ++it)
            cout << *it << " ";
    }

    void set() //ввод элементов заданных пользователем... не используем. потому как рандомно заполнить и быстрее и легче а если надо, то далее в мэйне можно чуть код переделать
    {
        for (int i = 0; i < N; i++)
        {
            cout << "Enter " << i << " element of array: ";
            cin >> arr[i];
        }
    }
    // метод сортировки пузырьком 
    void bubble_sort(long long int& iterations, long long int& comparisons, long long int& shuffle)
    {
        for (int i = 0; i < N; ++i)
        {
            iterations++;//подсчет итераций в каждом цикле
            for (int j = 0; j < N - i; j++)
            {
                iterations++;//подсчет итераций в каждом цикле
                comparisons++;//подсчет сравнений перед каждым сравнением
                if (arr[j] < arr[j + 1])
                {
                    shuffle++;//подсчет перестановки перед каждой перестановкой
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    //метод шейкерного сортирования
    void cocktail_sort(long long int& iterations, long long int& comparisons, long long int& shuffle)
    {
        int count = N;
        int left = 0, right = count - 1;
        int flag = 1;

        while ((left < right) && flag > 0)
        {
            iterations++;//подсчет итераций в каждом цикле
            flag = 0;
            for (int i = left; i < right; i++)
            {
                iterations++; //подсчет итераций в каждом цикле
                comparisons++;//подсчет сравнений перед каждым сравнением
                if (arr[i] < arr[i + 1])
                {
                    shuffle++;//подсчет перестановки перед каждой перестановкой
                    double t = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = t;
                    flag = 1;
                }
            }
            right--;
            for (int i = right; i > left; i--)
            {
                iterations++; //подсчет итераций в каждом цикле
                comparisons++;//подсчет сравнений перед каждым сравнением
                if (arr[i - 1] < arr[i])
                {
                    shuffle++;//подсчет перестановки перед каждой перестановкой
                    double t = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = t;
                    flag = 1;
                }
            }
            left++;
        }
    }
    void onemore_sort0(long long int& iterations, long long int& comparisons, long long int& shuffle) {}
    void onemore_sort1(long long int& iterations, long long int& comparisons, long long int& shuffle) {}


    int Max() //поиск максимума в массиве через итератор
    {
        int max = *begin();
        for (Iterator it = begin(); it != end(); ++it)
            if (max < *it)max = *it;
        return max;
    }
    int Min()//поиск минимума
    {
        int min = *begin();
        for (Iterator it = begin(); it != end(); ++it)
            if (min > *it)min = *it;
        return min;
    }
};