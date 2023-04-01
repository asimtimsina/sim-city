#ifndef IND_H
#define IND_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "cell.h"
#include "cells.h"

void industrial(int x, int y,int& Goods,int& Worker,  cells v2, cell current, vector<cell> adjacent,cells &updating);   // simulation for industrial cell

int  adjtester(vector<cell> adjacent,int adjpop_test);   // function that returns the no of adjacent cells with the population greater than adjpop_test 

#endif