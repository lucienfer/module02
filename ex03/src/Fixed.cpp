#include "../Fixed.hpp"
#include <cmath>

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
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

/*-----------Arithmetic operators-----------*/

Fixed  Fixed::operator+(const Fixed& other) const {
    return (Fixed(toFloat() + other.toFloat()));
}

Fixed  Fixed::operator-(const Fixed& other) const {
    return (Fixed(toFloat() - other.toFloat()));
}

Fixed  Fixed::operator*(const Fixed& other) const {
    return (Fixed(toFloat() * other.toFloat()));
}

Fixed  Fixed::operator/(const Fixed& other) const {
    return (Fixed(toFloat() / other.toFloat()));
}

/*------------------------------------------*/

/*-----------Comparison operators-----------*/

bool   Fixed::operator<(const Fixed& other) {
    return (fixedIntegrer < other.getRawBits());
}

bool   Fixed::operator>(const Fixed& other) {
    return (fixedIntegrer > other.getRawBits());
}

bool   Fixed::operator>=(const Fixed& other) {
    return (fixedIntegrer >= other.getRawBits());
}

bool   Fixed::operator<=(const Fixed& other) {
    return (fixedIntegrer <= other.getRawBits());
}

bool   Fixed::operator!=(const Fixed& other) {
    return (fixedIntegrer < other.getRawBits());
}

bool   Fixed::operator==(const Fixed& other) {
    return (fixedIntegrer < other.getRawBits());
}

/*------------------------------------------*/

/*-incrementation & decrementation operator-*/

Fixed&   Fixed::operator++( void ) {
    ++fixedIntegrer;
    return (*this);
}

Fixed   Fixed::operator++( int ) {
    Fixed   tmp = *this;
    ++fixedIntegrer;
    return (tmp);
}

Fixed&   Fixed::operator--( void ) {
    --fixedIntegrer;
    return (*this);
}

Fixed   Fixed::operator--( int ) {
    Fixed   tmp = *this;
    --fixedIntegrer;
    return (tmp);
}

/*------------------------------------------*/

Fixed    Fixed::min(Fixed& f1, Fixed& f2) {
    if (f1 < f2)
        return (f1);
    else
        return (f2);
}

const Fixed    Fixed::min(const Fixed& f1, const Fixed& f2) {
    if (f1.getRawBits() < f2.getRawBits())
        return (f1);
    else
        return (f2);
}

Fixed    Fixed::max(Fixed& f1, Fixed& f2) {
    if (f1 > f2)
        return (f1);
    return (f2);
}

const Fixed    Fixed::max(const Fixed& f1, const Fixed& f2) {
    if (f1.getRawBits() > f2.getRawBits())
        return (f1);
    else
        return (f2);
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
