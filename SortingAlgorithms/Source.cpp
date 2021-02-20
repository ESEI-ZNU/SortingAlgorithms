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

    /*struct Iterator
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
    */
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

    //метод сортировки вибором

    //метод сортировки слиянием 

    //метод быстрой сортировки

};

void get_correct_input(int& value) 
{
    cin >> value;
    while (cin.fail()) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please try again: ";
        cin >> value;
    }
}

Array zero;
Array full(100000, 1);

class Statistic {
private:
    double** array;
    int N;
public:
    Statistic(int n) {
        N = n;
        array = new double* [N];
        for (int i = 0; i < N; i++) 
        {
            array[i] = new double[4];
        }
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                array[i][j] = 0;
            }
        }
    }
    void zero_array() 
    {
        for (int i = 0; i < 6; i++) 
        {
            long long int iterations = 0, comparisons = 0;;
            clock_t time1 = clock();
            switch (i) 
            {
                case 0:
                    cout << "\nc\n";
                    zero.bubble_sort(iterations, comparisons);
                    cout << "Bubble sort analysis done\n";
                    break;
                case 1:
                    cout << "\nCocktail sort analysis\n";
                    zero.cocktail_sort(iterations, comparisons);
                    cout << "Cocktail sort analysis done\n";
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
            }
            clock_t time2 = clock();
            array[i][0] = (double)(time2 - time1) / CLOCKS_PER_SEC;
            array[i][1] = iterations;
            array[i][2] = comparisons;
        }
    }
    void full_array() 
    {
        for (int i = 0; i < 6; i++) 
        {
            long long int iterations = 0, comparisons = 0;
            clock_t time1 = clock();
            switch (i) 
            {
                case 0:
                    cout << "\nBubble sort analysis\n";
                    full.bubble_sort(iterations, comparisons);
                    cout << "Bubble sort analysis done\n";
                    break;
                case 1:
                    cout << "\nCocktail sort analysis\n";
                    full.cocktail_sort(iterations, comparisons);
                    cout << "Cocktail sort analysis done\n";
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
            }
            clock_t time2 = clock();
            array[i][0] = (double)(time2 - time1) / CLOCKS_PER_SEC;
            array[i][1] = iterations;
            array[i][2] = comparisons;
        }
    }
    void print_result() 
    {
        cout << '\n';
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                cout << setw(3) << setprecision(10) << array[i][j] << " ";
            }
            cout << '\n';
        }
    }
};

int main()
{
    Statistic analysis(6);
    int n, choice;

    do 
    {
        do 
        {
            cout << endl;
            cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
            cout << " * Enter the desired option for filling the array:   *" << endl;
            cout << " *\t1 - Fill with zero values                    *" << endl;
            cout << " *\t2 - Fill with random values                  *" << endl;
            cout << " *\t0 - Exit                                     *" << endl;
            cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
            cout << "\t\t\t\t        Your choice: ";
            
            get_correct_input(choice);
        } while (choice < 0 || choice > 2);

        /*do {
            cout << "Введите размер массива: ";
            getCorrectInput(n);
        } while (n < 0);*/

        switch (choice)
        {
            case 0:
                cout << "Exit\n";
                break;
            case 1: 
                //Array array(n);
                cout << "Zero array analysis: " << endl;
                analysis.zero_array();
                analysis.print_result();
                //array.printArray();
                break;
            case 2: 
                //Array array(n, true);
                cout << "Random array analysis: " << endl;
                analysis.full_array();
                analysis.print_result();
                //array.printArray();
                break;
        }
    } while (choice != 0);

    system("pause");
    return 0;
}

