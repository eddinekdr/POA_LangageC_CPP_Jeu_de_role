#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

#include "Position.h"

static const int VIDE = 0;
static const int MUR = 1;
static const int PERSONNAGE = 2;
static const int ITEM = 3;

using namespace std;

class Element
{
    public:
        Element();
        Element(int x, int y);
        Element(Position * pos);
        Element(int type);
        virtual ~Element();

        int getType();
        Position* GetPosition() { return pos; }
        void SetPosition(Position * val);

        int GetX() { return pos->Getx(); }
        void SetX(int val) { pos->Setx(val); }
         int GetY() { return pos->Gety(); }
        void SetY(int val) { pos->Sety(val); }

    protected:
        int type;
        Position * pos;
    private:
};

#endif // ELEMENT_H
