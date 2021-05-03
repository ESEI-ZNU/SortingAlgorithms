#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <typeinfo>
#include "Array.cpp"

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
                cout << "\nInsetrs sort analysis\n";
                full.inserts_sort(iterations, comparisons);
                cout << "Insetrs sort analysis done\n";
                break;
            case 3:
                cout << "\nSelection sort analysis\n";
                full.selection_sort(iterations, comparisons);
                cout << "Selection sort analysis done\n";
                break;
            case 4:
                cout << "\nMerge sort analysis\n";
                full.merge_sort(iterations, comparisons);
                cout << "Merge sort analysis done\n";
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