/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:51 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/08 14:58:05 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include "Span.hpp"

// Constructors
Span::Span() : _capacity(0), _currentSize(0)
{
	_currentEnd = _container.begin();
}

Span::Span(unsigned int capacity) : _capacity(capacity), _currentSize(0), _container(capacity)
{
	_currentEnd = _container.begin();
}

Span::Span(const Span &src) : _capacity(src._capacity), _currentSize(src._currentSize), _container(src._container)
{
	_currentEnd = _container.begin();
	std::advance(_currentEnd, _currentSize);
}

// Destructors
Span::~Span()
{
}

// Operators
Span	&Span::operator=(const Span &rhs)
{
	_container = rhs._container;
	_capacity = rhs._capacity;
	_currentSize = rhs._currentSize;
	_currentEnd = _container.begin();
	std::advance(_currentEnd, _currentSize);
	return *this;
}

// Exception classes
const char	*Span::SpanFullException::what( void ) const throw()
{
	return "Span is full";
}

const char	*Span::SpanNotEnoughCapacity::what( void ) const throw()
{
	return "Span has not enough capacity";
}

const char	*Span::SpanNotEnoughElements::what( void ) const throw()
{
	return "Span has not enough elements";
}

// Helpers
unsigned int	calcSpan(int a, int b)
{
	if (b >= a)
		return b - a;
	return a - b;
}

void	printList(const std::list<int> &lst)
{
	std::list<int>::const_iterator	it = lst.begin();
	while (it != lst.end())
	{
		std::cout << *it << ", ";
		it++;
	}
	std::cout << std::endl;
}

// Actions
void	Span::addNumber(int value)
{
	if (_currentSize >= _capacity)
		throw SpanFullException();
	*_currentEnd = value;
	_currentSize++;
	std::advance(_currentEnd, 1);
}

unsigned int	Span::shortestSpan( void ) const
{
	if (_currentSize < 2)
		throw SpanNotEnoughElements();
	std::list<int>				tmp(_container.begin(), static_cast<std::list<int>::const_iterator>(_currentEnd));
	std::list<unsigned int>		spansList(_currentSize - 1);
	tmp.sort();
	std::transform(tmp.begin(), tmp.end(), ++tmp.begin(), spansList.begin(), calcSpan);
	return *std::min_element(spansList.begin(), spansList.end());
}

unsigned int	Span::longestSpan( void ) const
{
	if (_currentSize < 2)
		throw SpanNotEnoughElements();
	std::list<int>	tmp(_container.begin(), static_cast<std::list<int>::const_iterator>(_currentEnd));
	tmp.sort();
	return *(--tmp.end()) - *tmp.begin();
}
