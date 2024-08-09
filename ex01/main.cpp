/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:09:11 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/08 15:13:38 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include "Span.hpp"

int	main()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	
	try
	{
		sp.addNumber(5);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "----------------------------" << std::endl;

	
	std::vector<int>	v;
	Span				sp2(20000);

	srand(time(NULL));
	int	i = 0;
	while (i < 20000)
	{
		v.push_back(rand() - RAND_MAX/2);
		i++;
	}
	sp2.addNumber(v.begin(), v.end());
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

	return EXIT_SUCCESS;
}
