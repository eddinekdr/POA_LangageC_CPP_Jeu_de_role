#ifndef CASE_H
#define CASE_H

#include "Element.h"

using namespace std;

class Case
{
    public:
        Case();
        ~Case();

        Element* getElement() const;
        void setElement(Element * unElement);

    protected:

    private:
        Element * element;
};

#endif // CASE_H
