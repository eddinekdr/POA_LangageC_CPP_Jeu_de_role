#ifndef ARME_H
#define ARME_H

#include <Item.h>
#include <stdio.h>
#include "string"

class Arme : public Item
{
    public:
        Arme();
        virtual ~Arme();
        Arme(const Arme& other);
        Arme& operator=(const Arme& other);

        int Getdommages() { return dommages; }
        void Setdommages(int val) { dommages = val; }
        string Gettype() { return type; }
        void Settype(string val) { type = val; }
        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        string Getcarac() { return carac; }
        void Setcarac(string val) { carac = val; }

        void equiperExcalibur();

    protected:

    private:
        string type;

        int dommages;
        string nom;
        string carac;

};

#endif // ARME_H
