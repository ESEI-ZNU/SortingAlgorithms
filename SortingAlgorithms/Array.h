#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Array  //Клас масиву з ітератором, конструктором, перевантаженим оператором присвоєння
{
private:
    int* arr;  //Посилання на масив
    int N;  //Кількість єлементів у масиві
public:

    //Структура ітератора, його категорія тип на який посилається та перевантажені оператори для роботи ітератора
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

    //Функція-геттер, повертає кількість елементів масиву
    int Size() {
        return N;
    }
    Iterator begin() {
        return Iterator(&arr[0]);
    }
    Iterator end() {
        return Iterator(&arr[N]);
    }

    //Перевантаження оператора присвоєння для класу Array
    Array& operator=(Array B) {
        if (N)delete arr;
        N = B.N;
        arr = new int[N];

        for (int i = 0; i < N; i++)
            arr[i] = B.arr[i];
        return *this;
    }

    //Конструктор без параметрів
    Array() {
        N = 0;
        arr = NULL;
    }

    //Конструктор з одним параметром для введення данних користувачем власноруч
    Array(int n) {
        N = n;
        arr = new int[N];
        set();
    }

    //Конструктор з двума параметрами, другий параметр задає розкид випадкових значень у масиві, якщо задати 1 або менше, то масив буде нульовий
    Array(int n, int widerand) {
        N = n;
        if (widerand < 1)
            widerand = 1;

        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = rand() % widerand;
    }

    //Конструктор копіювання
    Array(const Array& B) {
        N = B.N;
        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = B.arr[i];
    }

    //Деструктор классу
    ~Array() {
        delete[] arr;  //Звільнення пам'яті
    }

    //Друк елементів масива з використанням ітератора
    void print_array() {
        for (Iterator it = begin(); it != end(); ++it)
            cout << *it << " ";
    }

    //Заповнення масива елементами які вводить користувач. (Не використовуємо, тому що випадково заповнти швидше та легше, але за необхідністю можна переробити код у мейні
    void set() {
        for (int i = 0; i < N; i++) {
            cout << "Enter " << i << " element of array: ";
            cin >> arr[i];
        }
    }

    //Метод бульбашкового сортування
    void bubble_sort(long long int& iterations, long long int& comparisons, long long int& shuffle) {
        for (int i = 0; i < N; ++i) {
            iterations++;  //Підрахунок ітерацій у кожному циклі 

            for (int j = 0; j < N - i; j++) {
                iterations++;  //Підрахунок ітерацій у кожному циклі 
                comparisons++;  //Підрахунок порівнянь перед кожним порівнянням

                if (arr[j] < arr[j + 1]) {
                    shuffle++;  //Підрахунок перестановок перед кожною перестановкою 
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    //Метод шейкерного сортування
    void cocktail_sort(long long int& iterations, long long int& comparisons, long long int& shuffle)
    {
        int count = N;
        int left = 0, right = count - 1;
        int flag = 1;

        while ((left < right) && flag > 0)
        {
            iterations++;  //Підрахунок ітерацій у кожному циклі 
            flag = 0;

            for (int i = left; i < right; i++) {
                iterations++;  //Підрахунок ітерацій у кожному циклі 
                comparisons++;  //Підрахунок порівнянь перед кожним порівнянням

                if (arr[i] < arr[i + 1]) {
                    shuffle++;  //Підрахунок перестановок перед кожною перестановкою 
                    double t = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = t;
                    flag = 1;
                }
            }

            right--;
            for (int i = right; i > left; i--) {
                iterations++;  //Підрахунок ітерацій у кожному циклі 
                comparisons++;  //Підрахунок порівнянь перед кожним порівнянням

                if (arr[i - 1] < arr[i]) {
                    shuffle++;  //Підрахунок перестановок перед кожною перестановкою 
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

    //Пошук максимума серед елементів масива з використанням ітератора
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

    //Пошук мінімума серед елементів масива з використанням ітератора
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