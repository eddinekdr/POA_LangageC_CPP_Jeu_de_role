#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <Caracteristique.h>
#include <Arme.h>
#include <Sort.h>

#include <vector>
#include <string>

static const int HAUT = 72;
static const int BAS = 80;
static const int DROITE = 77;
static const int GAUCHE = 75;

static const int TAILLE_MAX = 5;
static const int NB_POINTS = 23;

class Personnage : public Element
{
    public:
        ///---------------------CONSTRUCTEURS - DESTRUCTEURS---------------------------///
        Personnage();
        Personnage(int x, int y);
        Personnage(string unNom, int uneVie, int desPA, int desPM, int uneInitiative,Caracteristique * carac, int x, int y);
        virtual ~Personnage();
        Personnage(const Personnage& other);
        Personnage& operator=(const Personnage& other);

        ///-------------------------GETTERS & SETTERS------------------------------------///
        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        int Getvie() { return vie; }
        void Setvie(int val);
        int GetPA() { return PA; }
        void SetPA(int val) { PA = val; }
        int GetPM() { return PM; }
        void SetPM(int val) { PM = val; }
        int Getinitiative() { return initiative; }
        void Setinitiative(int val) { initiative = val; }
        int GetResistance() { return resistance; }
        void SetResistance(int val) { resistance = val; }
        int GetPointsCaracteristiques() { return pointsCaracteristiques; }
        void SetPointsCaracteristiques(int val) { pointsCaracteristiques = val; }
        Caracteristique* Getcaracteristique() { return caracteristique; }
        void Setcaracteristique(Caracteristique * val) { caracteristique = val; }
        Arme* Getarme() { return arme; }
        void Setarme(Arme * val) { arme = val; }
        vector<Sort*> Getsorts() { return sorts; }
        void Setsorts(vector<Sort*> val) { sorts = val; }
        vector<Item*> Getsac() { return sac; }
        void Setsac(vector<Item*> val) { sac = val; }

        ///----------------------METHODES-----------------------------------------------///

        Personnage* saisiePersonnage();
        Caracteristique* distributionCaracteristique(string nom, int &uneVie, int &uneInitiative, int &uneResistance);
        string listeCaracteristiques(int i);
        bool saisiePossible(int &val1, int &val2);


        ///----------Gestion Sac et Sorts-----------///
        int gererSac();
        int afficherSac();
        void afficherSort();

        Position ramasserObjet(Item * item);
        void utiliserPotion(int choix);

        int jeterObjet();
        void supprimerUnObjetDuSac(int choix);

        void ajouterSort();

        ///------------Attaquer---------------------///
        //int virtual attaquer(int choix) =0;
        int attaquer(int choix);
        int lancerUnSort(int choix);
        int choixSort();
        bool attaquePossible(int val);

        ///------------Déplacement------------------///
        void deplacer(int mouvement);
        int seDeplacer();
        int choixDeplacement();
        Position calculDeplacement(int mouvement);
        Position simulationDeplacement();
        Position requeteDeplacement();

        void ajouterSortMonstre();

    protected:
        string nom;
        int vie;
        int PA;
        int PM;
        int initiative;
        int resistance;
        int pointsCaracteristiques;
        Caracteristique * caracteristique;
        vector<Sort*> sorts;

    private:
        Arme * arme;
        vector<Item*> sac;
};

#endif // PERSONNAGE_H
