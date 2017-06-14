#include "Arme.h"

Arme::Arme()
{
    //ctor
    this->type = "arme";
    this->dommages = 0;
    this->carac = "force";
}

Arme::~Arme()
{
    //dtor
}

void Arme::equiperExcalibur()
{
    this->type ="arme";

    this->nom = "Epee d'excalibur";
    this->dommages = 12;
    this->carac = "force";
}

Arme::Arme(const Arme& other)
{
    //copy ctor
}

Arme& Arme::operator=(const Arme& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
