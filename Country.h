
#ifndef __LinkList__Country__
#define __LinkList__Country__

#include <iostream>
#include <string>


using namespace std;


const int COUNTRY_CODE_SIZE = 3; // 2 + \0

class Country
{
private:
   char code[COUNTRY_CODE_SIZE];
   string name;
   string capital;
   int population;
public:
   Country();
   Country(char *inputStr, string inputName, string inputCapital, int inputPopulation);
   // setter
   void setCode(const char *inputChar);
   void setName(const string inputName);
   void setCapital(const string inputCapital);
   void setPopulation(const int population);
   // getter
   char* getCode();
   string getName();
   string getCapital();
   int getPopulation();
   
   
};


#endif /* defined(__LinkList__Country__) */
