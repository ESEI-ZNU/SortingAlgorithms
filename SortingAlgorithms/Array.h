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

    //Метод шейкерного сортування
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