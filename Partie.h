#ifndef PARTIE_H
#define PARTIE_H

#include "Maap.h"
#include "Combat.h"

class Partie
{
    public:
        ///CONSTRUCTEURS
        Partie();
        ~Partie();

        ///GETTERS & SETTERS
        Maap * Getmaap() { return maap; }
        void Setmaap(Maap * val) { maap = val; }
        Personnage * GetJoueur() { return joueur; }
        void SetJoueur(Personnage * val) { joueur = val; }
        Combat * GetCombat() { return combat; }
        void SetCombat(Combat * val) { combat = val; }

        ///INITIALISATION
        void start();
        void lancerPartie();

        ///MENU
        void afficherMenu(bool partieEnCours);
        int choixMenu(bool partieEnCours);

        ///SAUVEGARDE - CHARGEMENT - NOUVELLE PARTIE
        void charger();
        void sauvegarder();
        void nouvellePartie();

        ///JEU - COMBAT
        int jouer();
        int lancerCombat(Personnage * joueur1,Personnage * joueur2);

    protected:

    private:
        Maap * maap;
        Combat * combat;
        Personnage * joueur;
};

#endif // PARTIE_H
