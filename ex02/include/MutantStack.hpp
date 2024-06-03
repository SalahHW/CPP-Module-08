/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:11:20 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/03 18:05:00 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		~MutantStack() {};
		MutantStack() : std::stack<T>() {};
		MutantStack(MutantStack<T> const &other) : std::stack<T>(other) {};
		MutantStack<T> &operator=(MutantStack<T> const &other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin() {
			return (this->c.begin());
		}
		iterator	end() {
			return (this->c.end());
		}
};

#endif
