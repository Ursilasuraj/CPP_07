#include "iter.hpp"
#include <iostream>

void int_test(int& value)
{
    value += 10;
}



int main()
{
    // Test the Array class with integers
    int arr_int[] = {1, 2, 3, 4, 5};
    std::size_t length = sizeof(arr_int) / sizeof(arr_int[0]);

    std::cout << "Before int_test: ";
    iter(arr_int, length, print_element<int>);
    std::cout << std::endl;

    iter(arr_int, length, int_test);

    std::cout << "After int_test: ";
    iter(arr_int, length, print_element<int>);
    std::cout << std::endl;

    // Test the Array class with long integers const references
    long arr_long[] ={10L, 20L, 30L, 40L, 50L};
    std::size_t length_long = sizeof(arr_long) / sizeof(arr_long[0]);


    return 0;
}

