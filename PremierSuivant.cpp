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
    vector <char> DejaTraite;
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
                    cout<<"test"<<endl;
                   Premiers(a,sRecursivite[i][1],DejaTraite);

                }

            }while(testFin==false);
            }
        }

          for(unsigned int k=0; k<DejaTraite.size(); k++)
                {
                    cout<<"" <<DejaTraite[k]<<" ";
                }

            cout<<endl;
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
