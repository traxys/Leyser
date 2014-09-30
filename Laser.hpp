#ifndef LASER_HPP_INCLUDED
#define LASER_HPP_INCLUDED

class Laser{
public:
    Laser();
    Laser(int lane);
    ~Laser();
    int getLane();
    int getCoord();
    void pushLaser(int number);
private:
    int lane;
    int x;
};

#endif // LASER_HPP_INCLUDED
