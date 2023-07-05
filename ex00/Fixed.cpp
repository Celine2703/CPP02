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

Fixed	&Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->value = obj.getRawBits();
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

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}