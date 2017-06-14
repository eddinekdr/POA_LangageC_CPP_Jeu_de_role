#ifndef CARACTERISTIQUE_H
#define CARACTERISTIQUE_H


class Caracteristique
{
    public:
        Caracteristique();
        ~Caracteristique();
        Caracteristique(const Caracteristique& other);
        Caracteristique& operator=(const Caracteristique& other);

        int GetAgilite() { return agilite; }
        void SetAgilite(int val) { agilite = val; }
        int Getintelligence() { return intelligence; }
        void Setintelligence(int val) { intelligence = val; }
        int Getforce() { return force; }
        void Setforce(int val) { force = val; }

    protected:

    private:
        int agilite;
        int intelligence;
        int force;
};

#endif // CARACTERISTIQUE_H
