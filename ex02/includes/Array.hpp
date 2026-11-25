#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        std::size_t _size;
        T* _array;
    public:
        Array() : _size(0), _array(NULL) {}
        Array(std::size_t n) : _size(n)
        {
            _array = new T[_size]();
        }

        Array(const Array &other)
         :_size(other._size)
        {
            _array = new T[_size];
            for (std::size_t i = 0; i < _size; i ++)
            {
                _array[i] = other._array[i];
            }
        }

        Array &operator=(const Array &other)
        {
            if (this != &other)
            {
                delete[] _array;

                _size = other._size;
                _array = new T[_size];

                for (std::size_t i = 0; i < _size; i++)
                {
                    _array[i] = other._array[i];
                }
            }
            return *this;
        }
        ~Array()
        {
            delete[] _array;
        }

        T& operator[](std::size_t index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }

        const T& operator[](std::size_t index) const
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }

        std::size_t size() const
        {
            return _size;
        }
};

#endif // ARRAY_H
