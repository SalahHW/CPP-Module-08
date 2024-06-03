/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:41:46 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/03 09:55:24 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "vector"
# include <algorithm>
# include <climits>
# include <exception>
# include <vector>

class Span
{
public:
	~Span();
	Span(Span const &);
	Span &operator=(Span const &);

	Span(unsigned int);

	void	addNumber(int number);
	void	addNumber(std::vector<int>::const_iterator const &, std::vector<int>::const_iterator const &);
	int		shortestSpan() const;
	int		longestSpan() const;
	void	printSpan() const;
	
private:
	Span();
	unsigned int		N;
	std::vector<int>	numbers;

	class FullSpan : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class EmptySpan : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif
