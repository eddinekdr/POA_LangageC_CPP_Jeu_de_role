#ifndef POTION_H
#define POTION_H

#include <Item.h>


class Potion : public Item
{
    public:
        Potion();
        Potion(int soin, string name);
        Potion(int soin, string name, int x, int y);
        virtual ~Potion();
        Potion(const Potion& other);
        Potion& operator=(const Potion& other);

        int Getsoin() { return soin; }
        void Setsoin(int val) { soin = val; }

    protected:

    private:
        int soin;
};

#endif // POTION_H
