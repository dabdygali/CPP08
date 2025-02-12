/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:51:33 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/05 13:41:10 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _EASYFIND_TPP_
	#define _EASYFIND_TPP_

	#include <algorithm>
	
	template <typename T>
	typename T::iterator	easyfind(T &container, int val)
	{
		return std::find(container.begin(), container.end(), val);
	}
#endif
