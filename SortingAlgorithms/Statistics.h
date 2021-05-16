#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Statistic {
private:
    double** array;//массив для показаний статистики
    int N;// по количеству методов сортировки (в данном случае будет 2)
public:
    Statistic(int n) //коструктор статистики, в него передаем кол-во методов сортировки
    {
        N = n;
        array = new double* [N];
        for (int i = 0; i < N; i++)
            array[i] = new double[4]; //для каждого метода будем сохранять 4 показателя, время, колво циклов, колво сравнений и колво перестановок
    }

    //сортировку массива будем вызывать из класса статистики
    void sort_arrays(Array* a)//передаем ссылку на наши массивы (их будет столькоже сколько и сортировок, и содержать они будут одинаковые данные, для честности сравнения методов)
    {
        for (int i = 0; i < N; i++)//цикл по колву методов сортировки, в данном случае 2
        {
            long long iterations = 0, comparisons = 0, reshuffle = 0;// переменные для хранения итераций, сравнений и перстановок
            clock_t time1 = clock();// запоминаем время
            switch (i)//выбираем метод сортировки
            {
            case 0://метод пузырька
                cout << "\nBubble sort analysis\n";
                if (a[i].Size() < 20) { cout << "Before\n"; a[i].print_array(); }//если размер массива небольшой (менее 20) то будем распечатывать на экране до и после сортировки
                a[i].bubble_sort(iterations, comparisons, reshuffle);//сортировка
                if (a[i].Size() < 20) { cout << "\nAfter\n"; a[i].print_array(); }
                cout << "\nBubble sort analysis done\n";
                break;
            case 1://метод шейкер
                cout << "\nCocktail sort analysis\n";
                if (a[i].Size() < 20) { cout << "Before\n"; a[i].print_array(); }//если размер массива небольшой (менее 20) то будем распечатывать на экране до и после сортировки
                a[i].cocktail_sort(iterations, comparisons, reshuffle);//сортировка
                if (a[i].Size() < 20) { cout << "\nAfter\n"; a[i].print_array(); }
                cout << "\nCocktail sort analysis done\n";
                break;
            case 2://метод сортировки 3
                cout << "\nonemore_sort0 sort analysis\n";
                if (a[i].Size() < 20) { cout << "Before\n"; a[i].print_array(); }//если размер массива небольшой (менее 20) то будем распечатывать на экране до и после сортировки
                a[i].onemore_sort0(iterations, comparisons, reshuffle);//сортировка дополнительным методом
                if (a[i].Size() < 20) { cout << "\nAfter\n"; a[i].print_array(); }
                cout << "\nonemore_sort0 sort analysis done\n";
                break;
            case 3://метод сортировки 4
                cout << "\nonemore_sort1 sort analysis\n";
                if (a[i].Size() < 20) { cout << "Before\n"; a[i].print_array(); }//если размер массива небольшой (менее 20) то будем распечатывать на экране до и после сортировки
                a[i].onemore_sort1(iterations, comparisons, reshuffle);//сортировка еще одним доп методом
                if (a[i].Size() < 20) { cout << "\nAfter\n"; a[i].print_array(); }
                cout << "\nonemore_sort1 sort analysis done\n";
                break;

            }
            clock_t time2 = clock();//смотрим время окончания 
            array[i][0] = (double)(time2 - time1) / CLOCKS_PER_SEC;//разницу от времени окончания сортировки и начала переводим в секунды и сохраним в массив показателей
            array[i][1] = iterations;//сохраним в массив показателей итерации
            array[i][2] = comparisons;//сранения
            array[i][3] = reshuffle;//и перестановки
        }
    }
    void print_result()//метод вывода показателей статистики
    {
        cout << '\n';
        cout << "            time | iterations | comparsions | reshuffles\n";
        for (int i = 0; i < N; i++)
        {
            switch (i)//выводим название метода. их соответственно по количеству методов сортировок в классе (можно дабвить)
            {
            case 0:
                cout << " Buble  ";
                break;
            case 1:
                cout << "Cocktail";
                break;
            case 2:
                cout << "onemore0";
                break;
            case 3:
                cout << "onemore1";
                break;
            }
            for (int j = 0; j < 4; j++)
                cout << setw(10) << setprecision(10) << array[i][j] << " ";
            cout << '\n';
        }
    }
};