#include "Case.h"

#include "stdlib.h"
#include <iostream>
#include "stdio.h"

using namespace std;

Case::Case()
{
    //ctor
    this->element = new Element();
    cout << "Création d'une case" <<endl;
}

Case::~Case()
{
    //dtor
    delete element;
    element = 0;
    cout << "Suppression d'une case" << endl;
}
Element* Case::getElement() const
{
    return this->element;
}

void Case::setElement(Element * unElement)
{
    cout << "Suppression d'un element d'une case: " << element->getType() << endl;
    delete element;
    this->element = unElement;
    cout << "Nouvel élement : " << element->getType() << endl;
}
