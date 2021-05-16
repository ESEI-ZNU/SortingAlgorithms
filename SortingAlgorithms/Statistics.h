#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//Класс для отримання статистики заданой колекції
class Statistic {
private:
    double** array;  //Масив для показань статистики
    int N;  //За кількістю методів сортування (в даному випадку буде 2)
public:

    //Конструктор статистики, в нього передаємо кількість методів сортування
    Statistic(int n) {  
        N = n;
        array = new double* [N];

        for (int i = 0; i < N; i++) {
            array[i] = new double[4];  //Для кожного методу будемо зберігати 4 показника, час, колво циклів, колво порівнянь і колво перестановок
        }
    }

    //Сортування масиву будемо викликати з класу статистики
    void sort_arrays(Array* a) {  //Передаємо посилання на наші масиви (їх буде столькоже скільки і угруповань, і містити вони будуть однакові дані, для чесності порівняння методів)
        for (int i = 0; i < N; i++) {  //Цикл за кількість методів сортування, в даному випадку 2
        
            long long iterations = 0, comparisons = 0, reshuffle = 0;  //Змінні для зберігання ітерацій, порівнянь і перстановок
            clock_t time1 = clock();  //Запам'ятовуємо час
            
            //Обираємо метод сортування
            switch (i) {  
            
            //Метод бульбашкового сортування
            case 0:  
                cout << "\nBubble sort analysis\n";

                //Якщо розмір масиву невеликий (менше 20) то будемо виводити елементи масиву на екран до і після сортування за допомогою ітератора 
                if (a[i].Size() < 20) { 
                    cout << "Before\n";
                    a[i].print_array(); 
                }

                //Викликаємо метод сортування та сортуємо
                a[i].bubble_sort(iterations, comparisons, reshuffle);  

                if (a[i].Size() < 20) { 
                    cout << "\nAfter\n";
                    a[i].print_array(); 
                }
                cout << "\nBubble sort analysis done\n";
                break;

            //Метод шейкерного сортування
            case 1:  
                cout << "\nCocktail sort analysis\n";

                //Якщо розмір масиву невеликий (менше 20) то будемо виводити елементи масиву на екран до і після сортування за допомогою ітератора 
                if (a[i].Size() < 20) { 
                    cout << "Before\n"; 
                    a[i].print_array(); 
                }

                //Викликаємо метод сортування та сортуємо
                a[i].cocktail_sort(iterations, comparisons, reshuffle);  

                if (a[i].Size() < 20) { 
                    cout << "\nAfter\n"; 
                    a[i].print_array(); 
                }
                cout << "\nCocktail sort analysis done\n";
                break;

            //Метод сортування 3
            case 2:  
                cout << "\nonemore_sort0 sort analysis\n";

                //Якщо розмір масиву невеликий (менше 20) то будемо виводити елементи масиву на екран до і після сортування за допомогою ітератора
                if (a[i].Size() < 20) { 
                    cout << "Before\n"; 
                    a[i].print_array();  
                }  


                //Сортування додатковим методом
                a[i].onemore_sort0(iterations, comparisons, reshuffle);  

                if (a[i].Size() < 20) { 
                    cout << "\nAfter\n"; 
                    a[i].print_array(); 
                }
                cout << "\nonemore_sort0 sort analysis done\n";
                break;

            //Метод сортування 4
            case 3:  
                cout << "\nonemore_sort1 sort analysis\n";

                //Якщо розмір масиву невеликий (менше 20) то будемо виводити елементи масиву на екран до і після сортування за допомогою ітератора
                if (a[i].Size() < 20) { 
                    cout << "Before\n"; 
                    a[i].print_array(); 
                }  

                //Сортування ще одним додатковим методом
                a[i].onemore_sort1(iterations, comparisons, reshuffle);  

                if (a[i].Size() < 20) { 
                    cout << "\nAfter\n"; a[i].print_array(); 
                }
                cout << "\nonemore_sort1 sort analysis done\n";
                break;
            }

            clock_t time2 = clock();  //Дивимося час закінчення

            array[i][0] = (double)(time2 - time1) / CLOCKS_PER_SEC;  //Різницю від часу закінчення сортування і початку переводимо в секунди і збережемо в масив показників
            array[i][1] = iterations;  //Зберігаємо в масив показники ітерацій
            array[i][2] = comparisons;  //Зберігаємо в масив показники порівнянь
            array[i][3] = reshuffle;  //Зберігаємо в масив показники перестановок
        }
    }

    //Метод виведення показників статистики
    void print_result() {  
    
        cout << '\n';
        cout << "            time | iterations | comparsions | reshuffles\n";

        for (int i = 0; i < N; i++) {
        
            //Виводимо назву методу. Кількість кейсів відповідно до кількості методів сортувань в класі (можна додати)
            switch (i) {  
            
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