/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:43:27 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/08 14:44:23 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SPAN_HPP_
	#define _SPAN_HPP_

	#include <list>
	#include <exception>
	#include <limits>
	#include <iterator>
	#include <stdexcept>

	class	Span
	{
		private:
			unsigned int				_capacity;
			unsigned int				_currentSize;
			std::list<int>				_container;
			std::list<int>::iterator	_currentEnd;
			
		public:
			// Constructors
			Span();
			Span(unsigned int capacity);
			Span(const Span &src);

			// Destrcutors
			virtual ~Span();

			// Operators
			Span	&operator=(const Span &rhs);

			// Exception classes
			class	SpanFullException : public std::exception
			{
				public:
					const char	*what() const throw();
			};
			
			class	SpanNotEnoughCapacity : public std::exception
			{
				public:
					const char	*what() const throw();
			};

			class	SpanNotEnoughElements : public std::exception
			{
				public:
					const char	*what() const throw();
			};

			// Actions
			void			addNumber(int value);
			template <typename InputIterator>
			void			addNumber(InputIterator first, InputIterator last);
			unsigned int	shortestSpan( void ) const;
			unsigned int	longestSpan( void ) const;
	};

	template <typename InputIterator>
	void	Span::addNumber(InputIterator first, InputIterator last)
	{
		typename std::iterator_traits<InputIterator>::difference_type	dist;
		
		dist = std::distance(first, last);
		if (dist < 0)
			throw std::invalid_argument("Span bulk insert: Range distance is negative");
		if (dist > static_cast<typename std::iterator_traits<InputIterator>::difference_type>(std::numeric_limits<unsigned int>::max()))
			throw SpanNotEnoughCapacity();
		if ((_capacity - _currentSize) < static_cast<unsigned int>(dist))
			throw SpanNotEnoughCapacity();
		while (first != last)
		{
			*_currentEnd = *first;
			first++;
			_currentEnd++;
			_currentSize++;
		}
	}
#endif
