//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_CHARACTER_HPP
#define CPP_EX4_PARTA_CHARACTER_HPP


#include <iostream>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point &loc;
        int attack_points;
        string name;

    public:
        Character(string Name, Point &location);
        Character(Character& other);
        virtual ~Character();
        virtual bool isAlive();
        virtual double distance(Character* other);
        virtual void hit(int hitting_points);
        virtual string getName();
        virtual Point getLocation();
        virtual string print();
        Character& operator=(const Character& other);
    };
}

#endif // CPP_EX4_PARTA_CHARACTER_HPP
