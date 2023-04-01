#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "cell.h"
#include "cells.h"
#include "industrial.h"
#include "commercial.h"
#include "residential.h"
using namespace std;
   
int main(){

     string filename;// config file 
     string layout;//to read the line from csv file
     string buffers;//For reading string  in config file
     int rate;
     int timeSteps;
     int refreshRate;

     cout <<"Beginning Simulation"<<endl;

     cout <<"Please enter the name of the configuration file:";
     //cin>>filename;
     filename = "config1.txt";
     fstream first(filename);//filestream for initial config file
     getline(first,buffers,':');
     cout<<buffers <<endl;
     getline(first,layout);
     cout<<layout<<endl;
     getline(first,buffers,':');
     getline(first,buffers);
     timeSteps=stoi(buffers);//converting temesteps to integers
     cout<<"TimeSteps: "<<timeSteps<<endl;

     getline(first,buffers,':');
     getline(first,buffers);
     refreshRate=stoi(buffers);//converting refresh rate to integers
     cout<<"RefreshRate: "<<refreshRate<<endl;
      
     char temp;//to store state of each cell
     string line;
     fstream myfile(layout);//filestream for csv file
     int i = 0 ;
     cell c1;//instantiating object of type cell
     vector<cell> v1;//creating a vector of cell objects
     cells v2;//creating cells objects to store the data
    cells updating ; // creating another cells object to store the updating datas

     //storing the info on each cell from csv file
     while(getline(myfile,line)){
         stringstream ss(line);
         while(!ss.eof()){  
           ss >> std::noskipws;
         ss>>temp;
         c1.setC(temp);
         v1.push_back(c1);

         ss>>temp;
         }
        
         v2.setTable(v1);
         v1.clear();
        }
 vector<cell> tempa;

updating = v2; 

v2.Printtable();
updating.Printtable();
bool program = true;

////while (program){
  bool change = false;  // bool to  check check  change between two, consecutive time steps

 vector<cell> adjacenttiles;

int goods = 0;//variable to store available goods
int worker = 0;//variable to track available worker, 0 in beginning
    

    cout << "X max: " << v2.getX_size() << endl;
    cout << "Y max: " << v2.getY_size() << endl;
    

     adjacenttiles =  v2.getadj_tileinfo(1,0);
cout << adjacenttiles.size() <<" " << adjacenttiles[1].getC() << endl;
for (int p = 0 ; p < timeSteps; p++) {

	cout <<"TimeStep "<<p<<"\n Available Worker "<<worker <<"    Available goods "<<goods <<endl;
       	for(int i = 0 ; i < v2.getX_size() ; i++ ){
    for (int j = 0; j < v2.getY_size(); j++){
    
      cell current = v2.gettileinfo(i,j);     

      adjacenttiles =  v2.getadj_tileinfo(i,j);
   
    if(current.getC()=='C'){
	      commercial(i,j,goods,worker,v2,current,adjacenttiles,updating);
      }
      v2= updating;
      if(current.getC()=='R'){
        residential(i,j,worker,v2,current,adjacenttiles,updating);
      }
      v2= updating;

      if(current.getC() == 'I'){
        industrial(i, j,goods, worker, v2,  current, adjacenttiles, updating);
      }
     v2 = updating;
  } 
}
updating.Printpoptable();
v2.Printpoptable();
cout << "Worker: " << worker << endl;

if(p % refreshRate == 0){
v2.Printtable();
}
}
}
