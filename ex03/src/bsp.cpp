#include "../Fixed.hpp"
#include "../Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed   alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) /
                  ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
    Fixed   beta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) /
                  ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
    float   gamma = 1.0 - alpha.toFloat() - beta.toFloat();
    return (alpha.toFloat() >= 0 && beta.toFloat() >= 0 && gamma >= 0);
}
