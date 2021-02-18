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
        setRand();
    }

    ~Array() //деструктор
    {
        delete[] arr; //освобождение памяти
    }

    void printArray() //показать массив
    {
        for (int i = 0; i < N; i++)
            cout << arr[i] << "  ";
        cout << endl;
    }

    void setRand() //ввод случайных элементов массива
    {
        srand(time(NULL));
        for (int i = 0; i < N; i++)
            arr[i] = rand() % 100;
    }

    void set() //ввод элементов заданных пользователем
    {
        for (int i = 0; i < N; i++)
        {
            cout << "Введите " << i << " элемент массива: ";
            cin >> arr[i];
        }
    }
    // метод сортировки пузырьком 

    void bubble_sort(long long int& iterations, long long int& comparisons) {

        for (int i = 0; i < N; ++i) {
            iterations++;
            for (int j = 0; j < N - i; j++) {
                iterations++;
                comparisons++;
                if (arr[j] < arr[j + 1]) {

                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                }
            }
        }
    }

    void cocktail_sort(long long int& iterations, long long int& comparisons) {

        int count = N;
        int left = 0, right = count - 1;
        int flag = 1;

        while ((left < right) && flag > 0) {
            iterations++;

            flag = 0;
            for (int i = left; i < right; i++) {
                iterations++;
                comparisons++;
                if (arr[i] > arr[i + 1]) {
                    double t = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = t;
                    flag = 1;
                }
            }

            right--;

            for (int i = right; i > left; i--) {
                iterations++;
                comparisons++;
                if (arr[i - 1] > arr[i]) {

                    double t = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = t;
                    flag = 1;
                }
            }
            left++;
        }
    }

};

void getCorrectInput(int& value) {
    cin >> value;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неправильный ввод. Пожалуйста, попробуйте еще раз: ";
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
        for (int i = 0; i < N; i++) {
            array[i] = new double[4];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                array[i][j] = 0;
            }
        }
    }
    void zero_array() {
        for (int i = 0; i < 6; i++) {
            long long int iterations = 0, comparisons = 0;;
            clock_t time1 = clock();
            switch (i) {
            case 0:
                cout << "\nАнализ bubble_sort\n";
                zero.bubble_sort(iterations, comparisons);
                cout << "Анализ bubble_sort завершён\n";
                break;
            case 1:
                cout << "\nАнализ cocktail_sort\n";
                zero.cocktail_sort(iterations, comparisons);
                cout << "Анализ cocktail_sort завершён\n";
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
    void full_array() {
        for (int i = 0; i < 6; i++) {
            long long int iterations = 0, comparisons = 0;
            clock_t time1 = clock();
            switch (i) {
            case 0:
                cout << "\nАнализ bubble_sort\n";
                full.bubble_sort(iterations, comparisons);
                cout << "Анализ bubble_sort завершён\n";
                break;
            case 1:
                cout << "\nАнализ cocktail_sort\n";
                full.cocktail_sort(iterations, comparisons);
                cout << "Анализ cocktail_sort завершён\n";
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
    void print_result() {
        cout << '\n';
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                cout << setw(3) << setprecision(10) << array[i][j] << " ";
            }
            cout << '\n';
        }
    }
};

int main()
{
    setlocale(LC_CTYPE, "rus");
    Statistic analysis(6);
    int n, variant;

    do {
        do {
            cout << "Введите желаемый вариант заполнения массива: \n \t1) Заполнить нулевыми значениями \n \t2) Заполнить рандомными значениями\n \t0) Выход \n" << "Ваш выбор: ";
            getCorrectInput(variant);
        } while (variant < 0 || variant > 2);

        /*do {
            cout << "Введите размер массива: ";
            getCorrectInput(n);
        } while (n < 0);*/

        switch (variant)
        {
        case 0:
            cout << "Выход\n";
            break;
        case 1: {
            //Array array(n);
            cout << "Анализ с нулевым массивом: " << endl;
            analysis.zero_array();
            analysis.print_result();
            //array.printArray();
            break;
        }
        case 2: {
            //Array array(n, true);
            cout << "Анализ с случайным массивом: " << endl;
            analysis.full_array();
            analysis.print_result();
            //array.printArray();
            break;
        }
        default:
        {
            cout << "Необходимо выбрать один из вариантов" << endl;
        }
        }
    } while (variant != 0);

    system("pause");
    return 0;
}

