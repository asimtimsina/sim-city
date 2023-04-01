#include "commercial.h"

using namespace std;

int  adjtest(vector<cell> adjacent,int adjpop_test){
  int temp = 0 ;
  for(int i =0; i < adjacent.size(); i++){
    if (adjacent[i].getPopulation() >=adjpop_test){
      temp++ ;
    }
  }
return temp;
}


void commercial(int x ,int y ,int& goods, int& worker,cells &v2 , cell current, vector<cell> adjacent, cells &updating){

int pop = current.getPopulation();
bool isAdjToPowerline = false;

for(unsigned int i = 0 ; i <adjacent.size() ; i++){
  if(adjacent[i].getC() == 'T'||adjacent[i].getC()=='#'){
    isAdjToPowerline= true;
    break;

  }
}
if(pop==0 && isAdjToPowerline && worker >= 1 && goods>=1){
current.incPopulation(1);
worker--;
goods--;
}
if(pop==0 && adjtest(adjacent ,1)>=1 && worker >= 1 && goods>=1){
current.incPopulation(1);
worker--;
goods--;
}
if(pop==1 && adjtest(adjacent ,1)>2 && worker >= 1 && goods>=1){
current.incPopulation(1);
worker--;
goods--;
}
cout << " Comm => " << updating.settile(current, x,y) << endl;
}
