/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:48:10 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/16 12:30:52 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ITER_HPP
#define  ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void print_element(const T& value)
{
    std::cout << value << " ";
}
// Prints one array element without modifying it.

template <typename T, typename F>
void iter(T* array, const std::size_t length, F function)
{
    for (std::size_t i = 0; i < length; ++i)
        function(array[i]);
}
// Calls the supplied function once for every element in the array.

#endif 