/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:52:49 by sbouheni          #+#    #+#             */
/*   Updated: 2024/05/31 17:17:03 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <deque>
#include <list>
#include <vector>

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> numbers(arr, arr + 5);

	std::deque<int> numbers_deque;
	numbers_deque.push_back(1);
	numbers_deque.push_back(25);
	numbers_deque.push_back(42);
	numbers_deque.push_back(21);

	std::list<int> numbers_list(arr, arr + 5);

	try
	{
		easyfind(numbers, 5);
		std::cout << "Value found" << std::endl;
		easyfind(numbers_deque, 42);
		std::cout << "Value found" << std::endl;
		easyfind(numbers_list, 18);
		std::cout << "Value found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found int the container" << std::endl;
	}
	return (0);
}
