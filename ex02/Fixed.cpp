#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
}

Fixed::Fixed(Fixed const &obj)
{
	this->value = obj.getRawBits();
	// *this = obj;
}

Fixed::Fixed(const int value)
{
	this->value = value << this->bits;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << this->bits)); // 1 << this->bits == 2^8 == 256 c'est puissance de 2
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	if (this == &rhs)
		return (*this);
	this->value = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << this->bits));
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

Fixed::~Fixed(void)
{
}

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->value > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->value < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->value >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->value <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->value == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->value != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	tmp;

	tmp.setRawBits(this->value + rhs.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	tmp;

	tmp.setRawBits(this->value - rhs.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	tmp;

	tmp.setRawBits((this->value * rhs.getRawBits()) >> this->bits);
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	tmp;

	tmp = Fixed(this->toFloat() / rhs.toFloat());
	return (tmp);
}

Fixed	&Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->value++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->value--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}
