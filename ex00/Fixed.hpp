/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:19:24 by mstrauss          #+#    #+#             */
/*   Updated: 2024/09/24 17:17:32 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;
};

#endif