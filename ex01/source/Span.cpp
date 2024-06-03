/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:41:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/03 09:59:15 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <iterator>

Span::~Span() {}

Span::Span() {}

Span::Span(Span const &other)
{
	N = other.N;
	numbers = other.numbers;
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}
	return (*this);
}

Span::Span(unsigned int N) : N(N) {}

void Span::addNumber(int number)
{
	if (numbers.size() >= N)
		throw Span::FullSpan();
	numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::const_iterator const &start, std::vector<int>::const_iterator const &end)
{
	size_t elements_count;
	size_t new_elements_count;

	new_elements_count = std::distance(start, end);
	elements_count = numbers.size();
	if (elements_count + new_elements_count > N)
		throw Span::FullSpan();
	numbers.insert(numbers.end(), start, end);	
}

int	Span::shortestSpan() const
{
	if (numbers.size() <= 1)
		throw EmptySpan();
	int shortest_span = INT_MAX;
	std::vector<int> sorted_numbers(numbers);
	std::sort(sorted_numbers.begin(), sorted_numbers.end());
	for (size_t i = 1; i < sorted_numbers.size(); i++)
	{
		int current_span = sorted_numbers[i] - sorted_numbers[i - 1];
		if (current_span < shortest_span)
			shortest_span = current_span;
	}
	return (shortest_span);
}

int Span::longestSpan() const
{
	if (numbers.size() <= 1)
		throw EmptySpan();
	int longest_span = 0;
	std::vector<int>::const_iterator smallestIt;
	std::vector<int>::const_iterator greatestIt;
	smallestIt = std::min_element(numbers.begin(), numbers.end());
	greatestIt = std::max_element(numbers.begin(), numbers.end());

	longest_span = *greatestIt - *smallestIt;
	return (longest_span);
}

void Span::printSpan() const
{
	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << "'" << numbers[i] << "'" << std::endl;
}

const char *Span::FullSpan::what() const throw() 
{
	return ("Span can't store more value");
}

const char *Span::EmptySpan::what() const throw() 
{
	return ("Span doesn't have enough value");
}


