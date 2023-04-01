#ifndef POLLUTION_H
#define POLLUTION_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "cell.h"
#include "cells.h"
#include "industrial.h"
using namespace std;

void pollution(int x, int y,int pop,  cells& data){
  int jump =1;
  while(pop>0){
  data.changePollution(x,y,pop);
  pop -=1;











  
  }//while
} //func






#endif