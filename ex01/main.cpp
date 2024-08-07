/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:09:11 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/07 13:18:56 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Span.hpp"

int	main()
{
	Span a(10);
	int	arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	a.addNumber(arr, arr + 10);
	return EXIT_SUCCESS;
}
