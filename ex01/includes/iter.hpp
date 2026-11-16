/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:48:10 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/16 17:08:12 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ITER_HPP
#define  ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void print_element(const T& element)
{
    std::cout << element << " ";
}

template <typename T>
void iter(T *array, std::size_t length, void (*func)(T &))
{
	// std::cout << "\nTemplate non-const called" << std::endl;
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

template <typename T>
void iter(const T *array, std::size_t length, void (*func)(const T &))
{
	// std::cout << "\nTemplate const called" << std::endl;
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

// Calls the supplied function once for every element in the array.
template <typename T>
void print_elememts(T* array, const std::size_t length)
{
    iter(array, length, print_element<T>);
}

#endif 