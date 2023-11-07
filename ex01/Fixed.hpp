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
    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif