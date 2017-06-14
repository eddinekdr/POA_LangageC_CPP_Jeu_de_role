#include "Element.h"

#include <iostream>

using namespace std;

Element::Element()
{
    //ctor
    this->type = VIDE;
}

Element::Element(int x, int y)
{
    //ctor
    this->type = VIDE;
    this->pos = new Position(x,y);
}

Element::Element(Position * val)
{
    //ctor
    this->type = VIDE;
    this->pos->Setx(val->Getx());
    this->pos->Sety(val->Gety());
}


Element::Element(int type)
{
    //ctor
    if(type == VIDE)
    {
        this->type = VIDE;
    }
    else if(type == MUR)
    {
        this->type = MUR;
    }
    else if(type == PERSONNAGE)
    {
        this->type = PERSONNAGE;
    }
    else if(type == ITEM)
    {
        this->type = ITEM;
    }
    else
        cout << "Mauvaise initialisation d'élément";
}

Element::~Element()
{
    //dtor
    delete pos;
}

int Element::getType()
{
    return this->type;
}

void Element::SetPosition(Position * unePos)
{
    this->pos->Setx(unePos->Getx());
    this->pos->Sety(unePos->Gety());
}
