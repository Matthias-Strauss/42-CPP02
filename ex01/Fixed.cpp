/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:27:11 by mstrauss          #+#    #+#             */
/*   Updated: 2024/09/24 17:43:30 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
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

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
