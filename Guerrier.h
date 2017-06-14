#ifndef GUERRIER_H
#define GUERRIER_H

#include <Personnage.h>


class Guerrier : public Personnage
{
    public:
        Guerrier();
        virtual ~Guerrier();
        Guerrier(const Guerrier& other);

    protected:

    private:
};

#endif // GUERRIER_H
