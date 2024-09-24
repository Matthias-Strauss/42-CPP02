/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:27:11 by mstrauss          #+#    #+#             */
/*   Updated: 2024/09/24 17:18:25 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _fixedPointValue(src._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}
