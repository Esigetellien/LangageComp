#include "Language.h"

using namespace std;

/*Détermine si une phrase peut être lu par une grammaire
 1. Saisir une phrase puis la stockée dans une pile
 2. Lire la phrase à l'aide de la table d'analyse*/

// Saisir la chaine
string saisir()
{
    string phrase = "";

    do
    {
        cout << "Ecrire la phrase a analyser :" << endl;
        cin >> phrase;
    }while(pocedeDollars(phrase));//vérifier phrase!=0 ?

    return phrase;
}

// La phrase ne doit pas contenir de dollars
bool pocedeDollars(string phrase)
{
    for(unsigned i = 0; i < phrase.size(); i++)
    {
        if(phrase[i] == '$')
            return true;
    }
    return false;
}

// empiler la chaine
void Langage::empiler(string saisie)
{
    // ajouter le symbole terminal
    saisie += '$';

    // recopier chacun des caractères de la saisie dans la phrase en commençant par la fin
    for(int i=saisie.size()-1; i>=0; i--)
    {
        phrase.push(saisie[i]);
    }

    /*cout << endl << "La phrase push dans la pile est la suivante :" << endl;
    afficher(phrase);
    cout << endl;*/ // à supprimer

    return;
}

void afficher(const stack<char>& p)
{
        stack<char> t = p;
        while(!t.empty())
        {
                cout << t.top();
                t.pop();
                if(!t.empty())
                        cout << " , ";
        }
}

// lire la phrase
bool Langage::compiler()
{
    // initialiser la sortie
    sortie.push('$');
    char etatInitial = etats[0];
    sortie.push(etatInitial);

    char ctr_phrase;
    char ctr_sortie;

    // Tant que phrase est non vide
    while(!phrase.empty())
    {
        // afficher les deux piles
        cout << endl << "Caracteres de la phrase : ";
        afficher(phrase);
        cout << endl;
        cout << "Caracteres de la sortie : ";
        afficher(sortie);
        cout << endl;

        // Dépiler les deux piles
        ctr_phrase = phrase.top();
        ctr_sortie = sortie.top();

        //Si le dernier caractère de sortie = dernier caractère de la phrase alors dépiler les caracteres de phrase et sortie
        if(ctr_phrase == ctr_sortie)
        {
            phrase.pop();
            sortie.pop();
        }
        //Sinon
        else
        {
            // Parcourir les lignes de la table
            for(int i=0; i<(int)analyse.size(); i++)
            {
                // Trouver celle correspondant au premier caractère de la sortie
                if(analyse[i][0] == ctr_sortie)
                {
                    // Parcourir les colonnes de la table
                    for(int j=0; j<(int)analyse[i].size(); j++)
                    {
                        // Trouver celle correspondant au premier caractère de la phrase
                        if((char)analyse[0][j] == (char)ctr_phrase)
                        {
                            cout << "Regle utilisee : " << (int)analyse[i][j] << endl << endl;

                            // Analyser la règle
                            // Si # alors dépiler uniquement la sortie
                            if(ctr_sortie == '#')
                            {
                                sortie.pop();
                            }
                            // Si aucune règle possible alors retourner faux
                            else if(analyse[i][j] == 0)
                            {
                                return false;
                            }
                            // Sinon échanger le caractère de sortie et la nouvelle règle
                            else
                            {
                                /*for (unsigned int y=0; y<imports[(int)analyse[i][j]].size(); y++)
                                {
                                    cout << " " << imports[(int)analyse[i][j]][y];
                                    if (y==0) cout << " -> ";
                                    if (y==imports[(int)analyse[i][j]].size()-1)
                                        cout << endl;
                                }*/

                                // dépiler le caractère de la sortie
                                sortie.pop();

                                // Empiler la nouvelle règle
                                for(int k=sRecursivite[analyse[i][j]-1].size()-1; k>0; k--)
                                {
                                    if(sRecursivite[((int)analyse[i][j])-1][k] != '#')
                                        sortie.push(sRecursivite[((int)analyse[i][j])-1][k]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
}

void Langage::reconnaissance()
{
    string phrase = saisir();
    empiler(phrase);
    if(compiler()) cout << endl << endl << "phrase reconnaissable par la grammaire" << endl << endl;
    else cout << endl << endl << "phrase non reconnaissable par la grammaire" << endl << endl;
}
