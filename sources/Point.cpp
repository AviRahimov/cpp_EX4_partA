#include "Point.hpp"
using namespace ariel;

Point::Point(double new_x, double new_y) : x_axis(new_x), y_axis(new_y)
{
}

double Point::distance(Point &other)
{
    return 0;
}

void Point::print()
{
    return;
}

Point Point::moveTowards(Point &src, Point &dest, double dist)
{
    return Point(0, 0);
}