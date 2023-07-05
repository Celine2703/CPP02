#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = obj.getRawBits();
	// *this = obj;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bits;
}

/* pour decaller de 3 bits (*2^3)
11101011.000
01011000
*/

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bits)); // 1 << this->bits == 2^8 == 256 c'est puissance de 2
}

// value est un float et le decalage se fait avec int

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->value = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << this->bits)); // on shift a gauche puis on deplace la virgule
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->bits); // on shift a droite
}

/*
11101011.000
01011000
00001011
*/

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}