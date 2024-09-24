/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:19:24 by mstrauss          #+#    #+#             */
/*   Updated: 2024/09/24 17:37:28 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);

	~Fixed(void);

	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif