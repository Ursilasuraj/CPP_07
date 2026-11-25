#include "../includes/Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "Default constructor test" << std::endl;

    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    std::cout << "Array with " << MAX_VAL << " elements test" << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
   
    std::srand(std::time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //copy constructor test
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete [] mirror;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
    delete [] mirror;//

    std::cout << "\n Assignation operator test" << std::endl;

    Array<int>a(5);

    for (unsigned int i = 0; i < a.size(); i++)
    {
        a[i] = i * 10;
    }
    Array<int>b;
    
    b = a;

    b[0] = 999;

    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;

    if (a[0] != b[0])
    {
        std::cout << "Deep copy Assignation operator works correctly!" << std::endl;
    }
    else
    {
        std::cout << "Assignation operator failed!" << std::endl;
    }
    std::cout << "\n Copy constructor test" << std::endl;   

    Array<int> original(3);

    original[0] = 1;
    original[1] = 2;
    original[2] = 3;

    Array<int> copy(original);

    copy[1] = 42;
    std::cout << "original[1] = " << original[1] << std::endl;
    std::cout << "copy[1] = " << copy[1] << std::endl;

    if (original[1] != copy[1])
        std::cout << "Deep copy Copy constructor works correctly!" << std::endl;
    else
        std::cout << "Copy constructor failed!" << std::endl;

    std::cout << "\n Size test" << std::endl;

    std::cout << "numbers.size() = " << numbers.size() << std::endl;
    std::cout << "a.size() = " << a.size() << std::endl;
    std::cout << "empty.size() = " << empty.size() << std::endl;
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

