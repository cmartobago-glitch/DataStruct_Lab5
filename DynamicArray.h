#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>

class DynamicArray
{
private:
    int* data;
    std::size_t size;
    std::size_t capacity;

    void resize();

public:
    DynamicArray(std::size_t initialCapacity = 5);
    ~DynamicArray();

    bool add(int value);
    bool removeAt(std::size_t index);
    int find(int target) const;
    void print() const;

    std::size_t getSize() const;
    std::size_t getCapacity() const;
};

#endif