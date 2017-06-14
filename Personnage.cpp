#include "Personnage.h"
#include "Potion.h"

#include <ctime>
#include "conio.h"
#include "windows.h"

Personnage::Personnage()
{
    //ctor
    this->type = PERSONNAGE;
    nom = "Ragnar le Puissant";
    vie = 100;
    PA = 7;
    PM = 3;
    initiative = 100;
    resistance = 80;
    pointsCaracteristiques = 0;
    this->pos = new Position(1,1);
    this->caracteristique = new Caracteristique();
    this->arme = 0;
    vector<Sort*> sorts();
    ajouterSort();

    vector<Item*> sac ();
}

Personnage::Personnage(string unNom, int uneVie, int desPA, int desPM, int uneInitiative,Caracteristique * carac, int x, int y)
{
    //ctor
    this->type = PERSONNAGE;
    nom = unNom;
    vie = uneVie;
    PA = desPA;
    PM = desPM;
    initiative = uneInitiative;
    pointsCaracteristiques = NB_POINTS;
    this->pos = new Position(x,y);
    caracteristique = carac;
    this->arme = new Arme();
    vector<Sort*> sorts();
    ajouterSort();

    vector<Item*> sac ();
}

Personnage* Personnage::saisiePersonnage()
{

    string unNom = "";
    int uneVie;
    int desPA;
    int desPM;
    int uneInitiative;
    int uneResistance;

    cout << "\n                                        ";
    cout << "Veuillez choisir le nom de votre personnage:" <<endl;
    cout << "\n                                                              ";
    cin >> unNom;
    desPA = 6;
    desPM = 3;
    uneVie = 64;
    uneResistance = 70;
    uneInitiative = 100;
    system("cls");
    cout << "\n                                     ";
    cout << "Vous disposez de " << uneVie <<" points de vie de base et de " << uneInitiative <<" points d'initiatives." <<endl;
    cout << "\n                                     ";
    cout << "Vous avez " << NB_POINTS << " a affecter a " << unNom << "." <<endl;
    Sleep(2500);

    return new Personnage(unNom,uneVie,desPA,desPM,uneInitiative,distributionCaracteristique(unNom,uneVie,uneInitiative,uneResistance),1,1);
}

Caracteristique* Personnage::distributionCaracteristique(string unNom, int &uneVie, int &uneInitiative, int &uneResistance)
{
    int nombre;
    int i = 0;
    bool sortie = false;
    Caracteristique * carac = new Caracteristique();
    int ptsCarac = NB_POINTS;
    do
    {
        nombre = 0;
        if(ptsCarac>0)
        {
            string mot = listeCaracteristiques(i);
            system("cls");
            cout << "\n      Combien de points souhaitez-vous affecter a " << listeCaracteristiques(i) << " de " << unNom << " ?" << endl;
            cout << "\n             a. Terminer - Points restants: " << ptsCarac <<endl;
            cout << "\n             ";
            cin >> nombre;
            if(nombre == 97)
            {
                sortie = true;
            }
            else
            {
                if(saisiePossible(ptsCarac,nombre))///Passage de paramètres par références
                {
                    switch(i) {
                        case 0 :
                                uneVie += nombre;
                                break;
                        case 1 :
                                uneInitiative += nombre;
                                break;
                        case 2 :
                                uneResistance += nombre;
                                break;
                        case 3 :
                                carac->SetAgilite(carac->GetAgilite()+nombre);
                                break;
                        case 4 :
                                carac->Setintelligence(carac->Getintelligence()+nombre);
                                break;
                        case 5 :
                                carac->Setforce(carac->Getforce()+nombre);
                                break;
                    }
                    ptsCarac -= nombre;
                    i++;
                    if(i==6)
                        i=0;
                }
            }
        }
        else
        {
            cout << "\n             Il ne vous restes pas assez de points pour effectuer cette action." << endl;
        }
    }while(ptsCarac>0 && !sortie);

    return carac;
}

string Personnage::listeCaracteristiques(int i)
{
    string tab[6] = {"la vie","l'initiative","la resistance","l'agilite","l'intelligence","la force"};

    return tab[i];
}

bool Personnage::saisiePossible(int &desPointsCaracteristiques, int &nbCaracteristiques)
{
    if(desPointsCaracteristiques-nbCaracteristiques>=0)
        return true;
    else
        return false;
}

Personnage::Personnage(int x, int y)
{
    this->type = PERSONNAGE;
    this->pos = new Position(x,y);
}

Personnage::~Personnage()
{
    //dtor
    delete caracteristique;
    caracteristique = nullptr;

    delete arme;
    arme = nullptr;

    for(int i=0;i<sorts.size();i++)
    {
        delete sorts.at(i);
        sorts.at(i) = nullptr;
    }
    for(int i=0;i<sac.size();i++)
    {
        delete sorts.at(i);
        sac.at(i) = nullptr;
    }
    //cout << "Suppression d'un personnage " << endl;
}

Personnage::Personnage(const Personnage& other)
{
    //copy ctor
}

void Personnage::Setvie(int val)///La vie ne peut pas être négative
{
    if(val<=0)
    {
        cout << "\n                                                              ";
        cout << Getnom() << " est mort !" <<endl;
        vie = 0;
    }
    else
    {
       vie = val;
    }
}

Personnage& Personnage::operator=(const Personnage& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

int Personnage::afficherSac()
{

    cout << "\n                                                              ";
    cout << "Contenu du Sac: ";
    if(this->sac.size()==0)
    {
        cout << " Vide." << endl;
    }
    else
    {
        for(int i=0; i<this->sac.size(); i++)
        {
            cout << "\n                                                              ";
            cout << i+1 << ". " << this->sac.at(i)->GetName() << " " << endl;
        }
    }
    cout << "\n\n                                                              ";
    cout << "Entree pour quitter," <<endl;
    int choix = getch();

    return choix;
}

int Personnage::gererSac()
{
    int choix = afficherSac();
    if(choix!=13)
    {
        choix -= 49;
    }
    int reponse;

    while(choix != 13)
    {
        cout << "\n                                                            ";
        cout << "Souhaitez-vous utiliser ";
        cout << this->sac.at(choix)->GetName() << "?" <<endl;
        cout << "\n                                                            ";
        cout << "1. Oui  2. Non" << endl;
        cin >> reponse;
        if(reponse==1){
            utiliserPotion(choix);
            choix = 13;
        }
        else{
            cout << choix;
            choix = 13;
        }
    }

    return choix;
}

void Personnage::afficherSort()
{
    cout << "                                                             ";
    cout << "Mes Sorts:\n\n";
    if(this->sorts.size()==0)
    {
        cout << "                                                ";
        cout << "Aucun sorts." << endl;
    }
    else
    {
        for(int i=0; i<this->sorts.size(); i++)
        {
            cout << "                                                             ";
            cout << i+1 << "." << this->sorts.at(i)->GetName() << "" << endl;
        }
    }
    cout << "\n                                                             ";
    cout << "Appuyez une touche pour quitter," <<endl;
    getch();
}

void Personnage::supprimerUnObjetDuSac(int choix)
{
    this->sac.erase(this->sac.begin()+choix);
}

/***Retourne 1 si l'objet est supprimmé, et 0 sinon***/
int Personnage::jeterObjet()
{
    cout << "\n                                                ";
    cout << "De quel item voulez-vous vous débarasser ?" << endl;
    afficherSac();
    cout << "\n                                                ";
    cout << "0. Annuler" <<endl;
    int choix;
    cin >> choix;
    if(choix>0 && choix<=this->sac.size())
    {
        supprimerUnObjetDuSac(choix-1);
        return 1;
    }

    return choix;
}

Position Personnage::ramasserObjet(Item * item)
{
    int choix;
    cout << " ";
    cout << "\n\n                                                               ";
    cout << "Ramasser x1 \"" << item->GetName() << "\" ?" << endl;
    cout << "\n                                                                 ";
    cout << "1. Oui     2. Non" << endl;
    choix = getch();
    if(choix == 49)
    {
        if(this->sac.size()>=TAILLE_MAX)
        {
            cout << "                                                ";
            cout << "Sac plein.\n";
            cout << "                                                ";
            cout << "Impossible de ramasser l'objet !" << endl;
            choix = jeterObjet();
            if(choix == 1)
            {
                return Position(-99,-99);
            }
        }
        else
        {
            this->sac.push_back(item);
            cout << "\n                                                ";
            cout << "Objet collecte !" << endl;
            Sleep(500);
        }
    }
    else
    {
        return Position(-99,-99);
    }

    return Position(item->GetX(),item->GetY());
}

bool Personnage::attaquePossible(int val)
{
    if(Getsorts().at(val-1)->GetcoutPA() <= PA)
        return true;
    else
        return false;
}

int Personnage::lancerUnSort(int choix)
{
    cout << "\n                                           ";
    cout << nom << " utilise " << sorts.at(choix)->GetName() << "." << endl;
    if(sorts.at(choix)->Getnature() == "soin")
    {
        cout << "\n                                           ";
        cout << nom << " se regenere de " << sorts.at(choix)->Getsoin() << " pts de vie." << endl;
        vie += sorts.at(choix)->Getsoin();
        return 0;
    }
    else if(sorts.at(choix)->Getnature() == "armure")
    {
        cout << "\n                                           ";
        cout << nom << " ameliore sa resistance de " << sorts.at(choix)->Getdommage() << " %." << endl;
        resistance += sorts.at(choix)->Getdommage();
        return 0;
    }
    else
    {
        return sorts.at(choix)->Getdommage();
    }
}

int Personnage::attaquer(int choix)
{
    if(choix == 0)
    {
        return Getarme()->Getdommages();
    }
    else
    {
        return lancerUnSort(choix);
    }
}

int Personnage::choixDeplacement()/***Renvoie 0 en cas d'erreur***/
{
    int choix  = getch();///Implémentation des touches directionnelles
    if(choix == 224)
    {
        choix = getch();
        fflush(0);
        switch(choix)
        {
            case(72):
                return HAUT;
            case(80):
                return BAS;
            case(75):
                return GAUCHE;
            case(77):
                return DROITE;
            default:
                return 0;
        }
    }
    else
    {
        return 0;
    }
}

Position Personnage::calculDeplacement(int mouvement)
{
    switch(mouvement)
    {
    case(HAUT):
       return Position(GetX(),GetY()-1);
    case(BAS):
        return Position(GetX(),GetY()+1);
    case(GAUCHE):
        return Position(GetX()-1,GetY());
    case(DROITE):
        return Position(GetX()+1,GetY());
    }
}

Position Personnage::simulationDeplacement()///On demande l'autorisation à la maap
{
    return calculDeplacement(choixDeplacement());
}

Position Personnage::requeteDeplacement()
{
    cout << "Utilisez les touches directionnelles." <<endl;
    return simulationDeplacement();

}

void Personnage::deplacer(int mouvement)
{
    pos = 0;
    delete pos;

    switch(mouvement)
    {
    case(HAUT):
       delete pos;
       pos = new Position(GetX(),GetY()-1);
       break;
    case(BAS):
       pos = new Position(GetX(),GetY()+1);
       break;
    case(GAUCHE):
        pos = new Position(GetX()-1,GetY());
        break;
    case(DROITE):
        pos = new Position(GetX()+1,GetY());
        break;
    }
}

void Personnage::ajouterSort()
{
    this->sorts.resize(4);

    ///AJOUT DES SORTS
    this->sorts.erase(this->sorts.begin());
    this->sorts.insert(this->sorts.begin(),this->sorts.at(0)->creationSort(0));
    this->sorts.erase(this->sorts.begin()+1);
    this->sorts.insert(this->sorts.begin()+1,this->sorts.at(0)->creationSort(1));
    this->sorts.erase(this->sorts.begin()+2);
    this->sorts.insert(this->sorts.begin()+2,this->sorts.at(0)->creationSort(2));
    this->sorts.erase(this->sorts.begin()+3);
    this->sorts.insert(this->sorts.begin()+3,this->sorts.at(0)->creationSort(3));
}

void Personnage::ajouterSortMonstre()
{
    this->sorts.resize(4);

    ///AJOUT DES SORTS
    this->sorts.erase(this->sorts.begin());
    this->sorts.insert(this->sorts.begin(),this->sorts.at(0)->creationSort(5));
    this->sorts.erase(this->sorts.begin()+1);
    this->sorts.insert(this->sorts.begin()+1,this->sorts.at(0)->creationSort(6));
    this->sorts.erase(this->sorts.begin()+2);
    this->sorts.insert(this->sorts.begin()+2,this->sorts.at(0)->creationSort(7));
    this->sorts.erase(this->sorts.begin()+3);
    this->sorts.insert(this->sorts.begin()+3,this->sorts.at(0)->creationSort(8));
}

void Personnage::utiliserPotion(int choix)
{
    Potion * p = static_cast<Potion*>(this->sac.at(choix));
    this->vie += p->Getsoin();
    p = 0;
    this->sac.at(choix) = 0;
    this->sac.erase(this->sac.begin()+choix);
}
