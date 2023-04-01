#include <iostream>
#include "cell.h"

using namespace std;

void cell::setC(char a){
  c =a;
}
char cell::getC(){
  return c;
}
void cell::printLayOut(){
 if(population > 0 ){ cout<<population <<" ";
}
else {
	cout <<c <<" ";

}
}


void cell::settile(char a){
  if (a == 'I')
      isIndustrial = true;
  if (a == 'R')
      isResidential = true;
   if (a == 'C')
      isCommercial = true;
   if (a == 'P')
      isPowerPlant = true;
    if (a == '-')
      isRoad = true;
     if (a == '#')
      isPowerLineoverRoad = true;
      if (a == 'T')
      isPowerLine = true;
}



void cell::setPopulation(int pop){
  population = pop;
}

int cell::getPopulation(){
  return population;
}


cell::cell(){
 c = '*';
 isResidential = false;
 isIndustrial = false;
 isCommercial = false;
 isRoadwayConnected = false;
 isRoad = false; 
 isPowerPlant = false;
 isPowerLine = false; 
 isPowerLineoverRoad = false;
 population = 0; 
  Worker = 0;
}




void cell::setWorker(int a){
  Worker =a;
}
int cell::getWorker(){
  return Worker;
}

void cell::incPopulation(int a){
population += a;
}

void cell::incrementPollution(int a){
  pollution += a;
  }
