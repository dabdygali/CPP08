/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:51 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/07 13:58:08 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
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

void	Span::addNumber(int value)
{
	if (_currentSize >= _capacity)
		throw SpanFullException();
	*_currentEnd = value;
	_currentSize++;
	_currentEnd++;
}

int	Span::shortestSpan( void ) const
{
	if (_currentSize < 2)
		throw SpanNotEnoughElements();
	std::list<int>	tmp(_container);
	tmp.sort();
}
