#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);

		Fixed	&operator=(const Fixed &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					value;
		static const int	bits = 8;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs);

#endif