#include "Item.h"

Item::Item()
{
    //ctor
}

Item::Item(Position * unePos)
{
    this->type = ITEM;
    this->pos->Setx(unePos->Getx());
    this->pos->Sety(unePos->Gety());
}

Item::~Item()
{
    //dtor
}

Item::Item(const Item& other)
{
    //copy ctor
}

Item& Item::operator=(const Item& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
