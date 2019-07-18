#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<time.h>

using namespace std;

struct tache{
  int d, p, l, ind, c;
};

void lecture(int &n, vector<tache> &Tache);
int partition(vector<tache> &Tache, int deb, int fin);
void tri_rapide_bis(vector<tache> &Tache, int deb, int fin);
void tri_rapide(vector<tache> &Tache,int n);
int maximum(int &n, vector<tache> &Tache);
void affichage(int n, vector<tache> Tache, int Lmax);

int main(){

   int n, Lmax;
   vector<tache> Tache;
   lecture(n,Tache);

   float temps;
   clock_t t1, t2;
   t1 = clock();

   tri_rapide(Tache,n);

   Lmax=maximum(n,Tache);
   cout<<endl;

   affichage(n,Tache,Lmax);
   cout<<endl;

   t2 = clock();
   temps = (float)(t2-t1)/CLOCKS_PER_SEC;
   cout<<"temps= "<<temps<<endl;
}

void lecture(int &n, vector<tache> &Tache){

    tache T;

    cout<<"donner le nbre de taches ";
    cin>>n;
    cout<<endl;

    for(int i=0; i<n; i++){

      T.ind=i;

      cout<<"entrer  p"<<i+1<<"  ";
      cin>>T.p;

      cout<<"entrer  d"<<i+1<<"  ";
      cin>>T.d;

      Tache.push_back(T);
      cout<<endl;

   }
}


int partition(vector<tache> &Tache, int deb, int fin){
 int compt=deb;
 int pivot=Tache[deb].d;

 for(int i=deb+1; i<=fin; i++){
    if(Tache[i].d<pivot){
        compt++;
         swap(Tache[compt],Tache[i]);
    }
 }
    swap(Tache[compt],Tache[deb]);

 return(compt);
}

void tri_rapide_bis(vector<tache> &Tache, int deb, int fin){
 if(deb<fin){
    int pivot= partition(Tache,deb,fin);
    tri_rapide_bis(Tache, deb, pivot-1);  //recursivité
    tri_rapide_bis(Tache, pivot+1, fin);
 }
}

void tri_rapide(vector<tache> &Tache,int n){
    tri_rapide_bis(Tache,0,n-1);
}

int maximum(int &n, vector<tache> &Tache){

   int t=Tache[0].p;
   int maximum=t-Tache[0].d;

    Tache[0].c=t;
    Tache[0].l=t-Tache[0].d;

     for(int i=1; i<n; i++){
            t=t+Tache[i].p;
            Tache[i].c= t;
            Tache[i].l= t-Tache[i].d;

         if(maximum < (t-Tache[i].d)){
         maximum= t-Tache[i].d;
         }
     }
     return maximum;
}

void affichage(int n, vector<tache>Tache, int Lmax){

     cout<<"Lmax= "<<Lmax<<endl;
     cout<<endl;

      for(int i=0; i<n; i++){
        cout<<"d"<<Tache[i].ind+1<<"= "<<Tache[i].d<<"  ";
    }
    cout<<endl;
     for(int i=0; i<n; i++){
        cout<<"c"<<Tache[i].ind+1<<"= "<<Tache[i].c<<"  ";
    }
    cout<<endl;

    for(int i=0; i<n; i++){
        cout<<"L"<<Tache[i].ind+1<<"= "<<Tache[i].l<<"  ";
    }
    cout<<endl;

}
