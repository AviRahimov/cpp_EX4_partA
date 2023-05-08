//
// Created by avi on 30/04/2023.
//

#ifndef CPP_EX4_PARTA_TEAM_HPP
#define CPP_EX4_PARTA_TEAM_HPP

#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>
namespace ariel
{
    class Team
    {
        private:
        Character* leader;
        vector<Character*> war{10};
        public:
        Team(Character* character);
        ~Team();
        void add(Character* warrior);
        void attack(Team* enemies);
        int stillAlive();
        void print();
    };
}

#endif //CPP_EX4_PARTA_TEAM_HPP
