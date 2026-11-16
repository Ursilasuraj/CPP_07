#include <iostream>
#include "iter.hpp"

template <typename T>

void print (const T& value)
{
    std::cout << value << std::endl;
}

void iter(int *array, size_t length, void (*func)(const int&))
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};

    iter(numbers, 5, print<int>);

    return 0;
}