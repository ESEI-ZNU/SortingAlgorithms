#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array
{
private:
    int* data;   // Pointer to the data array
    size_t size; 

public:
    Array(size_t sz);

    ~Array();

    // Overload the subscript operator for array access
    int& operator[](size_t index);

    size_t getSize() const;

    int* getData() const;

    void fillRandom();

    void print() const;
};

#endif 
