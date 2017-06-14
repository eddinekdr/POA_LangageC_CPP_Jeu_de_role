#include "Sort.h"

Sort::Sort()
{
    //ctor
    this->type = "force";
    this->coutPA = 2;
    this->dommage = 10;
    this->name = "Fatal foudre";
    this->soin = 0;
    this->nature = "attaque";
}

Sort::Sort(string unType, int unCoutPA, string unNom, int desDommages, int unSoin, string uneNature)
{
    type = unType;
    coutPA = unCoutPA;
    dommage = desDommages;
    name = unNom;
    soin = soin;
    nature = uneNature;
}

Sort* Sort::creationSort(int val)
{
    switch(val)
    {
    case 0:
        return new Sort("force",3,"Tremblement divin", 15, 0,"attaque");
    case 1:
        return new Sort("intelligence",4,"Soin elfique", 0, 22, "soin");
    case 2:
        return new Sort("sagesse",3,"Armure incandescente", 19,0,"armure");
    case 3:
        return new Sort("intelligence",2,"Pluie de braise",9,0, "attaque");
    case 5:
        return new Sort("force",3,"Onde de choc malefique", 11, 0,"attaque");
    case 6:
        return new Sort("intelligence",4,"Soin dantesque", 0, 16, "soin");
    case 7:
        return new Sort("sagesse",3,"Armure aqueuse", 17,0,"armure");
    case 8:
        return new Sort("intelligence",2,"Souffle enflammé",10,0, "attaque");
    default:
        return new Sort();
    }
}

Sort::~Sort()
{
    //dtor
}

Sort::Sort(const Sort& other)
{
    //copy ctor
}

Sort& Sort::operator=(const Sort& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
