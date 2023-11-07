#include "../Point.hpp"

Fixed   Point::getX( void ) const {
    return (x);
}

Fixed   Point::getY( void ) const {
    return (y);
}

Point::Point( void ) : x(0), y(0) {
    return ;
}

Point::Point(const float x, const float y) : x(x), y(y) {
    return ;
}

Point::Point(Point& other) : x(other.getX()), y(other.getY()) {
    return ;
}

Point::~Point( void ) {
    return ;
}

Point&  Point::operator=(Point& other) {
    if (this != &other) {
        (Fixed) x = other.getX();
        (Fixed) y = other.getY();
    }
    return (*this);
}
