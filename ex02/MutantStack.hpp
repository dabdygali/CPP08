/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:51:20 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/08 16:53:48 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _MUTANTSTACK_HPP_
	#define _MUTANTSTACK_HPP_

	#include <stack>

	template <typename T>
	class	MutantStack : public std::stack<T>
	{
		public:
			// Constructors
			MutantStack();
			MutantStack(const MutantStack &src);

			// Destructors
			virtual ~MutantStack();

			// Operators
			MutantStack	&operator=(const MutantStack &rhs);

			// Iterators
			typedef typename std::stack<T>::container_type::iterator			iterator;
			typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
			iterator		begin( void );
			const_iterator	begin( void ) const;
			iterator		end( void );
			const_iterator	end( void ) const;
	};
	
	#include "MutantStack.tpp"
	
#endif
