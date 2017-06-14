#ifndef ITEM_H
#define ITEM_H

#include <Element.h>


class Item : public Element
{
    public:
        Item();
        Item(Position * pos);
        virtual ~Item();
        Item(const Item& other);
        Item& operator=(const Item& other);

        string GetName(){ return name; }
        void SetName(string val){ name = val; }

    protected:
        string name;
    private:
};

#endif // ITEM_H
