#include "Partie.h"
#include "Potion.h"
#include "Monstre.h"
#include "windows.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>

static const int DECLENCHER_COMBAT = 5;

using namespace std;

Partie::Partie()
{
    //ctor
    maap = new Maap();
    combat = new Combat();
}

Partie::~Partie()
{
    //dtor
    delete maap;
    maap = nullptr;
    delete combat;
    combat = nullptr;
}

void Partie::afficherMenu(bool partieEnCours)
{
    std::system("cls");
    cout << "\n\n\n\n" <<endl;
    cout << "                                          ================================" << endl;
    cout << "                                                                          " << endl;
    cout << "                                    --------              MENU             --------" << endl;
    cout << "                                                                " << endl;
    cout << "                                          ================================" << endl;
    cout << "                                                                          " << endl;
    cout << "                                               =                      =" << endl;
    cout << "                                                   1.Nouvelle partie   " << endl;
    cout << "                                               =                      =" << endl;
    cout << "                                                    2.Charger partie    " << endl;
    cout << "                                               =                      =" << endl;
    cout << "                                                       3.Quitter       " << endl;
    if(partieEnCours)
    {
        cout << "                                               =                      =" << endl;
        cout << "                                                     4.Sauvegarder     " << endl;
        cout << "                                                                       " << endl;
        cout << "                                               ========================" << endl;
    }
    else{
        cout << "                                               =                      =" << endl;
        cout << "                                                                   " << endl;
        cout << "                                               ========================" << endl;
        cout << "                                                           ";
    }
}

int Partie::choixMenu(bool partieEnCours)
{
    int choix;
    cin >> choix;

    if(choix == 1)
    {
        lancerPartie();
    }
    else if(choix == 2)
    {
        charger();
    }
    else if(choix == 3)
    {
        "FIN DU JEU.";
        return 0;
    }
    else if(partieEnCours && choix == 4)
    {
        sauvegarder();
    }
}

void Partie::start()
{
    afficherMenu(false);///False indique qu'il ne faut pas afficher l'option "Sauvegarder".
    choixMenu(false);
}

int Partie::jouer()///Pour un PJ
{
    int choix;
    int secondChoix;
    bool enCombat = false;

    std::system("cls");
    cout << "" << endl;
    maap->affichageFinal(false);

    choix = maap->choixAction();///On demande à l'utilisateur une action

    if(choix == 7){
        do
        {
            secondChoix = maap->GetJoueur()->gererSac();
        }while(secondChoix!=13);
    }
    else if(choix == 8){
        maap->GetJoueur()->afficherSort();
    }
    else if(choix == 3 && enCombat){
        maap->GetJoueur()->SetPM(maap->GetJoueur()->GetPM()-1);
    }
    else if(choix == DECLENCHER_COMBAT){
        return DECLENCHER_COMBAT;
    }
    else if(choix == 9){
        std::system("cls");
        cout << "\n\n\n" << endl;
        afficherMenu(true);
        choixMenu(true);
    }

    return choix;
}

void Partie::lancerPartie()
{
    int retour;
    maap->creationMaap1F();
    do
    {
        retour = jouer();
        if(retour == DECLENCHER_COMBAT)
        {
            int x = maap->GetAdversaire()->GetX();///On sauvegarde les positions du monstre
            int y = maap->GetAdversaire()->GetY();
            retour = combat->lancerCombat(maap->GetJoueur(),maap->GetAdversaire());
            if(retour==0)
            {
                retour = 9;
            }
            else
            {
                std::system("cls");
                cout << "\n                                                            ";
                cout << "Chargement du Level 2: La vallée caché de la brume...";
                Sleep(1200);
                maap->creationMaap2F();
                retour = 1;///On s'assure de rejouer un tour
            }
        }

    }while( retour != 9 );
}

void Partie::charger()
{

    string nom;
    int vie;
    int PA;
    int PM;
    int initiative;
    int resistance;
    int pointsCaracteristiques;
    string agilite;
    string force;
    string intelligence;
    int x;
    int y;

    string mon_fichier = "";
    cout << "                                           ";
    cout << "Quelle partie souhaitez-vous charger ? "<<endl;
    cout << "                                           ";
    cin >> mon_fichier;

    mon_fichier += ".txt";
    string s = "C:\\Users\\Ludo\\Documents\\ESILV\\3e_annee\\Programmation\\C_C++\\MiniJeu\\";
    s += mon_fichier;

    ifstream fichier(mon_fichier, ios::in);

    if(fichier)///Si l'ouverture a fonctionné
    {
        string ligne;

        while(getline(fichier, ligne))
        {
                cout << ligne << endl;
        }
        //nom >> vie >> PA >> PM >> initiative >> resistance >> pointsCaracteristiques >> agilite >> force >> intelligence >> x >> y;

        fichier.close();
    }
    else
                cerr << "       Impossible d'ouvrir le fichier !" << endl;
}

void Partie::sauvegarder()
{
        string nom_fichier = "";
        cout << "       Sous quel nom souhaitez-vous enregistrer votre partie ?\n       ";

        cin >> nom_fichier;
        nom_fichier += ".txt";

        ofstream fichier(nom_fichier, ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

        if(fichier)
        {
                fichier << maap->GetJoueur()->Getnom() << "\n";
                fichier << maap->GetJoueur()->Getvie() << "\n";
                fichier << maap->GetJoueur()->GetPA() << "\n";
                fichier << maap->GetJoueur()->GetPM() << "\n";
                fichier << maap->GetJoueur()->Getinitiative() << "\n";
                fichier << maap->GetJoueur()->GetResistance() << "\n";
                fichier << maap->GetJoueur()->GetPointsCaracteristiques() << "\n";
                fichier << maap->GetJoueur()->Getcaracteristique()->GetAgilite() << "\n";
                fichier << maap->GetJoueur()->Getcaracteristique()->Getforce() << "\n";
                fichier << maap->GetJoueur()->Getcaracteristique()->Getintelligence() << "\n";
                /*for(int i=0; i<maap->GetJoueur()->Getsorts().size();i++)
                {
                    maap->GetJoueur()->Getsorts().at(i)->Getdommage() << "\n";
                    maap->GetJoueur()->Getsorts().at(i)->Getsoin() << "\n";
                    maap->GetJoueur()->Getsorts().at(i)->GetcoutPA() << "\n";
                    maap->GetJoueur()->Getsorts().at(i)->Gettype() << "\n";
                    maap->GetJoueur()->Getsorts().at(i)->GetName() << "\n";
                    maap->GetJoueur()->Getsorts().at(i)->Getnature() << "\n";
                }*/
                for(int i=0; i<maap->GetJoueur()->Getsac().size();i++)
                {
                    //maap->GetJoueur()->Getsac().at(i)->GetName() << "\n";
                    Potion * p = static_cast<Potion*>(maap->GetJoueur()->Getsac().at(i));
                    //p->Getsoin() << "\n";
                }
                fichier << maap->GetJoueur()->GetPosition()->Getx() << "\n";
                fichier << maap->GetJoueur()->GetPosition()->Gety() << "\n";

                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
}
