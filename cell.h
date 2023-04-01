
#ifndef CELL_H
#define CELL_H

class cell{
private:
char c;
bool isResidential = false;
bool isIndustrial = false;
bool isCommercial = false;
bool isRoadwayConnected = false;
bool isRoad = false; 
bool isPowerPlant = false;
bool isPowerLine = false; 
bool isPowerLineoverRoad = false;
int population; 
int Worker;
int pollution;



public:

void setC(char a);
char getC();
void printLayOut();
char getType();
void settile(char a);

void setPopulation(int pop);
int getPopulation();
void incPopulation(int a);

void setWorker(int a);
int getWorker();
void incrementPollution(int a);

cell();

};

#endif
