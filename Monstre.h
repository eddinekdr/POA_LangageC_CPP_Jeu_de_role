#ifndef MONSTRE_H
#define MONSTRE_H

#include <Personnage.h>


class Monstre : public Personnage
{
    public:
        Monstre();
        Monstre(string unNom, int x, int y);
        virtual ~Monstre();
        Monstre(const Monstre& other);

    protected:

    private:
};

#endif // MONSTRE_H
