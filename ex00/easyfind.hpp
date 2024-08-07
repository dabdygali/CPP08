/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:11:44 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/05 12:59:55 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _EASYFIND_HPP_
	#define _EASYFIND_HPP_
	
	template <typename InputOperator, typename T>
	InputOperator	easyfind(T &container, int val);
	
	#include "easyfind.tpp"
	
#endif
