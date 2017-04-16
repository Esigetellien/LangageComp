#ifndef LANGUAGE_H_INCLUDED
#define LANGUAGE_H_INCLUDED

#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

class Langage
{
    public:

        Langage();
        void afficherGrammaire();
        void afficherEtatsEtTerminaux();
        void recupEtats();
        void recupTerminal();
        void recupSRecursivite();
        void afficherGrammaireSRecursivite();
        char trouverEtatLibre();
        void PremiersSuivants();
        void Premiers(int a, char IndiceEtats);
         void AffichagePremiers();
          bool EstTerminal(char monEtat);
        //void DeterminerNbRegles();
    private:

        int term;//nombre d'etats terminaux
        std::vector<char> etats;
        std::vector<bool> terminaux;
        std::vector<std::vector<char> > imports;
        std::vector<std::vector<char> > sRecursivite;

        // Pas utilisés, a voir pour le bon type
        std::vector<std::vector<char> > premiers;
        std::vector<std::vector<char> > suivants;
        std::vector<std::vector<char> > tAnalyse;
        std::vector<char> reglesAnalyse;
        //std::vector<char> nbReglesC;
        //std::vector<int> nbReglesI;
}                                                                                                                                                    ;


#endif // LANGUAGE_H_INCLUDED
