#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

class Array
{
private:
    int* arr;
    int N;
public:

    struct Iterator
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
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&arr[0]); }
    Iterator end() { return Iterator(&arr[N]); }
    
    Array() //конструктор без параметров
    {
        N = 100000;
        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = 0;
    }
    Array(int n) //конструктор с одним параметром
    {
        N = n;
        arr = new int[N];
        set();
    }

    Array(int n, bool fRand) //конструктор с двумя параметрами
    {
        N = n;
        arr = new int[N];
        set_rand();
    }

    ~Array() //деструктор
    {
        delete[] arr; //освобождение памяти
    }

    void print_array() //показать массив
    {
        //for (auto it = begin(), ed = end(); it != ed; it++)
        for (int i = 0; i < N; i++)
        {
            // const auto i = *it - 1;
            cout << arr[i] << "  ";
        }
    }

    void set_rand() //ввод случайных элементов массива
    {
        srand(time(NULL));
        for (int i = 0; i < N; i++)
            arr[i] = rand() % 100;
    }

    void set() //ввод элементов заданных пользователем
    {
        for (int i = 0; i < N; i++)
        {
            cout << "Enter " << i << " element of array: ";
            cin >> arr[i];
        }
    }

    // метод сортировки пузырьком 
    void bubble_sort(long long int& iterations, long long int& comparisons)
    {
        for (int i = 0; i < N; ++i)
        {
            iterations++;
            for (int j = 0; j < N - i; j++)
            {
                iterations++;
                comparisons++;
                if (arr[j] < arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                }
            }
        }
    }

    void cocktail_sort(long long int& iterations, long long int& comparisons)
    {
        int count = N;
        int left = 0, right = count - 1;
        int flag = 1;

        while ((left < right) && flag > 0)
        {
            iterations++;

            flag = 0;
            for (int i = left; i < right; i++)
            {
                iterations++;
                comparisons++;
                if (arr[i] > arr[i + 1])
                {
                    double t = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = t;
                    flag = 1;
                }
            }
            right--;
            for (int i = right; i > left; i--)
            {
                iterations++;
                comparisons++;
                if (arr[i - 1] > arr[i])
                {
                    double t = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = t;
                    flag = 1;
                }
            }
            left++;
        }
    }

    //метод сортировки вставками
    void inserts_sort(long long int& iterations, long long int& comparisons)
    {
        for (int i = 1; i < N; i++)
        {
            for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //метод сортировки вибором
    void selection_sort(long long int& iterations, long long int& comparisons)
    {
        int min, temp;
        for (int i = 0; i < N - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < N; j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    //метод сортировки слиянием 
    void merge_sort(int* a, int l, int r)
    {
        if (l == r) return; // границы сомкнулись
        int mid = (l + r) / 2; // определяем середину последовательности
        // и рекурсивно вызываем функцию сортировки для каждой половины
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        int i = l;  // начало первого пути
        int j = mid + 1; // начало второго пути
        int* tmp = (int*)malloc(r * sizeof(int)); // дополнительный массив
        for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
        {
            // записываем в формируемую последовательность меньший из элементов двух путей
            // или остаток первого пути если j > r
            if ((j > r) || ((i <= mid) && (a[i] < a[j])))
            {
                tmp[step] = a[i];
                i++;
            }
            else
            {
                tmp[step] = a[j];
                j++;
            }
        }
        // переписываем сформированную последовательность в исходный массив
        for (int step = 0; step < r - l + 1; step++)
            a[l + step] = tmp[step];
    }

    //метод быстрой сортировки
    void quick_sort(int* arr, int first, int last)
    {
        {
            int mid, count;
            int f = first, l = last;
            mid = arr[(f + l) / 2]; //вычисление опорного элемента
            do
            {
                while (arr[f] < mid) f++;
                while (arr[l] > mid) l--;
                if (f <= l) //перестановка элементов
                {
                    count = arr[f];
                    arr[f] = arr[l];
                    arr[l] = count;
                    f++;
                    l--;
                }
            } while (f < l);
            if (first < l) quick_sort(arr, first, l);
            if (f < last) quick_sort(arr, f, last);
        }
    }
};


