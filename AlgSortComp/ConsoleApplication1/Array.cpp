#include "Array.h"
#include <cstdlib>
#include <ctime>

Array::Array(size_t sz) : size(sz)
{
    data = new int[size];
}

Array::~Array()
{
    delete[] data;
}

int& Array::operator[](size_t index)
{
    return data[index];
}

size_t Array::getSize() const
{
    return size;
}

int* Array::getData() const
{
    return data;
}

void Array::fillRandom()
{
    for (size_t i = 0; i < size; ++i) 
    {
        data[i] = rand() % 100;
    }
}

void Array::print() const
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
