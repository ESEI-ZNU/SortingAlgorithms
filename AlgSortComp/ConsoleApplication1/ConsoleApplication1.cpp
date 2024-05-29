#include <iostream>
#include <array>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// Class to represent a dynamic array
class Array
{
private:
    int* data;   // Pointer to the data array
    size_t size; // Size of the array

public:
    // Constructor to initialize the array with a given size
    Array(size_t sz) : size(sz)
    {
        data = new int[size];
    }

    // Destructor to free the allocated memory
    ~Array()
    {
        delete[] data;
    }

    // Overload the subscript operator for array access
    int& operator[](size_t index)
    {
        return data[index];
    }

    // Get the size of the array
    size_t getSize() const
    {
        return size;
    }

    // Get the pointer to the data array
    int* getData() const
    {
        return data;
    }

    // Fill the array with random numbers between 0 and 99
    void fillRandom()
    {
        for (size_t i = 0; i < size; ++i) {
            data[i] = rand() % 100;
        }
    }

    // Print the contents of the array
    void print() const
    {
        for (size_t i = 0; i < size; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{   

    return 0;
}
