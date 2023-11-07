#include "../Fixed.hpp"
#include <iostream>

int Fixed::getRawBits(void) const {
    std::cout << "# getRawBits member function called #" << std::endl;
    return (fixedIntegrer);
}

void    Fixed::setRawBits( int const raw ) {
    fixedIntegrer = raw;
    return ;
}

Fixed::Fixed(void) : fixedIntegrer(0) {
    std::cout << "# Default constructor called #" << std::endl;
    return ;
}

Fixed::~Fixed() {
    std::cout << "| Destructor called |" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed& other) : fixedIntegrer(0) {
    std::cout << "# Copy constructor called #" << std::endl;
    setRawBits(other.getRawBits());
    return ;
}

Fixed&  Fixed::operator=(const Fixed& other) {
    setRawBits(other.getRawBits());
    return (*this);
}
