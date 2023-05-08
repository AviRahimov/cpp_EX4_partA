//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_POINT_HPP
#define CPP_EX4_PARTA_POINT_HPP

namespace ariel
{
    class Point
    {
    private:
        // The location of the point represeted by x and y
        double x_axis, y_axis;

    public:
        // Inittializer constructor that take x and y as arguments
        Point(double new_x, double new_y);
        double distance(Point &other);
        void print();
        static Point moveTowards(Point &src, Point &dest, double dist);
    };
}

#endif // CPP_EX4_PARTA_POINT_HPP
