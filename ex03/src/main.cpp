#include "../Fixed.hpp"
#include "../Point.hpp"
#include <iostream>

bool    bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point   a(-1,0);
    Point   b(10, -30);
    Point   c(20,0);
    Point   point(10,15);

if(bsp(a, b, c, point) != false)
    std::cout << "dans le triangle" << std::endl;
else
    std::cout << "pas dans le triangle" << std::endl;
return 0;
}
