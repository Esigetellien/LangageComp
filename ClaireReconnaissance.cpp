#include "Language.h"

using namespace std;

/*Détermine si une phrase peut être lu par une grammaire
 1. Saisir une phrase puis la stockée dans une pile
 2. Lire la phrase à l'aide de la table d'analyse*/

// Saisir la chaine
string saisir()
{
    /// A faire

    return "rien";
}

// empiler la chaine
void Langage::empiler(string saisie)
{
    // ajouter le symbole terminal
    saisie += '$';

    // recopier chacun des caractères de la saisie dans la phrase en commençant par la fin
    // attention à bien commencer par la fin de la saisie ($)

    /// A faire

    return;
}

// lire la phrase
bool Langage::analyser()
{
    // initialiser la sortie
    sortie.push('$');
    char etatInitial = etats[0];
    sortie.push(etatInitial);

    /// A faire
    // Tant que phrase est non vide
        //Si le dernier caractère de sortie = dernier caractère de la phrase alors dépiler les deux
        //Sinon
            // Parcourir les lignes de la table
            // Trouver celle correspondant au premier caractère de la sortie
                // Parcourir les colonnes de la table
                // Trouver celle correspondant au premier caractère de la phrase
                    // Analyser la règle
                    // Si # alors dépiler la sortie
                    // Sinon échanger le caractère de sortie et la nouvelle règle
                        // Dépiler le caractère de sortie
                        // Empiler la nouvelle règle

                    // Si aucune règle possible alors retourner faux
    //Recommencer

    return true;
}
