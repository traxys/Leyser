#ifndef CHARAC_HPP_INCLUDED
#define CHARAC_HPP_INCLUDED

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum direction{
    UP,DOWN
};

class Charac{
public:
    Charac();
    int getLane();
    void moveLane(direction dir);
    bool hasShield();
    void setShield();
    void removeShield();
    void checkShield();
private:
    bool shield;
    int lane;
    sf::Clock shieldClock;
};

#endif // CHARAC_HPP_INCLUDED
