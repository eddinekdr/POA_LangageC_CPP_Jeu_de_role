#include "Position.h"

#include <iostream>

using namespace std;

Position::Position()
{
    //ctor
    x = 0;
    y = 0;
}

Position::Position(int unX, int unY)
{
    //ctor
    x = unX;
    y = unY;
}

Position::~Position()
{
    //dtor
}

Position::Position(Position * val)
{
    this->x = val->Getx();
    this->y = val->Gety();
}


Position::Position(const Position& other)
{
    //copy ctor
}

Position& Position::operator=(const Position& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
