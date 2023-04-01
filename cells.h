#ifndef CELLS_H
#define CELLS_H

#include <iostream>
#include <string>
#include <vector>
#include "cell.h"
using namespace std;

class cells{
  private:
 vector <vector <cell>> table;
  int x_size;
  int y_size;


public:
  void Printtable();

 void setTable(vector<cell> t1){
   table.push_back(t1);
  }

   int getX_size(){
    return table.size();
  }
  
  int getY_size(){
    return table[0].size();
  }

  cell gettileinfo(int x, int y){
    return table[x][y];
  }


vector<cell> getadj_tileinfo(int x, int y);

int getWorker();

bool settile(cell C, int i , int j){
//TODO: Return void after testing

  if(table[j][i].getC() == C.getC()){
    table[j][i] = C ;
    return true;
  }
  return false;
}



///////////////////////////////
//   *** IMP Delete before submit

  void Printpoptable(){
    cout  << setfill('-')<< setw( table[0].size()*2 +4 ) << "\n";
  
    for (int i =0; i < table.size(); i++){
          cout << "| "; 
      for (int j = 0 ; j < table[i].size(); j++){
        cout << table[i][j].getWorker() << " " ;
      }
      cout  << "|" << endl;
    }
       cout << setfill('-') << setw( table[0].size()*2 +4 ) << "\n" ;
  }


void changePollution(int x, int y, int a);


};








#endif