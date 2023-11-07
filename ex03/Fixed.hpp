#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
private:

    int fixedIntegrer;
    static int const    frac = 8;

public:
    int getRawBits( void ) const;
    void    setRawBits( int const raw );
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed(const int nb);
    Fixed(const float nbf);

    Fixed&  operator=(const Fixed& other);
    Fixed   operator+(const Fixed& other) const;
    Fixed   operator-(const Fixed& other) const;
    Fixed   operator*(const Fixed& other) const;
    Fixed   operator/(const Fixed& other) const;

    bool   operator<(const Fixed& other);
    bool   operator>(const Fixed& other);
    bool   operator>=(const Fixed& other);
    bool   operator<=(const Fixed& other);
    bool   operator!=(const Fixed& other);
    bool   operator==(const Fixed& other);

    Fixed  operator++(int); //post
    Fixed&  operator++( void ); //pre
    Fixed  operator--(int);
    Fixed&  operator--( void );

    static Fixed    min(Fixed& f1, Fixed& f2);
    static const Fixed    min(const Fixed& f1, const Fixed& f2);
    static Fixed    max(Fixed& f1, Fixed& f2);
    static const Fixed    max(const Fixed& f1, const Fixed& f2);

    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif