#include "iter.hpp"
#include <iostream>

void int_test(int& value)
{
    value += 10;
}

void long_test_non_const(long& value)
{
    value *= 2;
}

void long_test_const(const long& value)
{
    std::cout << value << " ";
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

    // Test the Array class with long integers non-const references and const references
    long arr_long[] ={10L, 20L, 30L, 40L, 50L};
    std::size_t length_long = sizeof(arr_long) / sizeof(arr_long[0]);

    std::cout << "long array with print_element: ";
    iter(arr_long, length_long, print_element<long>);
    std::cout << std::endl;

    std::cout << "long array with long_test (non-const): ";
    iter(arr_long, length_long, long_test_non_const);
    iter(arr_long, length_long, print_element<long>);
    std::cout << std::endl;

    std::cout << "long array with long_test_const: ";
    iter(arr_long, length_long, long_test_const);
    std::cout << std::endl;

    return 0;
}

