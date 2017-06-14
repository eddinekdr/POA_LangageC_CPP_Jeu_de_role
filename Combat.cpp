#include "Combat.h"
#include "windows.h"
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;


/*************************************/
/**                                 **/
/**             COMBAT              **/
/**                                 **/
/*************************************/


/********* CONSTRUCTEURS *************/

Combat::Combat()
{
    //ctor
    joueur1 = 0;
    joueur2 = 0;

    maapCombat = new Maap();
}

Combat::~Combat()
{
    //dtor
    delete maapCombat;
    maapCombat = nullptr;
    delete joueur1;
    joueur1 = nullptr;
    delete joueur2;
    joueur2 = nullptr;
}

/********* METHODES *************/

int Combat::lancerCombat(Personnage * joueur, Personnage * adversaire)
{
    int i = 0; ///Variables pour alterner les tours
    maapCombat->creationMaapCombat2(joueur,adversaire);
    //maapCombat->creationMaap2F();
    this->joueur1 = joueur;
    this->joueur2 = adversaire;

    ///On désigne l'odre de jeu
    Personnage * premierCombattant = ordreTourDeJeu(joueur1,joueur2)[0];
    Personnage * secondCombattant = ordreTourDeJeu(joueur1,joueur2)[1];

    ///On lance le combat
    cout << "\n                                                              ";
    cout << "Debut du combat !" <<endl;
    cout << "\n                                                              ";
    cout << joueur1->Getnom() << " commence !" << endl;
    getch();
    std::system("cls");
    do
    {
        std::system("cls");
        affichageCombat();
        if(i==0)
        {
            cout << "                                           ";
            cout << "Au tour de " << premierCombattant->Getnom() << "." << endl;
            getch();
            tourDeJeu(premierCombattant);
            i++;
        }
        else
        {
            cout << "                                           ";
            cout << "Au tour de " << secondCombattant->Getnom() << "." << endl;
            getch();
            tourDeJeu(secondCombattant);
            i--;
        }
    }while(!finCombat(premierCombattant,secondCombattant));

    bool partieGagnee = estGagnant(joueur1,joueur2);

    ///Remettre les pointeurs à 0
    if(partieGagnee)
    {
        delete joueur2;
        joueur2 = 0;
        return 1;
    }
    else
    {
        std::system("cls");
        cout << "\n\n\n\n\n\n\n                                                              ";
        cout << "END GAME !" << endl;
        Sleep(1200);
        return 0;
    }
    premierCombattant = 0;
    secondCombattant = 0;
}

vector<Personnage*> Combat::ordreTourDeJeu(Personnage * joueur1, Personnage * joueur2)
{
    vector<Personnage*> ordre (2);
    if(joueur1->Getinitiative()>=joueur2->Getinitiative())
    {
        ordre[0] = joueur1;
        ordre[1] = joueur2;

        return ordre;
    }
    else
    {
        ordre[0] = joueur2;
        ordre[1] = joueur1;

        return ordre;
    }
}

void Combat::tourDeJeu(Personnage * joueur)
{
    int choix;
    if(joueur == this->joueur1) ///JOUEUR
    {
        joueur1->SetPA(7);
        do
        {
            std::system("cls");
            affichageCombat();
            afficheMenuCombat();
            choix = actionsCombatJOUEUR(choixMenuCombat());
        }while(choix!=3 && choix!=1 && joueur1->GetPA()>=0);
    }
    else                        ///IA
    {
        actionsCombatIA();
    }
}

void Combat::afficheMenuCombat()
{
    cout << "                                           ";
    cout << "1. Attaquer  2. Me deplacer  .3 Passer mon tour" << endl;
}

int Combat::choixMenuCombat()
{
    int choix;
    do
    {
        cin >> choix;

        switch(choix)
        {
            case 1:
                return 1;
                break;
            case 2:
                return 2;
                break;
            case 3:
                return 3;
                break;
            default:
                cout << "Erreur, veuillez recommencer," <<endl;
                break;
        }
    }while(choix != 1 && choix != 2 && choix != 3);
}

void Combat::afficheMenuSort()
{
    for(int i=0; i<joueur1->Getsorts().size(); i++)
    {
       cout << "                                           ";
       cout << i+1 << ". " << joueur1->Getsorts().at(i)->GetName() << endl;
    }
}

int Combat::calculDegats(int attaque, Personnage * joueur)
{
    Personnage * joueurCourant;
    Personnage * joueurAdverse;

    if(joueur == joueur1)
    {
        joueurCourant = joueur1;
        joueurAdverse = joueur2;
    }
    else
    {
        joueurCourant = joueur2;
        joueurAdverse = joueur1;
    }

    attaque = attaque + ((joueurCourant->Getcaracteristique()->Getforce())/100)*10;
    int defense = 0+((joueurAdverse->GetResistance()/100)*10);

    attaque = attaque - defense;

    if(attaque<0)
    {
        getch();
        std::system("cls");
        affichageCombat();
        cout << "\n                                           ";
        cout << "Cette attaque n'a aucun effet sur " << joueurAdverse->Getnom() << "." <<endl;
        attaque = 0;
    }
    else
    {
        getch();
        std::system("cls");
        affichageCombat();
        cout << "                                           ";
        cout << joueurAdverse->Getnom() << " perds " << attaque << " pts de vie." <<endl;
    }

    getch();

    joueurCourant = 0;
    joueurAdverse = 0;
    delete joueurCourant;
    delete joueurAdverse;

    return attaque;
}

void Combat::choixMenuSort()
{
    int choix;
    int i=0;
        cout << "\n                                           ";
        cout << "Choix: ";
        cin >> choix;
        if(joueur1->attaquePossible(choix))
        {
            joueur2->Setvie(joueur2->Getvie()-calculDegats(joueur1->attaquer(choix-1),joueur1));
            joueur1->SetPA((joueur1->GetPA())-(joueur1->Getsorts().at(choix-1)->GetcoutPA()));
        }
        else
        {
            cout << "                                           ";
            cout << "Vous ne disposez pas d'assez de PA." << endl;
        }
}

int Combat::actionsCombatIA()
{
    //choix= IA;
    int nb_alea = (rand() % 4) + 1;
    if(joueur2->attaquePossible(nb_alea))
    {
        joueur1->Setvie(joueur1->Getvie()-calculDegats(joueur2->attaquer(nb_alea-1),joueur2));
    }
}

int Combat::actionsCombatJOUEUR(int choix)
{
    switch(choix)
    {
        case 1:
            afficheMenuSort();
            choixMenuSort();
            return 1;
            break;
        case 2:
            cout << "\n                                                              ";
            cout << "Utilisez les fleches directionnelles." <<endl;
            maapCombat->choixAction();
            return 2;
        case 3:
            return 3;///Pour annuler
    }
}

void Combat::affichageCombat()
{

    maapCombat->affichageFinal(true);

    cout << "\n\n                                           ";
    cout << joueur1->Getnom()<<"                        "<<joueur2->Getnom()<<"   " << endl;
    cout << "\n                                        Vie: ";
    cout << joueur1->Getvie()<<"                       Vie: "<<joueur2->Getvie()<<"   " << endl;
    cout << "\n                                         PA: ";
    cout << joueur1->GetPA()<<"                            PA: "<<joueur2->GetPA()<<"   " << endl;
    cout << "\n                                        PM: ";
    cout << joueur1->GetPM()<<"                            PM: "<<joueur2->GetPM()<<"   " << endl;

}

bool Combat::finCombat(Personnage * joueur, Personnage * adversaire)
{
    if(joueur->Getvie()>0 && adversaire->Getvie()>0)
    {
        return false;
    }
    else
        return true;
}

bool Combat::estGagnant(Personnage * joueur, Personnage * joueur2)
{
    if(joueur->Getvie()<=0)
    {
        cout << joueur2->Getnom() << " gagne !" << endl;
        return true;
    }
    else
    {
        cout << joueur1->Getnom() << " gagne !" << endl;
        return false;
    }
}

