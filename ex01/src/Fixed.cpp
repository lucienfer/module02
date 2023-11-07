#include "../Fixed.hpp"
#include <cmath>

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedIntegrer);
}

void    Fixed::setRawBits( int const raw ) {
    fixedIntegrer = raw;
    return ;
}

Fixed::Fixed(void) : fixedIntegrer(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed& other) : fixedIntegrer(0) {
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(other.getRawBits());
    return ;
}

Fixed::Fixed(const int nb) : fixedIntegrer(nb << frac) {
    std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const float nbf) : fixedIntegrer(roundf(nbf * ( 1 << frac))) {
    std::cout << "Float constructor called" << std::endl;
    return ;
}

Fixed&  Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(other.getRawBits());
    return (*this);
}

float   Fixed::toFloat( void ) const {
    return (((float)fixedIntegrer) / (1 << frac));
}

int     Fixed::toInt( void ) const {
    return (fixedIntegrer >> frac);
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return (o);
}
