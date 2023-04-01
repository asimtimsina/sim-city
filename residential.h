#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "cell.h"
#include "cells.h"

using namespace std;

int  adjteste(vector<cell> adjacent,int adjpop_test);

void residential(int x ,int y, int& worker,cells &v2 , cell current, vector<cell> adjacent, cells &updating);





#endif
