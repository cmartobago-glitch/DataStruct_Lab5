#include "DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray(size_t initialCapacity)
{
    if (initialCapacity == 0)
    {
        initialCapacity = 5;
    }

    capacity = initialCapacity;
    size = 0;
    data = new int[capacity];
}

DynamicArray::~DynamicArray()
{
    delete[] data;
    data = nullptr;
}

void DynamicArray::resize()
{
    size_t newCapacity = capacity * 2;

    int* temp = new int[newCapacity];

    for (size_t i = 0; i < size; ++i)
    {
        temp[i] = data[i];
    }

    delete[] data;

    data = temp;
    capacity = newCapacity;
}

bool DynamicArray::add(int value)
{
    if (size >= capacity)
    {
        resize();
    }

    data[size] = value;
    ++size;

    return true;
}

bool DynamicArray::removeAt(size_t index)
{
    if (index >= size)
    {
        cout << "Invalid index!" << endl;
        return false;
    }

    for (size_t i = index; i < size - 1; ++i)
    {
        data[i] = data[i + 1];
    }

    --size;

    return true;
}

int DynamicArray::find(int target) const
{
    for (size_t i = 0; i < size; ++i)
    {
        if (data[i] == target)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

void DynamicArray::print() const
{
    if (size == 0)
    {
        cout << "Current List Contents: Empty" << endl;
        return;
    }

    cout << "Current List Contents: ";

    for (size_t i = 0; i < size; ++i)
    {
        cout << data[i] << " ";
    }

    cout << endl;
}

size_t DynamicArray::getSize() const
{
    return size;
}

size_t DynamicArray::getCapacity() const
{
    return capacity;
}