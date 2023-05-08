#include "Cowboy.hpp"
using namespace ariel;

Cowboy::Cowboy(string Name, Point location) : Character(Name, location), num_of_bullets(6){
}

string Cowboy::print(){
    return "";
}

void Cowboy::shoot(Character* enemy){
    return;
}

bool Cowboy::hasboolets(){
    return true;
}

void Cowboy::reload(){
    return;
}