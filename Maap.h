#ifndef MAAP_H
#define MAAP_H

#include <vector>
#include "Personnage.h"

using namespace std;

static const int PJ = 20;
static const int PNJ = 21;
static const int MONSTRE = 22;

//AFFICHAGE COMPLEXE
static const int LIGNES = 11;
static const int COLONNES = 21;

//AFFICHAGE FINALE
//static const int LIGNES = 16;
//static const int COLONNES = 11;

class Maap
{
    public:
        Maap();
        ~Maap();

        int GetLignes(){ return this->lignes; }
        void SetLignes(int nbLignes){ this->lignes = lignes; }
        int GetColonnes(){ return this->colonnes; }
        void SetColonnes( int nbColonnes ){ this->colonnes = nbColonnes; }

        Personnage* GetJoueur(){ return this->joueur; }
        void SetJoueur(Personnage * perso){ this->joueur = perso; }

        Personnage* GetAdversaire(){ return this->adversaire; }
        void SetAdversaire(Personnage * perso){ this->adversaire = perso; }


        void dessinerLigne(int longueur, char c, bool bordure);
        void dessinerRangee(int ligne, int longueur, int epaisseur, char c);
        void dessinerGrille(char c, int hauteur, int longueur, int epaisseur);

        void affichageFinal(bool enCombat);
        void affichage();
        void affichageComplexe(bool enCombat);

        ///Maap de jeu
        void creationMaap1();
        void creationMaap1F();
        void creationMaap2F();
        void creationMaap3F();
        void creationMaapCombat1(Personnage * joueur, Personnage * adversaire);
        void creationMaapCombat2(Personnage * joueur, Personnage * adversaire);

        ///Fonctions d'ajouts
        void actualiserMaap(Element * e, int x, int y);
        void add(Element * e);

        void retirerAjouter(int x, int y, Element * e);
        void collecterItem(int x, int y);

        ///Fonctions de déplacements
        int choixAction();
        int actionsPossibles(Personnage * perso, int mouvement);

        int deplacerPersonnage(int mouvement);
        void deplacement(Element * e, Position * nouvelle_position);///Fonction générale
        int deplacementPossible(Position * nouvelle_position);

        Position* calculDeplacement(Position * pos, int mouvement);

    protected:

    private:
        vector< vector <Element*> > * plateau;
        int lignes;
        int colonnes;
        Personnage * joueur;
        Personnage * adversaire;
};

#endif // MAAP_H
