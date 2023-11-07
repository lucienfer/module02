#ifndef FIXED_H
# define FIXED_H

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
    Fixed   &operator=(const Fixed& other);
};

#endif
