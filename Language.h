#ifndef LANGUAGE_H_INCLUDED
#define LANGUAGE_H_INCLUDED

#include <vector>

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

    private:

        std::vector<char> etats;
        std::vector<bool> terminaux;
        std::vector<std::vector<char> > imports;
        std::vector<std::vector<char> > sRecursivite;

        // Pas utilisés, a voir pour le bon type
        std::vector<std::vector<char> > premiers;
        std::vector<std::vector<char> > suivants;
        std::vector<std::vector<char> > tAnalyse;
        std::vector<char> reglesAnalyse;
}                                                                                                                                                    ;


#endif // LANGUAGE_H_INCLUDED
