#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "cell.h"
#include "cells.h"
#include "industrial.h"
using namespace std;


int  adjtest(vector<cell> adjacent,int adjpop_test);
void commercial(int x ,int y ,int& goods, int& worker,cells &v2 , cell current, vector<cell> adjacent, cells &updating);



#endif
