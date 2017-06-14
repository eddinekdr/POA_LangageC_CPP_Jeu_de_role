#include "Mur.h"

#include <iostream>

using namespace std;

Mur::Mur()
{
    //ctor
    this->type = MUR;
    //cout << "Creation d'un mur" <<endl;
}

Mur::Mur(int x, int y)
{
    //ctor
    this->type = MUR;
    this->pos = new Position(x,y);
}


Mur::Mur(Position * val)
{
    //ctor
    this->type = MUR;
    this->pos->Setx(val->Getx());
    this->pos->Sety(val->Gety());
}

Mur::~Mur()
{
    //dtor
    //cout << "Suppression d'un mur" <<endl;
}

Mur::Mur(const Mur& other)
{
    //copy ctor
}

Mur& Mur::operator=(const Mur& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
