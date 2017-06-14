#include "Caracteristique.h"

Caracteristique::Caracteristique()
{
    //ctor
    this->agilite = 10;
    this->force = 10;
    this->intelligence = 10;
}

Caracteristique::~Caracteristique()
{
    //dtor
}

Caracteristique::Caracteristique(const Caracteristique& other)
{
    //copy ctor
}

Caracteristique& Caracteristique::operator=(const Caracteristique& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
