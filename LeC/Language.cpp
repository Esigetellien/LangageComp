#include <iostream>
#include <vector>
#include "Language.h"

using namespace std;

Langage::Langage()
{
    // Tableau "importé" codé directement pour les tests. Exercice 1, analyseurs LL(1)
    imports.push_back(vector<char>(4));
    imports.push_back(vector<char>(2));
    imports.push_back(vector<char>(4));
    imports.push_back(vector<char>(2));
    imports.push_back(vector<char>(4));
    imports.push_back(vector<char>(4));
    imports[0][0]='S';
    imports[0][1]='(';
    imports[0][2]='L';
    imports[0][3]=')';
    imports[1][0]='S';
    imports[1][1]='a';
    imports[2][0]='L';
    imports[2][1]='L';
    imports[2][2]=',';
    imports[2][3]='S';
    imports[3][0]='L';
    imports[3][1]='S';


    imports[4][0]='E';
    imports[4][1]='L';
    imports[4][2]=',';
    imports[4][3]='S';
    imports[5][0]='E';
    imports[5][1]='[';
    imports[5][2]='b';
    imports[5][3]=']';

}

void Langage::recupTerminal()
{
    for (unsigned int x=0; x<etats.size(); x++) // les ints sont en unsigned simplement pour éviter un warning avec la comparaison de vector<>::size()
    {
        terminaux.push_back(true);
    }
    for (unsigned int x=0; x<etats.size(); x++)
    {
        for (unsigned int y=0; y<imports.size(); y++)
        {
            if (etats[x]==imports[y][0])
            {
                    terminaux[x] = false;
            }
        }
    }
}

void Langage::recupEtats() // ceci sera a refaire des que l'importation des fichiers de grammaire sera complétement fini
{
    etats.push_back(imports[0][0]);
    for (unsigned int x=0; x<imports.size(); x++) // les ints sont en unsigned simplement pour éviter un warning avec la comparaison de vector<>::size()
    {
        for (unsigned int y=0; y<imports[x].size(); y++)
        {
            for (unsigned int z=0; z<etats.size(); z++)
            {
                if (imports[x][y] == etats[z])
                {
                    z = etats.size();
                }
                else if (z==etats.size()-1)
                {
                    etats.push_back(imports[x][y]);
                }
            }
        }
    }
}

void Langage::afficherGrammaire()
{
    cout << endl;
    for (unsigned int x=0; x<imports.size(); x++) // les ints sont en unsigned simplement pour éviter un warning avec la comparaison de vector<>::size()
    {
        for (unsigned int y=0; y<imports[x].size(); y++)
        {
            cout << " " << imports[x][y];
            if (y==0){cout << " -> ";}
            if (y==imports[x].size()-1){cout << endl;}
        }
    }
    cout << endl;
}

void Langage::afficherEtatsEtTerminaux()
{
    cout << "etat  terminal" << endl;
    for (unsigned int i=0; i<etats.size(); i++)
    {
        cout << " " << etats[i] << "     " << terminaux[i] << endl;
    }
    cout <<  endl;
}

