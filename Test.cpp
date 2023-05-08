#include "doctest.h"
#include "sources/Team.hpp"
#include <vector>
#include <math.h>
#include <sstream>
using namespace ariel;
using namespace std;

TEST_SUITE("Point class tests")
{
    Point p1(2, 4);
    Point p2(6, 8);

    TEST_CASE("Distance between two points")
    {
        CHECK(p1.distance(p2) == (double)sqrt(20));
    }

    TEST_CASE("Move towards a point")
    {
        Point p3(3, 3);
        Point p4(4, 4);
        Point p5 = Point::moveTowards(p3, p4, 1.0);
        CHECK(p5.distance(p4) <= 1.0);
    }
}

TEST_SUITE("Character class tests")
{
    Point p1(2, 4);
    Character *c1 = new Cowboy("John", p1);
    Character *c2 = new Cowboy("Dave", p1);

    TEST_CASE("Distance between two characters")
    {
        CHECK(c1->distance(c2) == 0.0);
    }

    TEST_CASE("Get character name")
    {
        CHECK(c1->getName() == "John");
    }

    TEST_CASE("Get character location")
    {
        CHECK(c1->getLocation().distance(p1) == 0.0);
    }

    TEST_CASE("Character is alive")
    {
        CHECK(c1->isAlive() == true);
    }

    TEST_CASE("Hit character")
    {
        c1->hit(10);
        CHECK(c1->isAlive() == false);
    }
}

TEST_SUITE("Cowboy class tests")
{
    Point p1(2, 4);
    Cowboy *c1 = new Cowboy("John", p1);

    TEST_CASE("Has bullets")
    {
        CHECK(c1->hasboolets() == true);
    }

    TEST_CASE("Shoot enemy")
    {
        Point p2(6, 8);
        Character *c2 = new Cowboy("Dave", p2);
        c1->shoot(c2);
        CHECK(c2->isAlive() == false);
        CHECK(c1->hasboolets() == false);
    }

    TEST_CASE("Reload bullets")
    {
        c1->shoot(c1);
        c1->reload();
        CHECK(c1->hasboolets() == true);
    }
}

TEST_SUITE("Ninja class tests")
{
    Point p1(2, 4);
    Ninja *n1 = new Ninja("Jack", p1);

    TEST_CASE("Move towards an enemy")
    {
        Point p2(4, 4);
        Character *c1 = new Cowboy("John", p2);
        n1->move(c1);
        CHECK(n1->getLocation().distance(p2) < 2.0);
    }

    TEST_CASE("Slash enemy")
    {
        Point p2(6, 8);
        Character *c1 = new Cowboy("Dave", p2);
        n1->slash(c1);
        CHECK(c1->isAlive() == false);
    }
}

TEST_SUITE("OldNinja class tests")
{
    Point p1(2, 4);
    OldNinja *n1 = new OldNinja("Jack", p1);

    TEST_CASE("Move towards an enemy")
    {
        Point p2(4, 4);
        Character *c1 = new Cowboy("John", p2);
        n1->move(c1);
        CHECK(n1->getLocation().distance(p2) < 2.0);
    }

    TEST_CASE("Slash enemy")
    {
        Point p2(6, 8);
        Character *c1 = new Cowboy("Dave", p2);
        n1->slash(c1);
        CHECK(c1->isAlive() == false);
    }
}

TEST_SUITE("Team class tests")
{
    Point p1(2, 4);
    Point p2(6, 8);
    Character *c1 = new Cowboy("John", p1);
    Character *c2 = new Ninja("Lee", p2);
    Team *t1 = new Team(c1); // team led by John 
    Team *t2 = new Team(c2); // team led by Lee

    TEST_CASE("Create a team with a leader")
    {
        CHECK(t1->stillAlive() == 1); // only John is alive
        CHECK(t2->stillAlive() == 1); // only Lee is alive
    }

    TEST_CASE("Add characters to a team")
    {
        Character *c3 = new Cowboy("Dave", p1);
        Character *c4 = new Ninja("Kim", p2);
        t1->add(c3);                  // add Dave to John's team
        t2->add(c4);                  // add Kim to Lee's team
        CHECK(t1->stillAlive() == 2); // John and Dave are alive
        CHECK(t2->stillAlive() == 2); // Lee and Kim are alive
    }

    TEST_CASE("Attack another team")
    {
        t1->attack(t2); // John's team attacks Lee's team
        CHECK(t1->stillAlive() == 2); // John and Dave are still alive
        CHECK(t2->stillAlive() == 0); // Lee and Kim are dead
    }
}

TEST_SUITE("TrainedNinja class tests")
{
    Point p1(2, 4);
    TrainedNinja *n1 = new TrainedNinja("Jack", p1);
    TEST_CASE("Move towards an enemy")
    {
        Point p2(4, 4);
        Character *c1 = new Cowboy("John", p2);
        n1->move(c1);
        CHECK(n1->getLocation().distance(p2) < 2.0);
    }

    TEST_CASE("Slash enemy")
    {
        Point p2(6, 8);
        Character *c1 = new Cowboy("Dave", p2);
        n1->slash(c1);
        CHECK(c1->isAlive() == false);
    }

    // TEST_CASE("Throw shuriken")
    // {
    //     Point p2(6, 8);
    //     Character *c1 = new Cowboy("Dave", p2);
    //     n1->throwShuriken(c1);
    //     CHECK(c1->isAlive() == false);
    // }
}

TEST_SUITE("YoungNinja class tests")
{
    Point p1(2, 4);
    YoungNinja *n1 = new YoungNinja("Jack", p1);

    TEST_CASE("Move towards an enemy")
    {
        Point p2(4, 4);
        Character *c1 = new Cowboy("John", p2);
        n1->move(c1);
        CHECK(n1->getLocation().distance(p2) < 2.0);
    }

    TEST_CASE("Slash enemy")
    {
        Point p2(6, 8);
        Character *c1 = new Cowboy("Dave", p2);
        n1->slash(c1);
        CHECK(c1->isAlive() == false);
    }

    // TEST_CASE("Train a young ninja")
    // {
    //     Point p2(6, 8);
    //     Character *c1 = new YoungNinja("Jenny", p2);
    //     n1->train(dynamic_cast<YoungNinja *>(c1));
    //     CHECK(dynamic_cast<YoungNinja *>(c1)->getLevel() == 2);
    // }
}

TEST_SUITE("OldNinja class tests")
{
    Point p1(2, 4);
    OldNinja *n1 = new OldNinja("Jack", p1);
    TEST_CASE("Move towards an enemy")
    {
        Point p2(4, 4);
        Character *c1 = new Cowboy("John", p2);
        n1->move(c1);
        CHECK(n1->getLocation().distance(p2) < 2.0);
    }

    TEST_CASE("Slash enemy")
    {
        Point p2(6, 8);
        Character *c1 = new Cowboy("Dave", p2);
        n1->slash(c1);
        CHECK(c1->isAlive() == false);
    }
}
