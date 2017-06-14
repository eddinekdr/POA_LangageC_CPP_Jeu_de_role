#include "Maap.h"

#include <typeinfo>
#include <iostream>
#include <string>
#include "stdio.h"
#include "conio.h"

#include "Mur.h"
#include "Personnage.h"
#include "Monstre.h"
#include "Potion.h"

using namespace std;



Maap::Maap()
{
    //ctor
    lignes = LIGNES;
    colonnes = COLONNES;

    joueur = 0;
    adversaire = 0;

    this->plateau = new vector< vector<Element*> >;
    this->plateau->resize(lignes, vector<Element*>(colonnes));
}

Maap::~Maap()///On veille bien à libérer chaque pointeur d'Element avec de supprimmer la liste
{
    //dtor
    while(!(*this->plateau).empty())///On s'assure de bien supprimmer "tout" le plateau de jeu
    {
        for(int i=0; i<this->lignes; i++)
        {
            for(int j=0; j<this->colonnes; j++)
            {
                delete (*this->plateau).at(i).at(j);///On libère le pointeur de l'élément de cette case
                (*this->plateau).at(i).at(j) = nullptr;
            }
            (*this->plateau).at(i).clear();///On supprimme le vecteur de la "colonne"
        }
        (*this->plateau).clear();///Pour finir, on supprimme le tableau de jeu
    }
}

void Maap::dessinerLigne(int longueur, char c, bool bordure)
{
    int ajustement = 6;
    cout <<"\n                  ";///Centrer l'écran
    cout << c << c << c << c << c;     ///Bordure gauche, commence la ligne
    for(int i=0; i<longueur; i++)
    {
        if(bordure)
        {
             cout << c << c << c << c << c;
        }
        else
            cout << "      ";
    }
    if(bordure)
    {
        cout << c;
    }
    cout << c << c << c << c << c;///Bordure droite, ferme la ligne
    cout << "\n";
}

void Maap::dessinerRangee(int ligne, int longueur, int epaisseur, char c)
{
    int k=0;

    while(k<epaisseur)
    {
        cout <<"                  ";///Centrer l'écran
        cout << c;///Bordure gauche, pour debuter la ligne
        for(int j=1; j<longueur-1; j++)
        {
            if(k!=1)
            {
                if((*this->plateau).at(ligne).at(j)->getType() == MUR)
                {
                        cout << c << c << c << c << c << " ";
                }
                else
                {
                    cout << "      ";
                }
            }
            else if(k==1)
            {
                if((*this->plateau).at(ligne).at(j)->getType() == MUR)
                {
                    cout << c << c << c << c << c << " ";
                }
                else if((*this->plateau).at(ligne).at(j)->getType() == PERSONNAGE)
                {
                    cout << "o(><)/";
                }
                else if((*this->plateau).at(ligne).at(j)->getType() == ITEM)
                {
                    cout << " (O ) ";
                }
                else if((*this->plateau).at(ligne).at(j)->getType() == MONSTRE)
                {
                    cout << "^(--)^";
                }
                else if((*this->plateau).at(ligne).at(j)->getType() == VIDE)
                {
                    cout << "      ";
                }
            }
        }
        cout << c;///Bordure droite, pour fermer la ligne
        cout << "\n";
        k++;
    }
}

void Maap::dessinerGrille(char c, int hauteur, int longueur, int epaisseur)
{

    dessinerLigne(longueur,c,true);

    for(int i=1; i<hauteur-1; i++)
    {
        dessinerRangee(i, longueur,epaisseur,c);
    }
    cout << "                  ";
    for(int j=0; j<longueur*epaisseur*2-10; j++)
    {
        cout << c;
    }
}

void Maap::affichageFinal(bool enCombat)
{
    int hauteur = LIGNES;///Lignes
    int longueur = COLONNES;///Colonnes
    int epaisseur = 3;
    char c = static_cast<char>(219);

    dessinerGrille(c,hauteur,longueur,epaisseur);
    if(!enCombat)
    {
        cout << "\n\n                                                          ";
        cout << "Deplacez-vous a l'aide des fleches." << endl;
        cout << "\n                                                             ";
        cout << "7. Sac  8. Mes Sorts 9. Menu " << endl;
    }
}

void Maap::affichage()
{

    for(int i=0; i<this->lignes; i++)
    {
        for(int j=0; j<this->colonnes; j++)
        {
            if((*this->plateau).at(i).at(j)->getType() == MUR)
            {
                 cout << "*" ;
            }
            else if((*this->plateau).at(i).at(j)->getType() == PERSONNAGE)
            {
                 cout << "P" ;
            }
            else if((*this->plateau).at(i).at(j)->getType() == ITEM)
            {
                 cout << "o" ;
            }
            else if((*this->plateau).at(i).at(j)->getType() == VIDE)
            {
                cout << " ";
            }
            else if((*this->plateau).at(i).at(j)->getType() == MONSTRE)
            {
                cout << "M";
            }
        }
        cout << "\n";
    }
}

void Maap::affichageComplexe(bool enCombat)
{
    int k = 0;
    ///Petit décalage
    cout << "               ";
    for(int i=0; i<this->lignes; i++)
    {
        while(k<2)
        {
            for(int j=0; j<this->colonnes; j++)
            {
                if((*this->plateau).at(i).at(j)->getType() == MUR)
                {
                    cout << static_cast<char>(219) << static_cast<char>(219) << static_cast<char>(219);
                }
                else if((*this->plateau).at(i).at(j)->getType() == PERSONNAGE)
                {
                    cout << " P " ;
                }
                else if((*this->plateau).at(i).at(j)->getType() == ITEM)
                {
                     cout << " " << "O" << " ";
                }
                else if((*this->plateau).at(i).at(j)->getType() == MONSTRE)
                {
                    cout << static_cast<char>(200) << static_cast<char>(187) << static_cast<char>(188);
                }
                else if((*this->plateau).at(i).at(j)->getType() == VIDE)
                {
                    cout << "   ";
                }
            }
            cout << "\n               ";
            k++;
        }
        k = 0;
        //cout << "\n";
    }
    ///OPTION D'AFFICHAGE
    if(!enCombat)
    {
        cout << "\n                Deplacez-vous a l'aide des fleches." << endl;
        cout << "\n                7. Sac  8. Mes Sorts 9. Menu " << endl;
    }
}

void Maap::actualiserMaap(Element * e, int x, int y)///On créé une fonction d'ajout
{

    int lignes = y; ///Anciennes coordonnées
    int colonnes = x;

    ///Ancienne case retourne à vide
    (*this->plateau).at(lignes).erase((*this->plateau).at(lignes).begin()+colonnes);///On libère la case du vecteur pour la remplacer par la nouvelle
    (*this->plateau).at(lignes).insert((*this->plateau).at(lignes).begin()+colonnes,new Element());

    ///Case de destination
    delete (*this->plateau).at(e->GetY()).at(e->GetX());///On libère la case mémoire ! Très important
    (*this->plateau).at(e->GetY()).erase((*this->plateau).at(e->GetY()).begin()+e->GetX());///On libère la case du vecteur pour la remplacer par la nouvelle
    (*this->plateau).at(e->GetY()).insert((*this->plateau).at(e->GetY()).begin()+e->GetX(),e);
}

void Maap::collecterItem(int x, int y)
{
    (*this->plateau).at(y).erase((*this->plateau).at(y).begin()+x);///On libère la case du vecteur pour la remplacer par la nouvelle
    (*this->plateau).at(y).insert((*this->plateau).at(y).begin()+x,new Element());
}

void Maap::retirerAjouter(int x, int y, Element * nouvelleElement)
{
    delete (*this->plateau).at(y).at(x);///On libère la case mémoire ! Très important
    (*this->plateau).at(y).erase((*this->plateau).at(y).begin()+x);///On libère la case du vecteur pour la remplacer par la nouvelle
    (*this->plateau).at(y).insert((*this->plateau).at(y).begin()+x,nouvelleElement);
}

void Maap::add(Element * e)///On créé une fonction d'ajout
{

    int lignes = e->GetY();
    int colonnes = e->GetX();

     retirerAjouter(colonnes,lignes,e);

    ///On actualise la position de l'élement
    e->SetX(colonnes);///(x) correspond à l'axe des abscisses, donc au COLONNES !
    e->SetY(lignes);
}

void Maap::deplacement(Element * e, Position * nouvelle_position)///FONCTION DEPLACEMENT OFFICIELLE QUI ACTUALISE LE JEU
{
    ///On retient l'ancienne position de l'élément
    int x = e->GetX();
    int y = e->GetY();

    ///On actualise la position de l'élément
    e->SetPosition(nouvelle_position);

    ///On actualise le plateau de jeu
    actualiserMaap(e,x,y);
}

/***
    Return  0 case MUR
            1 case VIDE
            2 case OBJET
***/
int Maap::deplacementPossible(Position * positionCible)
{
    int x = positionCible->Getx();
    int y = positionCible->Gety();

    ///2e partie - La case existe t-elle ? Elle est libre ou occupée ?
    if( (y<lignes) && (y>=0) && (x<colonnes && x>=0))///On vérifie que la case ne déborde pas du tableau
    {
        if((*this->plateau).at(y).at(x)->getType() == MUR)
        {
            return 0;
        }
        else if((*this->plateau).at(y).at(x)->getType() == VIDE)
        {
            return 1;
        }
        else if((*this->plateau).at(y).at(x)->getType() == ITEM)
        {
            return 2;
        }
        else if((*this->plateau).at(y).at(x)->getType() == PJ)
        {
            return 3;
        }
        else if((*this->plateau).at(y).at(x)->getType() == PNJ)
        {
            return 4;
        }
        else if((*this->plateau).at(y).at(x)->getType() == MONSTRE)
        {
            return 5;
        }
    }
}

Position* Maap::calculDeplacement(Position * pos, int mouvement)
{
    Position * newPos = new Position();

    if(mouvement == HAUT)
    {
        newPos->Sety(pos->Gety()-1);
        newPos->Setx(pos->Getx());
    }
    else if(mouvement == BAS)
    {
        newPos->Sety(pos->Gety()+1);
        newPos->Setx(pos->Getx());
    }
    if(mouvement == DROITE)
    {
        newPos->Setx(pos->Getx()+1);
        newPos->Sety(pos->Gety());
    }
    if(mouvement == GAUCHE)
    {
        newPos->Setx(pos->Getx()-1);
        newPos->Sety(pos->Gety());
    }

    return newPos;
}

int Maap::actionsPossibles(Personnage * personnage, int mouvement)
{
    int verification;
    Position * nouvelle_pos = calculDeplacement(personnage->GetPosition(),mouvement);
    verification = deplacementPossible(nouvelle_pos);

    ///PJ
    if(verification==1)///CASE VIDE
    {
        deplacement(personnage,nouvelle_pos);
        return 3;
    }
    else if(verification==2)///ITEM
    {
        Item* item = static_cast<Item*>((*this->plateau).at(nouvelle_pos->Gety()).at(nouvelle_pos->Getx()));///On caste l'élement en item !
        Position p1 = personnage->ramasserObjet(item);///Le personnage se saisit de l'item
        if( p1.Getx() != -99)///On teste si l'objet à bien été ramassé
        {
            collecterItem(p1.Getx(),p1.Gety());///La maap est actualisé
        }
    }
    else if(verification==0)///Cas d'un déplacement impossible
    {
        ///A implémenter
    }
    else if(verification==5)///Cas d'une agression avec un monstre
    {
        ///A implémenter
        this->adversaire = static_cast<Personnage*>((*this->plateau).at(nouvelle_pos->Gety()).at(nouvelle_pos->Getx()));///On caste l'élement en personnage !
        return 5;
    }
}

/***
Retourne 3 pour un mouvement
         2 pour accéder aux sorts
         1 pour consulter le sac
***/
int Maap::choixAction()
{
    int choix;

    int c = getch();///Implémentation des touches directionnelles
    if(c == 224)
    {
        c = getch();
        if(c == 72)
        {
            fflush(0);///Très important de vider le buffers
            return actionsPossibles(this->joueur,HAUT);
        }
        else if(c == 80)
        {
            fflush(0);///Très important de vider le buffers
            return actionsPossibles(this->joueur,BAS);
        }
        else if(c == 75)
        {
            fflush(0);///Très important de vider le buffers
            return actionsPossibles(this->joueur,GAUCHE);
        }
        else if(c == 77)
        {
            fflush(0);///Très important de vider le buffers
            return actionsPossibles(this->joueur,DROITE);
        }
    }
    else if(c == 49)
    {
        return 1;
    }
    else if(c == 50)
    {
        return 2;
    }
    else if(c == 51)
    {
        return 3;
    }
    else if(c == 52)
    {
        return 4;
    }
    else if(c == 55)
    {
        return 7;
    }
    else if(c == 56)
    {
        return 8;
    }
    else if(c == 57)
    {
        return 9;
    }
    else
    {
        cout << "\n                                                             ";
        cout << "Veuillez resaisir votre choix.";
        return 0;
    }
}


void Maap::creationMaap1()
{

    ///Création de murs
    for(int i=0; i<lignes; i++)
    {
        for(int j=0; j<colonnes; j++)
        {
            if(i ==0 || i == lignes-1 || ((j == 0 || j == colonnes-1) && i!=0 && i!=lignes-1)) ///On crée le pourtour de remparts
            {
                add(new Mur(j,i));///Insertion d'un mur
            }
            else
                add(new Element(j,i));
        }
    }

    ///Positionnement de quelques murs supplémentaires
    add(new Mur(7,3));
    add(new Mur(8,3));
    //add(new Mur(9,3));
    add(new Mur(1,4));
    add(new Mur(2,4));
    add(new Mur(9,5));
    add(new Mur(3,7));
    //add(new Mur(4,7));
    add(new Mur(5,7));
    add(new Mur(6,7));
    add(new Mur(7,7));
    add(new Mur(5,8));
    add(new Mur(5,9));
    add(new Mur(1,10));
    add(new Mur(2,10));
    add(new Mur(8,10));
    add(new Mur(9,10));
    add(new Mur(2,11));
    add(new Mur(3,11));
    add(new Mur(4,11));
    add(new Mur(5,11));
    add(new Mur(8,11));
    add(new Mur(5,12));
    add(new Mur(8,12));
    add(new Mur(2,13));
    add(new Mur(3,13));
    add(new Mur(2,14));

    ///Création de potions
    add(new Potion(10,"Petite potion d'alchimie",9,1));
    add(new Potion(20,"Super potion magique",1,5));
    add(new Potion(10,"Petite potion d'alchimie",9,9));
    add(new Potion(20,"Super potion magique",1,11));
    add(new Potion(20,"Super potion magique",9,11));
    add(new Potion(30,"Hyper Potion",1,14));

    ///Création d'un monstre
    SetAdversaire(new Monstre("Dragons des sables",1,9));
    add(GetAdversaire());

    ///Création du personnage
    //joueur = joueur->saisiePersonnage();

     joueur = new Personnage();
     add(joueur);
}

void Maap::creationMaapCombat1(Personnage * joueur, Personnage * adversaire)
{
    ///Création de murs
    for(int i=0; i<lignes; i++)
    {
        for(int j=0; j<colonnes; j++)
        {
            if(i ==0 || i == lignes-1 || ((j == 0 || j == colonnes-1) && i!=0 && i!=lignes-1)) ///On crée le pourtour de remparts
            {
                add(new Mur(j,i));///Insertion d'un mur
            }
            else
                add(new Element(j,i));
        }
    }

    ///Positionnement de quelques murs supplémentaires
    add(new Mur(3,2));
    add(new Mur(3,5));
    add(new Mur(3,6));
    add(new Mur(7,4));
    add(new Mur(7,5));
    add(new Mur(7,9));
    add(new Mur(8,9));
    add(new Mur(9,9));
    add(new Mur(8,5));
    //add(new Mur(3,11));
    //add(new Mur(3,12));
    //add(new Mur(4,11));
    //add(new Mur(4,12));

    ///Positionnement de l'adversaire
    adversaire->SetX(7);
    adversaire->SetY(13);
    add(adversaire);

    ///Positionnement du personnage
    joueur->SetX(3);
    joueur->SetY(3);
     add(joueur);
}

void Maap::creationMaapCombat2(Personnage * joueur, Personnage * adversaire)
{
    ///Création de murs
    for(int i=0; i<lignes; i++)
    {
        for(int j=0; j<colonnes; j++)
        {
            if(i ==0 || i == lignes-1 || ((j == 0 || j == colonnes-1) && i!=0 && i!=lignes-1)) ///On crée le pourtour de remparts
            {
                add(new Mur(j,i));///Insertion d'un mur
            }
            else
                add(new Element(j,i));
        }
    }

    ///Positionnement de quelques murs supplémentaires
/*    add(new Mur(3,2));
    add(new Mur(3,5));
    add(new Mur(3,6));
    add(new Mur(7,4));
    add(new Mur(7,5));
    add(new Mur(7,9));
    add(new Mur(8,9));
    add(new Mur(9,9));
    add(new Mur(8,5));*/
    //add(new Mur(3,11));
    //add(new Mur(3,12));
    //add(new Mur(4,11));
    //add(new Mur(4,12));

    ///Positionnement de quelques murs supplémentaires
    add(new Mur(2,2));
    add(new Mur(2,4));
    add(new Mur(3,4));
    add(new Mur(3,7));
    add(new Mur(4,7));
    add(new Mur(5,7));
    add(new Mur(6,7));
    add(new Mur(7,7));
    add(new Mur(7,6));
    add(new Mur(2,9));
    add(new Mur(5,4));
    add(new Mur(5,5));
    add(new Mur(5,3));
    add(new Mur(6,3));
    add(new Mur(7,3));
    add(new Mur(8,3));
    add(new Mur(10,1));
    add(new Mur(10,2));
    add(new Mur(10,3));
    add(new Mur(10,4));
    add(new Mur(10,5));
    add(new Mur(10,6));
    add(new Mur(COLONNES-3,6));
    add(new Mur(COLONNES-2,6));
    add(new Mur(COLONNES-4,6));
    add(new Mur(COLONNES-4,5));
    add(new Mur(COLONNES-4,4));
    add(new Mur(14,5));
    add(new Mur(13,5));
    add(new Mur(12,5));
    add(new Mur(15,5));
    add(new Mur(12,3));
    add(new Mur(12,2));
    add(new Mur(13,2));
    add(new Mur(14,2));
    add(new Mur(9,9));
    add(new Mur(12,9));
    add(new Mur(14,9));
    add(new Mur(18,8));
    add(new Mur(COLONNES-4,3));
    add(new Mur(COLONNES-4,2));

    ///Positionnement de l'adversaire
    adversaire->SetX(10);
    adversaire->SetY(9);
    add(adversaire);

    ///Positionnement du personnage
    joueur->SetX(1);
    joueur->SetY(1);
     add(joueur);
}

void Maap::creationMaap1F()
{

    ///Création de murs
    for(int i=0; i<lignes; i++)
    {
        /*
        for(int k=0; k<colonnes; k++)///On retire toutes les cases, pour ensuite utiliser le push back et ne pas déborder
        {
            (*this->plateau).at(i).pop_back();
        }
        */
        for(int j=0; j<colonnes; j++)
        {
            if(i ==0 || i == lignes-1 || ((j == 0 || j == colonnes-1) && i!=0 && i!=lignes-1)) ///On crée le pourtour de remparts
            {
                add(new Mur(j,i));///Insertion d'un mur
            }
            else
                add(new Element(j,i));
        }
    }

    ///Positionnement de quelques murs supplémentaires
    add(new Mur(2,2));
    add(new Mur(2,4));
    add(new Mur(3,4));
    add(new Mur(3,7));
    add(new Mur(4,7));
    add(new Mur(5,7));
    add(new Mur(6,7));
    add(new Mur(7,7));
    add(new Mur(7,6));
    add(new Mur(2,9));
    add(new Mur(5,4));
    add(new Mur(5,5));
    add(new Mur(5,3));
    add(new Mur(6,3));
    add(new Mur(7,3));
    add(new Mur(8,3));
    add(new Mur(10,1));
    add(new Mur(10,2));
    add(new Mur(10,3));
    add(new Mur(10,4));
    add(new Mur(10,5));
    add(new Mur(10,6));
    add(new Mur(COLONNES-3,6));
    add(new Mur(COLONNES-2,6));
    add(new Mur(COLONNES-4,6));
    add(new Mur(COLONNES-4,5));
    add(new Mur(COLONNES-4,4));
    add(new Mur(14,5));
    add(new Mur(13,5));
    add(new Mur(12,5));
    add(new Mur(15,5));
    add(new Mur(12,3));
    add(new Mur(12,2));
    add(new Mur(13,2));
    add(new Mur(14,2));
    add(new Mur(9,9));
    add(new Mur(12,9));
    add(new Mur(14,9));
    add(new Mur(18,8));
    add(new Mur(COLONNES-4,3));
    add(new Mur(COLONNES-4,2));

    ///Création de potions
    add(new Potion(10,"Petite potion d'alchimie",6,4));
    add(new Potion(20,"Super potion magique",13,9));
    add(new Potion(10,"Petite potion d'alchimie",13,3));
    add(new Potion(20,"Super potion magique",19,5));
    add(new Potion(20,"Super potion magique",1,9));
    add(new Potion(30,"Hyper Potion",19,9));

    ///Création d'un monstre
    SetAdversaire(new Monstre("Dragons des sables",10,9));
    add(GetAdversaire());

    ///Création du personnage
    //cout << "B";
    this->joueur = joueur->saisiePersonnage();
    add(joueur);
}

void Maap::creationMaap3F()
{

    ///Création de murs
    for(int i=0; i<lignes; i++)
    {
        /*
        for(int k=0; k<colonnes; k++)///On retire toutes les cases, pour ensuite utiliser le push back et ne pas déborder
        {
            (*this->plateau).at(i).pop_back();
        }
        */
        for(int j=0; j<colonnes; j++)
        {
            if(i ==0 || i == lignes-1 || ((j == 0 || j == colonnes-1) && i!=0 && i!=lignes-1)) ///On crée le pourtour de remparts
            {
                add(new Mur(j,i));///Insertion d'un mur
            }
            else
                add(new Element(j,i));
        }
    }

    ///Positionnement de quelques murs supplémentaires
    add(new Mur(2,2));
    add(new Mur(2,4));
    add(new Mur(3,4));
    add(new Mur(3,7));
    add(new Mur(4,7));
    add(new Mur(5,7));
    add(new Mur(6,7));
    add(new Mur(7,7));
    add(new Mur(7,6));
    add(new Mur(2,9));
    add(new Mur(5,4));
    add(new Mur(5,5));
    add(new Mur(5,3));
    add(new Mur(6,3));
    add(new Mur(7,3));
    add(new Mur(8,3));
    add(new Mur(10,1));
    add(new Mur(10,2));
    add(new Mur(10,3));
    add(new Mur(10,4));
    add(new Mur(10,5));
    add(new Mur(10,6));
    add(new Mur(COLONNES-3,6));
    add(new Mur(COLONNES-2,6));
    add(new Mur(COLONNES-4,6));
    add(new Mur(COLONNES-4,5));
    add(new Mur(COLONNES-4,4));
    add(new Mur(14,5));
    add(new Mur(13,5));
    add(new Mur(12,5));
    add(new Mur(15,5));
    add(new Mur(12,3));
    add(new Mur(12,2));
    add(new Mur(13,2));
    add(new Mur(14,2));
    add(new Mur(9,9));
    add(new Mur(12,9));
    add(new Mur(14,9));
    add(new Mur(18,8));
    add(new Mur(COLONNES-4,3));
    add(new Mur(COLONNES-4,2));

    ///Création de potions
    add(new Potion(10,"Petite potion d'alchimie",6,4));
    add(new Potion(20,"Super potion magique",13,9));
    add(new Potion(10,"Petite potion d'alchimie",13,3));
    add(new Potion(20,"Super potion magique",19,5));
    add(new Potion(20,"Super potion magique",1,9));
    add(new Potion(30,"Hyper Potion",19,9));

    ///Création d'un monstre
    SetAdversaire(new Monstre("Dragons des sables",10,9));
    add(GetAdversaire());

    ///Création du personnage
    //cout << "B";
    add(joueur);
}

void Maap::creationMaap2F()
{

    ///Création de murs
    for(int i=0; i<lignes; i++)
    {
        for(int j=0; j<colonnes; j++)
        {
            if(i ==0 || i == lignes-1 || ((j == 0 || j == colonnes-1) && i!=0 && i!=lignes-1)) ///On crée le pourtour de remparts
            {
                add(new Mur(j,i));///Insertion d'un mur
            }
            else
                add(new Element(j,i));
        }
    }

    ///Positionnement de quelques murs supplémentaires
    add(new Mur(2,2));
    add(new Mur(3,2));
    add(new Mur(4,2));
    add(new Mur(2,4));
    add(new Mur(3,4));
    add(new Mur(4,4));
    add(new Mur(6,1));
    add(new Mur(6,2));
    add(new Mur(6,4));
    add(new Mur(6,5));
    add(new Mur(6,6));
    add(new Mur(7,6));
    add(new Mur(8,6));


    ///Création de potions
    /*
    add(new Potion(10,"Petite potion d'alchimie",6,4));
    add(new Potion(20,"Super potion magique",13,9));
    add(new Potion(10,"Petite potion d'alchimie",13,3));*/
    add(new Potion(20,"Super potion magique",19,5));
    add(new Potion(20,"Super potion magique",1,9));/*
    add(new Potion(30,"Hyper Potion",19,9));*/

    ///Création d'un monstre
    SetAdversaire(new Monstre("Argadon malefique",10,9));
    add(GetAdversaire());

    ///Création du personnage
    joueur->SetX(13);
    joueur->SetX(3);
    add(joueur);
}
