#ifndef LANGUAGE_H_INCLUDED
#define LANGUAGE_H_INCLUDED

#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>

class Langage
{
public:

    Langage(std::string menu);
    ~Langage();
    void afficherGrammaire();
    void afficherEtatsEtTerminaux();
    void recupEtats();
    void recupTerminal();
    void recupSRecursivite();
    void afficherGrammaireSRecursivite();
    char trouverEtatLibre();
    char trouverEtatLibre(char ancLettre);
    void PremiersSuivants();
    void Premiers(int a, char IndiceEtats, std::vector<char>DejaTraite);
    void AffichagePremiers();
    bool EstTerminal(char monEtat);
    std::vector<char>Suivants(int b, char IndiceEtats, std::vector<char>DejaTraite2);
    std::vector<char> SuivantsR2(int b,int i, int j, char IndiceEtats, std::vector<char>DejaTraite2);
    bool TestSPresent(char MaValeur, char IndiceEtats);
    void AffichageSuivants();

    void AnalyseInit();
    void Analyse();
    void testPremiers(int i, int j, int k);
    void testSuivants(int i, int j, int k);
    void affichageTableA();
    //void DeterminerNbRegles();
    void empiler(std::string saisie);
    bool analyser();

    void Creation();
    void DeterminerNbRegles();

private:

    int term;//nombre d'etats terminaux
    std::vector<char> etats;
    std::vector<bool> terminaux;
    std::vector<std::vector<char> > imports;
    std::vector<std::vector<char> > sRecursivite;

    // Pas utilisés, a voir pour le bon type
    std::vector<std::vector<char> > premiers;
    std::vector<std::vector<char> > suivants;
    //std::vector<std::vector<char> > tAnalyse;
   // std::vector<char> reglesAnalyse;
    std::vector<std::vector<char> > analyse;
    //std::vector<char> nbReglesC;
    //std::vector<int> nbReglesI;
    std::stack<char> phrase;
    std::stack<char> sortie;
}
                                                                                                                                                  ;
std::string saisir();
bool pocedeDollars(std::string phrase);

#endif // LANGUAGE_H_INCLUDED
