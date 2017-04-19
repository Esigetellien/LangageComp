#include "Language.h"

using namespace std;

//std::vector<std::vector<char> > premiers;

bool Langage:: EstTerminal(char monEtat)
{
    for(unsigned int i=0; i<etats.size(); i++)
    {
        if(etats[i]==monEtat)
        {
            if(terminaux[i]== 0)
            {
                return false;
            }

            if(terminaux[i]==1)
            {
                return true;
            }
        }
    }
    return false;
}
void Langage::PremiersSuivants()
{
    int a = 0;
    int b =0;
    vector <char> DejaTraite;
    vector <char> DejaTraite2;
    for( unsigned int i=0; i<etats.size(); i++ )
    {
        if(terminaux[i]== 0)
        {
            premiers.push_back(vector<char>());
            premiers[a].push_back(etats[i]);
            Premiers(a, etats[i],DejaTraite);
            a++;
        }

    }
      for( unsigned int i=0; i<etats.size(); i++ )//On a besoin que le tab de premier soit completement remplie
       {
           if(terminaux[i]== 0)
           {
               suivants.push_back(vector<char>());
               suivants[b].push_back(etats[i]);
               DejaTraite2.push_back(etats[i]);
              Suivants(b, etats[i], DejaTraite2);// Appel de la fonction premier qui va donner la liste des premiers de l'etat[i] non terminaux
              for(int k=0;k<DejaTraite2.size();k++)
              {
                  DejaTraite2.pop_back();
              }
               b++;
           }
        }
}
void Langage::Premiers(int a,char IndiceEtats,vector<char> DejaTraite)
{

    bool monEtat=false;
    bool testFin = false;
    bool present =false;
    DejaTraite.push_back(IndiceEtats);
    for(unsigned int i=0; i<sRecursivite.size(); i++)
    {
        //  cout<<"taille: "<<sRecursivite.size()<<endl;
        present =false;
        if(IndiceEtats == sRecursivite[i][0])
        {
            monEtat= EstTerminal(sRecursivite[i][1]);
            for(unsigned int l=0; l<premiers[a].size(); l++)
            {
                if(premiers[a][l]==sRecursivite[i][1])
                {
                    present =true;
                }
            }
            if(monEtat==true)
            {
                if (present==false)
                {
                    premiers[a].push_back(sRecursivite[i][1]);
                }

            }
            else
            {
                do
                {
                for(unsigned int k=0; k<DejaTraite.size(); k++)
                {

                    if(sRecursivite[i][1]==DejaTraite[k])
                    {
                        testFin= true;
                    }
                }
                if(testFin == false)
                {
                    DejaTraite.push_back(sRecursivite[i][1]);
                   Premiers(a,sRecursivite[i][1],DejaTraite);

                }

            }while(testFin==false);
            }
        }

        /*  for(unsigned int k=0; k<DejaTraite.size(); k++)
                {
                    cout<<"" <<DejaTraite[k]<<" ";
                }

            cout<<endl;*/
    }

}

 void Langage::Suivants(int b, char IndiceEtats, vector<char>DejaTraite2)// Meme chose que premiers
   {
        bool monEtat=false;
        bool present =false;
        bool VidePresent =false;
        bool present2=false;
        bool testFin=false;
        bool testFollow=false;
       // DejaTraite2.push_back(IndiceEtats);
        if(IndiceEtats == etats[0])// Si c'est le premier etat, alors dans les follows, il possede le startSymbol
        {
              suivants[b].push_back('$');
        }
        for(unsigned int i=0; i<sRecursivite.size(); i++)
        {
            for(unsigned int j= 1; j<sRecursivite[i].size();j++)
            {
                 present =false;
                if(sRecursivite[i][j]==IndiceEtats)
                {
                    //Les tab[i][j+1]correspond au caractere follow du de l'Etat Actuel: tab[i][j]=etats[i]
                      if(j+1>sRecursivite[i].size()-1) // Test pour verifier que ce n'est pas le dernier caractere de la ligne, si c'est le cas, affecter le mot vide dans les follozs
                      {
                         for(unsigned int k=0; k<DejaTraite2.size(); k++)
                                    {
                                        if(sRecursivite[i][0]==DejaTraite2[k])
                                        {
                                            VidePresent= true;
                                        }
                                    }
                                    if(VidePresent == false)
                                    {
                                         DejaTraite2.push_back(sRecursivite[i][j]);

                                         Suivants(b,sRecursivite[i][0],DejaTraite2);
                                    }
                      }

                      else
                      {
                         monEtat= EstTerminal(sRecursivite[i][j+1]);
                         for(unsigned int l=0; l<suivants[b].size();l++)
                         {
                            if(suivants[b][l]==sRecursivite[i][j+1])
                            {
                                present =true;
                            }
                         }

                         if(monEtat==true)//Cas Terminal
                         {
                            if(present==false)
                            {
                                suivants[b].push_back(sRecursivite[i][j+1]);// Meme chose que les premiers si terminaux ...
                            }
                         }

                         else//Cas non terminal
                         {
                            for(unsigned int k = 0; k<premiers.size();k++)   //Non terminal, donc appel a la recursivite du follow avec le first de cet indice
                            //Pour le first, utilise directement le tableau de resultat
                            {
                                if(premiers[k][0]==sRecursivite[i][j+1])
                                {
                                    for(unsigned int l = 1; l<premiers[k].size();l++)//On verifie que les premiers ne sont pas deja dans le tab suivants
                                    {
                                          for(unsigned int h=0; h<suivants[b].size();h++)
                                          {
                                                if(suivants[b][h]==premiers[k][l])
                                                {
                                                    present2 =true;
                                                }

                                                else if(premiers[k][l]=='#')
                                                {
                                                    testFollow=true;
                                                }
                                            }
                                        if(present2==false)
                                        {
                                                suivants[b].push_back(premiers[k][l]);// On affecte la liste des premiers du caractere non terminal tab[i][j+1]
                                        }

                                    }
                                    DejaTraite2.push_back(sRecursivite[i][j+1]);
                                    for(unsigned int k=0; k<DejaTraite2.size(); k++)
                                    {
                                        if(sRecursivite[i][j+1]==DejaTraite2[k])
                                        {
                                            testFin= true;
                                        }
                                    }
                                    if(testFin == false)
                                    {
                                         if(testFollow==true)
                                         {
                                            Suivants(b,sRecursivite[i][j+1], DejaTraite2);
                                         }
                                    }

                                }

                            }
                         }
                      }
                      cout<<"\n\n ------ Test Recursivite Follows --------"<<endl;
                                    cout<<"Etat "<<IndiceEtats;
                                    cout<<" , Deja Traite, valeur: "<<IndiceEtats<<endl;
                                       for(unsigned int i=0;i<DejaTraite2.size(); i++)
                                        {
                                            cout<<" "<<DejaTraite2[i];
                                        }
                                        cout<<endl;
                }
            }
        }

    }
void Langage::AffichagePremiers()
{
    cout << endl <<"Premiers" << endl;
    for(unsigned int i=0; i<premiers.size(); i++)
    {

        cout <<"Etat : "<<premiers[i][0];
        for(unsigned int j=1; j<premiers[i].size(); j++)
        {
            cout<<" : "<<premiers[i][j];
        }
        cout<<endl;
    }
}
  void Langage::AffichageSuivants()
    {
        cout<<"\n====== Suivants =======\n\n"<<endl;
        for(unsigned int i=0; i<suivants.size();i++)
        {
            cout<<"Etat : "<<suivants[i][0];
            for(unsigned int j=1; j<suivants[i].size();j++)
            {
                cout<<" : "<<suivants[i][j];
            }
            cout<<endl;
        }
    }
