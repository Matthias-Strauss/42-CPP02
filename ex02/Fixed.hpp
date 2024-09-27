/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:19:24 by mstrauss          #+#    #+#             */
/*   Updated: 2024/09/24 18:11:44 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	/* ------------------------------- Constructor ------------------------------ */
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);

	/* ------------------------------- Destructor ------------------------------- */
	~Fixed(void);

	/* ------------------------------- Conversion ------------------------------- */
	float toFloat(void) const;
	int toInt(void) const;

	/* ------------------------------- Getters/Setters --------------------------- */
	int getRawBits(void) const;
	void setRawBits(int const raw);

	/* -------------------------------------------------------------------------- */
	/*                              Operator Overload                             */
	/* -------------------------------------------------------------------------- */
	/* ------------------------------- Comparison ------------------------------- */
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	/* ------------------------------- Arithmetic ------------------------------- */
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	/* --------------------------- Increment/Decrement -------------------------- */
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif