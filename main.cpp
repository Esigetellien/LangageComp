#include <iostream>
#include <vector>
#include "Language.h"


using namespace std;


int main()
{

    Langage premier;

    premier.afficherGrammaire();

    premier.recupEtats();

    premier.recupTerminal();

    premier.afficherEtatsEtTerminaux();

    premier.recupSRecursivite();

    premier.afficherGrammaireSRecursivite();

    return 0;
}
