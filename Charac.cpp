#include "Charac.hpp"

Charac::Charac() : shield(true), lane(2){
    shieldClock.restart();
}
int Charac::getLane(){
    return lane;
}
bool Charac::hasShield(){
    return shield;
}
void Charac::moveLane(direction dir){
    if(dir == UP && lane != 1){
        lane--;
    }
    if(dir == DOWN && lane != 3){
        lane++;
    }
}
void Charac::setShield(){
    shield=true;
    shieldClock.restart();
}
void Charac::checkShield(){
    int elapsedTime = shieldClock.getElapsedTime().asSeconds();
    if(elapsedTime == 10){
        setShield();
    }
}
void Charac::removeShield(){
    shield=false;
    shieldClock.restart();
}
