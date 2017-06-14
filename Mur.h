#ifndef MUR_H
#define MUR_H

#include "Element.h"

class Mur : public Element
{
    public:
        Mur();
        Mur(int x,int y);
        Mur(Position * pos);
        virtual ~Mur();
        Mur(const Mur& other);
        Mur& operator=(const Mur& other);

    protected:

    private:
};

#endif // MUR_H
