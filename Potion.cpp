#include "Potion.h"

 #include <iostream>

using namespace std;

Potion::Potion()
{
    //ctor
    this->type = ITEM;
    this->soin = 10;
    this->name = "potion";
}

Potion::Potion(int unSoin, string unNom)
{
    //ctor
    this->type = ITEM;
    this->soin = unSoin;
    this->name = unNom;
}

Potion::Potion(int unSoin, string unNom, int valX, int valY)
{
    //ctor
    this->type = ITEM;
    this->soin = unSoin;
    this->name = unNom;
    this->pos = new Position(valX,valY);
}


Potion::~Potion()
{
    //dtor
    //cout << "destruction d'une potion" << endl;
}

Potion::Potion(const Potion& other)
{
    //copy ctor
}

Potion& Potion::operator=(const Potion& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


