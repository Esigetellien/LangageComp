#include "Language.h"

using namespace std;

void Langage::AnalyseInit()
{
    int a=1;
     analyse.push_back(vector<char>());
     analyse[0].push_back(' ');

    for(unsigned int i=0; i<terminaux.size();i++)
    {
        if(terminaux[i]== 1 && etats[i] !='#')
        {
             analyse[0].push_back(etats[i]);
        }
    }
    analyse[0].push_back('$');
    for(unsigned int k= 0; k<terminaux.size();k++)
    {
        if(terminaux[k]==0)
        {
            analyse.push_back(vector<char>(analyse[0].size()));
            analyse[a][0]=etats[k];
            a++;
        }
    }
}


void Langage::affichageTableA()
{
    cout<<"===== Table d'Analyse ====\n\n"<<endl;
    for(unsigned int i=0;i<analyse.size();i++)
    {
        cout<<analyse[i][0]<<" | ";
        for(unsigned int j=1;j<analyse[i].size();j++)
        {
            cout<<analyse[i][j]<<" - ";
        }
        cout<<endl;
    }
    cout<<"\n\n";
}

void Langage::Analyse()
{
    AnalyseInit();
    affichageTableA();
}
