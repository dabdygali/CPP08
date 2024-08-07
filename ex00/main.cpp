/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:08:05 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/05 14:30:11 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int	main()
{
	int					arr[5] = {1, 2, 3, 4, 5};
	size_t				arr_size = sizeof(arr)/sizeof(int);
	std::vector<int>	vec(arr, arr + arr_size);
	std::list<int>		ilist(arr, arr + arr_size);
	std::deque<int>		ideq(arr, arr + arr_size);
	int					toFind = 3;
	int					notAvail = -10;
	size_t				i = 0;

	// Intro
	std::cout << "The Array: ";
	while (i < arr_size)
	{
		std::cout << arr[i] << ' ';
		i++;
	}
	std::cout << std::endl;
	std::cout << "The value to find: " << toFind << std::endl;
	std::cout << "The missing value: " << notAvail << std::endl;
	
	// Vector
	std::cout << std::endl;
	std::cout << "--------Vector------" << std::endl;
	std::cout << "Found value: " << *easyfind(vec, toFind) << std::endl;
	std::cout << "Missing value: ";
	if (easyfind(vec, notAvail) == vec.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << *easyfind(vec, notAvail) << std::endl;
	
	// List
	std::cout << std::endl;
	std::cout << "--------List------" << std::endl;
	std::cout << "Found value: " << *easyfind(ilist, toFind) << std::endl;
	std::cout << "Missing value: ";
	if (easyfind(ilist, notAvail) == ilist.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << *easyfind(ilist, notAvail) << std::endl;

	// Deque
	std::cout << std::endl;
	std::cout << "--------Deque------" << std::endl;
	std::cout << "Found value: " << *easyfind(ideq, toFind) << std::endl;
	std::cout << "Missing value: ";
	if (easyfind(ideq, notAvail) == ideq.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << *easyfind(ideq, notAvail) << std::endl;
	return EXIT_SUCCESS;
}
