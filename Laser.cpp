#include "Laser.hpp"

Laser::Laser() : lane(2) , x(500){

}
Laser::Laser(int lane) : lane(lane), x(500){

}
Laser::~Laser(){
    lane = 0;
    x = 0;
}
int Laser::getLane(){
    return lane;
}
int Laser::getCoord(){
    return x;
}
void Laser::pushLaser(int number){
    if(x>0){
        x-=number;
    }
}
