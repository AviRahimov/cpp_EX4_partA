#include "Character.hpp"
using namespace ariel;

Character::Character(string Name, Point &location) : name(Name), loc(location){}

Character::Character(Character& other) : name(other.name), loc(other.loc){

}

Character::~Character(){
    // delete;
}

bool Character::isAlive(){
    return true;
}

double Character::distance(Character* other){
    return 0;
}

void Character::hit(int hitting_points){
    return;
}

string Character::getName(){
    return "";
}

Point Character::getLocation(){
    return Point(0, 0);
}

string Character::print(){
    return "";
}

Character& Character::operator=(const Character& other){
    return *this;
}