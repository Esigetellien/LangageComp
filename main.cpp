#include <iostream>
#include "Language.h"


using namespace std;


int main()
{

    /*int choix = 0;
    do
    {
        system("CLS");
        cout<<"==== Projet de Langage et Compilation ====\n"<<endl;
        cout<<"       ==== Analyseur Ascendant ===\n"<<endl;

        // Faire une saisie securisee
        cout<<"\n\n1.Charger un fichier.txt\n2.Lancer l'analyse descendante\n3.Quitter\n\n"<<endl;
        cout<<"Votre choix: ";
        cin>>choix;
        ///////////////////////////////////////////////
        switch(choix)
        {
            case 1:
            {
            }break;

            case 2:
            {
              system("PAUSE");
            }break;

            case 3:
            {
                cout<<"\n\n\n\nDeveloppé par Duhamel Bertrand, Gouessant Claire, Laversanne Vincent, Zuber Thibault"<<endl;
            }
            default:
            {
                cout<<"Erreur !!!!!"<<endl;
            }break;
        }*/

    Langage premier;
    premier.afficherGrammaire();
    premier.recupEtats();
    premier.recupTerminal();
    premier.afficherEtatsEtTerminaux();
    premier.recupSRecursivite();
    premier.afficherGrammaireSRecursivite();
    premier.afficherEtatsEtTerminaux();
    premier.PremiersSuivants();
    premier.AffichagePremiers();
    /*  //premier.Creation();
     system("PAUSE");

    }while(choix != 3);
    cout<<"\n\nDevelopper par Duhamel Bertrand, Gouessant Claire, Laversanne Vincent, Zuber Thibault"<<endl;*/
    return 0;
}
