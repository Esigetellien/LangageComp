#include <iostream>
#include "Language.h"


using namespace std;

string saisieFichier()
{
    system("CLS");
    string menu;
    cout << endl;
    cout << "==== Selection du fichier ====" << endl;
    cout << "    1. fichierTest1.txt" << endl;
    cout << "    2. fichierTest2.txt" << endl;
    cout << "    3. fichierTest3.txt" << endl;
    cout << "    4. fichierTest4.txt" << endl;
    cout << "    5. Saississez votre propre fichier" << endl;
    cout << "    0. Quitter" << endl << endl;

    bool verif = false;

    while (!verif)
    {
        cout << " Veuillez choisir une option" << endl;
        cin >> menu;

        if (menu == "1")
        {
            menu = "fichierTest1.txt";
            verif = true;
        }
        else if (menu == "2")
        {
            menu = "fichierTest2.txt";
            verif = true;
        }
        else if (menu == "3")
        {
            menu = "fichierTest3.txt";
            verif = true;
        }
        else if (menu == "4")
        {
            menu = "fichierTest4.txt";
            verif = true;
        }
        else if (menu == "5")
        {
            cout << " Veuillez entrer le nom du fichier (ne pas oublier l'extension .txt)" << endl;
            cin  >> menu;
            ifstream fichier (menu.c_str(), ios::in);
            if (fichier)
            {
                verif = true;
                fichier.close();
            }

            else
            {
                cout << " Erreur de saisie, le fichier specifie n'existe pas" << endl;
            }
        }
         else if (menu == "6")
        {
            menu = "fichierTestFollows.txt";
            verif = true;
        }

        else if (menu == "0")
        {
            cout<<"\n\n\n\nDeveloppe par Duhamel Bertrand, Gouessant Claire," << endl << "              Laversanne Vincent, Zuber Thibault."<<endl;
            exit(EXIT_SUCCESS);
        }
    }
    cout << " L'analyse va etre lance sur ce fichier" << endl;
   // system("PAUSE");
    return menu;
}

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

    bool verif = true;
    while (verif)
    {
        Langage premier(saisieFichier());
        premier.afficherGrammaire();
        premier.recupEtats();
        premier.recupTerminal();
        premier.afficherEtatsEtTerminaux();
       // system("PAUSE");
        premier.recupSRecursivite();
        premier.afficherGrammaireSRecursivite();
        premier.afficherEtatsEtTerminaux();
        //system("PAUSE");
        premier.PremiersSuivants();
        premier.AffichagePremiers();
        premier.AffichageSuivants();

        premier.Analyse();

        system("PAUSE");
    }


    /*  //premier.Creation();


    }while(choix != 3);
    cout<<"\n\nDevelopper par Duhamel Bertrand, Gouessant Claire, Laversanne Vincent, Zuber Thibault"<<endl;*/
    return 0;
}
