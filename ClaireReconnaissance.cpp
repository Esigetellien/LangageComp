#include "Language.h"

using namespace std;

/*D�termine si une phrase peut �tre lu par une grammaire
 1. Saisir une phrase puis la stock�e dans une pile
 2. Lire la phrase � l'aide de la table d'analyse*/

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

    // recopier chacun des caract�res de la saisie dans la phrase en commen�ant par la fin
    // attention � bien commencer par la fin de la saisie ($)

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
        //Si le dernier caract�re de sortie = dernier caract�re de la phrase alors d�piler les deux
        //Sinon
            // Parcourir les lignes de la table
            // Trouver celle correspondant au premier caract�re de la sortie
                // Parcourir les colonnes de la table
                // Trouver celle correspondant au premier caract�re de la phrase
                    // Analyser la r�gle
                    // Si # alors d�piler la sortie
                    // Sinon �changer le caract�re de sortie et la nouvelle r�gle
                        // D�piler le caract�re de sortie
                        // Empiler la nouvelle r�gle

                    // Si aucune r�gle possible alors retourner faux
    //Recommencer

    return true;
}
