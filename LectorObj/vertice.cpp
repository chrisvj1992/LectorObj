#include <iostream>
#include "vertice.hpp"

using namespace std;

vertice::vertice(){}

vertice::vertice(float posX, float posY, float posZ)
{
    this->x = posX;
    this->y = posY;
    this->z = posZ;
};

void vertice::print()
{
    printf("posX: %f, posY: %f, posZ: %f \n\n", this->x, this->y, this->z );
}


