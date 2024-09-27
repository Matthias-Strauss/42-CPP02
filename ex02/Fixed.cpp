/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:27:11 by mstrauss          #+#    #+#             */
/*   Updated: 2024/09/24 18:16:04 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */
/*                                Copy Operator                               */
/* -------------------------------------------------------------------------- */

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointValue = src.getRawBits();
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                                Deconstructor                               */
/* -------------------------------------------------------------------------- */

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                 Conversions                                */
/* -------------------------------------------------------------------------- */

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
}

/* -------------------------------------------------------------------------- */
/*                             Getters and Setters                            */
/* -------------------------------------------------------------------------- */

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

/* -------------------------------------------------------------------------- */
/*                             Operator Overloads                             */
/* -------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

/* -------------------------- Comparison Operators -------------------------- */

bool Fixed::operator>(const Fixed &other) const
{
	return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_fixedPointValue != other._fixedPointValue;
}

/* -------------------------- Arithmetic Operators -------------------------- */

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

/* --------------------- Increment / Decrement Operators -------------------- */

Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedPointValue++;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedPointValue--;
	return temp;
}

/* -------------------------------------------------------------------------- */
/*                               Static Methods                               */
/* -------------------------------------------------------------------------- */

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}