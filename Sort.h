#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>

using namespace std;

class Sort
{
    public:
        Sort();
        Sort(string unType, int unCoutPA, string unNom, int desDommages, int unSoin, string uneNature);
        ~Sort();
        Sort(const Sort& other);
        Sort& operator=(const Sort& other);

        int Getdommage() { return dommage; }
        void Setdommage(int val) { dommage = val; }
        int Getsoin() { return soin; }
        void Setsoin(int val) { soin = val; }
        int GetcoutPA() { return coutPA; }
        void SetcoutPA(int val) { coutPA = val; }
        string Gettype() { return type; }
        void Settype(string val) { type = val; }
        string GetName() { return name; }
        void SetName(string val) { name = val; }
        string Getnature() { return nature; }
        void Setnature(string val) { nature = val; }

        Sort* creationSort(int val);

    protected:

    private:
        int dommage;
        int soin;
        int coutPA;
        string type;
        string name;
        string nature;
};

#endif // SORT_H
