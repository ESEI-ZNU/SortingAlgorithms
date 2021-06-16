#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//Author - Bigun
//Class to obtain statistics for a given collection
class Statistic {
private:
    double** array;  
    int N; 
public:

    //Author - Bigun
    ///<summary>
    ///Ñonstructorof statistics, we pass the number of sorting methods
    ///</summary>
    ///<param name="n"> - number of sorts </param>
    Statistic(int n) {  
        N = n;
        array = new double* [N];

        for (int i = 0; i < N; i++) {
            array[i] = new double[4]; 
        }
    }

    //Author - Bigun
    ///<summary>
    ///Method of obtaining statistical data
    ///</summary>
    ///<param name="a"> - link array </param>
    void sort_arrays(Array* a) { 
        for (int i = 0; i < N; i++) {  //Cycle for the number of sorting methods, in this case 2
        
            long long iterations = 0, comparisons = 0, reshuffle = 0;  //Variables for storing iterations, comparisons and permutations
            clock_t time1 = clock();  //Remember the time
            
            //Choose the sort method
            switch (i) {  
            
            //Bubble sorting method
            case 0:  
                cout << "\nBubble sort analysis\n";

                //If the size of the array is small (less than 20) then we will display the elements of the array on the screen before and after sorting with an iterator 
                if (a[i].Size() < 20) { 
                    cout << "Before\n";
                    a[i].print_array(); 
                }

                //Call the sort method and sort
                a[i].bubble_sort(iterations, comparisons, reshuffle);  

                if (a[i].Size() < 20) { 
                    cout << "\nAfter\n";
                    a[i].print_array(); 
                }
                cout << "\nBubble sort analysis done\n";
                break;

            //Shaker sortmethod
            case 1:  
                cout << "\nCocktail sort analysis\n";

                //If the size of the array is small (less than 20) then we will display the elements of the array on the screen before and after sorting with an iterator 
                if (a[i].Size() < 20) { 
                    cout << "Before\n"; 
                    a[i].print_array(); 
                }

                //Call the sort method and sort
                a[i].cocktail_sort(iterations, comparisons, reshuffle);  

                if (a[i].Size() < 20) { 
                    cout << "\nAfter\n"; 
                    a[i].print_array(); 
                }
                cout << "\nCocktail sort analysis done\n";
                break;

            //Selection sort method 
            case 2:  
                cout << "\nSelection sort analysis\n";

                if (a[i].Size() < 20) { 
                    cout << "Before\n"; 
                    a[i].print_array();  
                }  

                a[i].selection_sort(iterations, comparisons, reshuffle);

                if (a[i].Size() < 20) { 
                    cout << "\nAfter\n"; 
                    a[i].print_array(); 
                }
                cout << "\nSelection sort analysis done\n";
                break;

            //Insertion sort method 
            case 3:  
                cout << "\nInsertion sort analysis\n";

                if (a[i].Size() < 20) { 
                    cout << "Before\n"; 
                    a[i].print_array(); 
                }  

                a[i].insertion_sort(iterations, comparisons, reshuffle);

                if (a[i].Size() < 20) { 
                    cout << "\nAfter\n"; a[i].print_array(); 
                }
                cout << "\nInsertion sort analysis done\n";
                break;
            }

            clock_t time2 = clock();  //Look at the end time

            array[i][0] = (double)(time2 - time1) / CLOCKS_PER_SEC;  //The difference from the end time of sortingand the beginning is translated into secondsand saved in an array of indicators
            array[i][1] = iterations;  // Store iterations of iterations in an array    
            array[i][2] = comparisons;  //Store in an array indicators of comparisons
            array[i][3] = reshuffle;  //Store in an array indicators of permutations
        }
    }

    //Author - Bigun
    ///<summary>
    ///Method of deriving statistics
    ///</summary>
    void print_result() {  
    
        cout << '\n';
        cout << "                time|  iterations| comparsions|  reshuffles|\n";

        for (int i = 0; i < N; i++) {
        
            //Print the name of the method. Number of cases according to the number of sorting methods in the class (can be added)
            switch (i) {  
            
            case 0:
                cout << "Buble    ";
                break;

            case 1:
                cout << "Cocktail ";
                break;

            case 2:
                cout << "Selection";
                break;

            case 3:
                cout << "Insertion";
                break;
            }

            for (int j = 0; j < 4; j++)
                cout << setw(10) << setprecision(10) << array[i][j] << " | ";
            cout << '\n';
        }
    }
};