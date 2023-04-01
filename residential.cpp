#include "residential.h"

using namespace std;

int  adjteste(vector<cell> adjacent,int adjpop_test){
  int temp = 0 ;
  for(int i =0; i < adjacent.size(); i++){
    if (adjacent[i].getPopulation() >=adjpop_test){
      temp++ ;
    }
  }
return temp;
}


void residential(int x ,int y, int& worker,cells &v2 , cell current, vector<cell> adjacent, cells &updating){
  int cellpopulation = current.getPopulation();
  bool isadjto_powerline = false;
  for(unsigned int i =0; i < adjacent.size(); i++){
    if(adjacent[i].getC() == '#'||adjacent[i].getC()=='T'){
      isadjto_powerline = true;
    }
  }
  if((cellpopulation ==0 ) && (isadjto_powerline)){
  current.incPopulation(1);
  worker++;
}
else if ((cellpopulation == 0 ) && (adjteste(adjacent,1) >= 1)){
   current.incPopulation(1);
   worker++;
}
else if ((cellpopulation == 1 ) && (adjteste(adjacent,1) >= 2) ){
   current.incPopulation(1);
   worker++;
}
else if ((cellpopulation == 2 ) && (adjteste(adjacent,2) >= 4)){
   current.incPopulation(1);
   worker++;
}
else if((cellpopulation == 3)&& (adjteste(adjacent,3)>=6)){
  current.incPopulation(1);
  worker++;
}
else if((cellpopulation == 3)&& (adjteste(adjacent,4)>=8)){
  current.incPopulation(1);
  worker++;
}


cout << "Res =>"<< updating.settile(current, x,y) << endl;





}


