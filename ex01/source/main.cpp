/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:41:53 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/03 10:06:13 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	Span test(100000);
	Span test3(3);

	try
	{
		for (size_t i = 0; i < 100000; i++)
			test.addNumber(10);
		std::cout << test.longestSpan() << std::endl;
		Span test2(20);
		test2.addNumber(50);
		test2.addNumber(150);
		test2.addNumber(25);
		test2.addNumber(23);
		test2.addNumber(52);
		std::cout << test2.longestSpan() << std::endl;
		std::cout << test2.shortestSpan() << std::endl;
		// test3.addNumber(1);
		int range_arr[] = {1, 20, 3};
		std::vector<int> range(range_arr, range_arr + 3);
		test3.addNumber(range.begin(), range.end());
		test3.printSpan();
		std::cout << test3.longestSpan() << std::endl;
		std::cout << test3.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
