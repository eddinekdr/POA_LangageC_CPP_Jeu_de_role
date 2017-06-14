#ifndef MAGE_H
#define MAGE_H

#include <Personnage.h>


class Mage : public Personnage
{
    public:
        Mage();
        virtual ~Mage();
        Mage(const Mage& other);

    protected:

    private:
};

#endif // MAGE_H
