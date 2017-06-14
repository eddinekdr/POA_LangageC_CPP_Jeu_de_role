#include "Monstre.h"

Monstre::Monstre()
{
    //ctor
    this->type = 22;

    ajouterSortMonstre();
}

Monstre::Monstre(string unNom, int x, int y)
{
    //ctor
    this->type = 22;
    nom = unNom;
    vie = 50;
    PA = 7;
    PM = 4;
    initiative = 104;
    this->pos = new Position(x,y);
    this->caracteristique = new Caracteristique();
    vector<Sort*> sorts();

    ajouterSortMonstre();
}

Monstre::~Monstre()
{
    //dtor
}

Monstre::Monstre(const Monstre& other)
{
    //copy ctor
}
