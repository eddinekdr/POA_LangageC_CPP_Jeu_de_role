#ifndef COMBAT_H
#define COMBAT_H

#include "Maap.h"
#include "Personnage.h"
#include <typeinfo>
#include <iostream>
#include <string>
#include "stdio.h"
#include "conio.h"

class Combat
{
    public:
        Combat();
        virtual ~Combat();

        Personnage * Getjoueur1() { return joueur1; }
        void Setjoueur1(Personnage * val) { joueur1 = val; }
        Personnage * Getjoueur2() { return joueur2; }
        void Setjoueur2(Personnage * val) { joueur2 = val; }
        Maap* GetmaapCombat() { return maapCombat; }
        void SetmaapCombat(Maap * val) { maapCombat = val; }

        int lancerCombat(Personnage * joueur1, Personnage * adversaire);
        int actionsCombat(Personnage * joueur1);

        bool finCombat(Personnage * joueur1, Personnage * joueur2);
        bool estGagnant(Personnage * joueur1, Personnage * joueur2);

        void tourDeJeu(Personnage * joueur);
        vector<Personnage*> ordreTourDeJeu(Personnage * joueur1, Personnage * joueur2);

        void affichageCombat();
        int seDeplacerEnCombat(Personnage * joueur, int mouvement);

        void afficheMenuCombat();
        int choixMenuCombat();
        int actionsCombatJOUEUR(int val);
        int actionsCombatIA();
        void afficheMenuSort();
        void choixMenuSort();
        int calculDegats(int dommages, Personnage * joueur);

        void chargerMaapCombat1();
        void chargerMaapCombat2();


    protected:

    private:
        Personnage * joueur1;
        Personnage * joueur2;
        Maap * maapCombat;
};

#endif // COMBAT_H
