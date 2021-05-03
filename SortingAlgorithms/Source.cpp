#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <typeinfo>
#include "Array.cpp"
#include "Statistic.cpp"

using namespace std;

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
            cout << "¬ведите размер массива: ";
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

