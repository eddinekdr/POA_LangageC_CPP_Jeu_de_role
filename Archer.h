#ifndef ARCHER_H
#define ARCHER_H

#include <Personnage.h>


class Archer : public Personnage
{
    public:
        Archer();
        virtual ~Archer();
        Archer(const Archer& other);

    protected:

    private:
};

#endif // ARCHER_H
