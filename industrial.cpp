#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "cell.h"
#include "cells.h"
#include "industrial.h"
using namespace std;


int  adjtester(vector<cell> adjacent,int adjpop_test){
  int temp = 0 ;
  for(int i =0; i < adjacent.size(); i++){
    if (adjacent[i].getPopulation() >=adjpop_test){
      temp++ ;
    }
  }
return temp;
}


void industrial(int x, int y,int& Goods,int& Worker,  cells v2, cell current, vector<cell> adjacent,cells &updating){  // simulation function for industrial cell

  int cellpopulation = current.getPopulation();  // getting the population
  bool isadjto_powerline = false; 
  int noof_worker = v2.getWorker();
  for(int i =0; i < adjacent.size(); i++){ // loop to check is the cell is adjacent to isadjto_powerline
      if(adjacent[i].getC() == 'T'){
      isadjto_powerline = true;
    }
  }
  int adjpop_test =0;
  //int noof_reqpop_adj = adjtester(adjacent,adjpop_test); // getting no of adjacent cells that has population greater than adjpop_test

 

if((cellpopulation ==0 ) && (isadjto_powerline) && (noof_worker >=2)){ //first case
  current.incPopulation(1);
  Goods++;
  Worker++;
}
else if ((cellpopulation == 0 ) && (adjtester(adjacent,1) >= 1) && (noof_worker >= 2) ){ // second case
  Goods++;
  Worker++;
}
else if ((cellpopulation == 1 ) && (adjtester(adjacent,1) >= 2) && (noof_worker >= 2) ){ // third case
   Goods++;
   Worker++;
}
else if ((cellpopulation == 2 ) && (adjtester(adjacent,2) >= 4) && (noof_worker >= 2) ){ // forth case
  Goods++;
  Worker++;
}


// TODO :: Call pollution function

cout << "Indus=> " << updating.settile(current, x,y) << endl;

}


