#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;

public:
    Fixed   getX( void ) const;
    Fixed   getY( void ) const;

    Point( void );
    ~Point();
    Point(const float x, const float y);
    Point(Point& other);
    Point&  operator=(Point& other);

};

#endif