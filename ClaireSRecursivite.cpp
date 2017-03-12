#include <iostream>
#include <vector>
#include "Language.h"

using namespace std;

void Langage::recupSRecursivite()
{
    // Tableau "sRecursivite" codé directement pour les tests.
    sRecursivite.push_back(vector<char>(4));
    sRecursivite.push_back(vector<char>(2));
    sRecursivite.push_back(vector<char>(3));
    sRecursivite.push_back(vector<char>(4));
    sRecursivite.push_back(vector<char>(2));
    sRecursivite[0][0]='S';
    sRecursivite[0][1]='(';
    sRecursivite[0][2]='L';
    sRecursivite[0][3]=')';
    sRecursivite[1][0]='S';
    sRecursivite[1][1]='a';
    sRecursivite[2][0]='L';
    sRecursivite[2][1]='S';
    sRecursivite[2][2]='l';
    sRecursivite[3][0]='l';
    sRecursivite[3][1]=',';
    sRecursivite[3][2]='S';
    sRecursivite[3][3]='l';
    sRecursivite[4][0]='l';
    sRecursivite[4][1]='#';
}

void Langage::afficherGrammaireSRecursivite()
{
    cout << "Gramaire sans recursivite" << endl;
    for (unsigned int x=0; x<sRecursivite.size(); x++)
    {
        cout << " " << sRecursivite[x][0] << " ->";;
        for (unsigned int y=1; y<sRecursivite[x].size(); y++)
        {
            cout << " " << sRecursivite[x][y];
        }
        cout << endl;
    }
    cout << endl;
}
