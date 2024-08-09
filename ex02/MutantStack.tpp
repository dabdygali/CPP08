/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:48:10 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/09 08:18:27 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _MUTANTSTACK_TPP_
	#define _MUTANTSTACK_TPP_

	// Constructors
	template <typename T>
	MutantStack<T>::MutantStack() : std::stack<T>()
	{
	}

	template <typename T>
	MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src)
	{
	}

	template <typename T>
	MutantStack<T>::~MutantStack()
	{
	}

	template <typename T>
	MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	}

	template <typename T>
	typename MutantStack<T>::iterator	MutantStack<T>::begin( void )
	{
		return std::stack<T>::c.begin();
	}

	template <typename T>
	typename MutantStack<T>::const_iterator	MutantStack<T>::begin( void ) const
	{
		return std::stack<T>::c.begin();
	}

	template <typename T>
	typename MutantStack<T>::iterator	MutantStack<T>::end( void )
	{
		return std::stack<T>::c.end();
	}

	template <typename T>
	typename MutantStack<T>::const_iterator	MutantStack<T>::end( void ) const
	{
		return std::stack<T>::c.end();
	}
	
#endif
