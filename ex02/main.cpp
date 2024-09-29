/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:18:47 by mstrauss          #+#    #+#             */
/*   Updated: 2024/09/29 22:54:35 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "ADDITIONAL TESTS" << std::endl;
	std::cout << "The bigger value of " << a << " and " << b << " is:" << Fixed::max(a, b) << std::endl;
	std::cout << "The smaller value of " << a << " and " << b << " is:" << Fixed::min(a, b) << std::endl;
	std::cout << std::endl;
	std::cout << "The product of " << a << " and " << b << " is:" << a * b << std::endl;
	std::cout << "The subtraction of " << a << " - " << b << " is:" << a - b << std::endl;
	std::cout << "The division of " << a << " / " << b << " is:" << a / b << std::endl;
	std::cout << "The sum of " << a << " + " << b << " is:" << a + b << std::endl;
	return 0;
}