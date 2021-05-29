#include "Array.h"
#include "Statistics.h"
using namespace std;

//Author - Hnybidenko
///<summary>
///Check the entered data for correctness. Only numeric values ​​need to be entered
///</summary>
///<param name="value"> - verified value </param>
void get_correct_input(int& value) {
    cin >> value;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please try again: ";
        cin >> value;
    }
}

int main()
{
    srand(time(NULL));  //Run the randomizer
    const int NumberOfSortType = 2;  //Number of sorting methods
    Statistic analysis(NumberOfSortType);  //Statistics class variable. We pass it the number of sorting methods
    Array arrayToSort[NumberOfSortType];  //Сreate an array of arrays of our class
    int arraySize = 0, choice;  //Variable to store the size of the array and our selection

    //Loop in which we ask what the user wants and react accordingly to his choice
    do {
        //Loop in which we ask how to fill an array with zeros or random numbers
        do {
            cout << endl;
            cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
            cout << " * Enter the desired option for filling the array:   *" << endl;
            cout << " *\t1 - Fill with zero values                    *" << endl;
            cout << " *\t2 - Fill with random values                  *" << endl;
            cout << " *\t0 - Exit                                     *" << endl;
            cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
            cout << "\t\t\t\t        Your choice: ";

            get_correct_input(choice);  //Check the entered value
        } while (choice < 0 || choice > 2);  //Repeat the loop until you enter incorrect values

         //If the choice is not zero then ask the size of the array
        if (choice > 0) {
            do {
                cout << "Input array size: ";
                get_correct_input(arraySize);
            } while (arraySize < 1);  //Repeat the loop until you enter incorrect values
        }

        //Call the constructor with a range of random numbers (if you choose a zero array, then 500 * (1-1) will give 0, and the array will be filled with zeros)
        Array blank(arraySize, 500 * (choice - 1));

        //Array blank(arraySize);  //Uncomment the line to enter the array yourself, and comment on the previous one

        //Fill in our array of arrays, an array (blank) which we created
        for (int i = 0; i < NumberOfSortType; i++)
            arrayToSort[i] = blank;  //blank - this is a change in our class, it was created to then fill our array of arrays so that they are the same

        //Depending on the user's choice, we display what he chose
        switch (choice) {
        case 0:
            cout << "Exit\n";
            break;

        case 1:
            cout << "Zero array analysis: " << endl;
            break;

        case 2:
            cout << "Random array analysis: " << endl;
            break;
        }

        //If the user chose not to exit the program
        if (choice > 0) {
            analysis.sort_arrays(arrayToSort);  //Let's delete our arrays, for this purpose in the method of a class Statistics we transfer links to our arrays
            analysis.print_result();  //Print the sort result
            cout << "\nMinimal and Maximal elements are :" << arrayToSort[0].Min() << "  " << arrayToSort[0].Max() << "\n\n\n";  //Print the maximum and minimum elements of the array
        }
    } while (choice != 0);  //Until the user enters 0 (exit the program), repeat its operation

    //system("pause");
    return 0;
}

// Run programs: CTRL + F5 or menu "Debug"> "Run without debugging"
// Debug programs: F5 or menu "Debug"> "Start Debugging"
