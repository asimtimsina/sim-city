#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "cell.h"
#include "cells.h"

using namespace std;


 


  void cells::Printtable(){
    cout  << setfill('-')<< setw( table[0].size()*2 +4 ) << "\n";
  
    for (int i =0; i < table.size(); i++){
          cout << "| "; 
      for (int j = 0 ; j < table[i].size(); j++){
table[i][j].printLayOut();
      }
      cout  << "|" << endl;
    }
       cout << setfill('-') << setw( table[0].size()*2 +4 ) << "\n" ;
  }


vector<cell> cells::getadj_tileinfo(int x, int y){
    
  // cout << y << " " << x << endl;
    int p =0;
  vector<cell>data;
    if (x==0){
      if( y ==0){
       
        
        for (int i =0; i < 2 ; i++){
          for (int j =0; j < 2; j++){
           
            if((x+i !=x) ||(y+j != y)){
              data.push_back(table[x+i][y+j]);
              p++;
            }
          }
        }
        
        return data;
      } // if y==0
      else if ( y == getY_size()-1){

       for (int i =0; i < 2 ; i++){
          for (int j =-1; j < 1; j++){
            if((x+i !=x) ||(y+j != y)){
              data.push_back(table[x+i][y+j]);
              p++;
            }
          }
        }
      
        return data;
      } // if y = ymax-1
      else{
     
        for (int i =0; i < 2 ; i++){
          for (int j =-1; j < 2; j++){
           if((x+i !=x) ||(y+j != y)){
             data.push_back(table[x+i][y+j]);
              p++;
            }
          }
        }
       
        return data;
      } // else
    } // if x==0





    else if ((x == (getX_size()-1))){
      if (y==0){

        for (int i =-1; i < 1 ; i++){
          for (int j =0; j < 2; j++){
            if((x+i !=x) || (y+j != y)){
              data.push_back(table[x+i][y+j]);
              p++;
              cout << table[x+i][y+j].getC() << endl;
            }
          }
        }
       
        return data;
      } // if y==0
      else if ( y == getY_size()-1){

        for (int i =-1; i < 1 ; i++){
          for (int j =-1; j < 1; j++){
            if((x+i !=x) || (y+j != y)){
              data.push_back(table[x+i][y+j]);
              p++;
            }
          }
        }
        
        return data;
      } // if y = ymax -1
      else{
     
 
        for (int i =-1; i < 1 ; i++){
          for (int j =-1; j < 2; j++){
            if((x+i !=x)|| (y+j != y)){
              data.push_back(table[x+i][y+j]);
              p++;
            }
          }
        }
     
        return data;
      } // else
    } // else if x = xmax -1 



    
    else if (y ==0){

       for (int i =-1; i < 2 ; i++){
          for (int j =0; j < 2; j++){
           
            if((x+i !=x) ||(y+j != y)){
             data.push_back(table[x+i][y+j]);
              p++;
            }
          }
        }
     
        return data;
    } // y==0 

    else if( y == getY_size()-1 ){
     
      
       for (int i =-1; i < 2 ; i++){
          for (int j =-1; j < 1; j++){
            if((x+i !=x) || (y+j != y)){
              data.push_back(table[x+i][y+j]);
              p++;
            }
          }
        }
  
        return data;
    }
    else{
     
     
       for (int i =-1; i < 2 ; i++){
          for (int j =-1; j < 2; j++){
          
            if((x+i !=x) || (y+j != y)){
              data.push_back(table[x+i][y+j]);
              p++;
            }
          }
        }
   
        return data;
    }
 }
 

int cells::getWorker(){
  int worker =0; 
  for(int i =0 ;i < getX_size() ; i++){
    for(int j =0; j <getY_size(); j++){
      worker += table[j][i].getWorker();
    }
  }
  return worker;
}


void cells::changePollution(int x, int y, int a){
  table[y][x].incrementPollution(a);
}
