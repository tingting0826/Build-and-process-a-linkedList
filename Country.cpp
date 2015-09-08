//
//  Country.cpp
//  LinkList
//
//  Created by Tingting Wang on 9/7/15.
//  Copyright (c) 2015 Tingting Wang. All rights reserved.
//

#include "Country.h"

Country::Country()
{
   strcpy(code, "   ");
   name = "empty";
   capital = "empty";
   population = 0;
   
}

Country::Country(char *inputStr, string inputName, string inputCapital, int inputPopulation)
{
   strcpy(code, inputStr);
   name = inputName;
   capital = inputCapital;
   population = inputPopulation;
   
}

void Country::setCode(const char *inputChar)
{
   strcpy(code, inputChar);
}

void Country::setName(const string inputName)
{
   name = inputName;
}

void Country::setCapital(const string inputCapital)
{
   capital = inputCapital;
}

void Country::setPopulation(const int inputPopuation)
{
   population = inputPopuation;
}

char* Country::getCode() 
{
   return code;
}

string Country::getName()
{
   return name;
}

string Country::getCapital()
{
   return capital;
}

int Country::getPopulation() 
{
   return population;
}