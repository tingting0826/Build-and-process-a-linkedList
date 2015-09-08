/**
 YOUR TASK is to read and understand this program. Then do the following:
 --> create and use a sentinel (or dummy) node
       // a sentinel node is an empty data node placed in the beginning of the list
       // insert/delete are shorter, simpler, and more eficient
 --> Display the number of countries in the list
 --> Create a second linked list
 --> Display the second linked list

 Name:Tingting Wang
 IDE:XCODE
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "CountryList.h"

using namespace std;

bool readCountries(CountryList *list);
void searchManager(CountryList *list);
void deleteManager(CountryList *list);
void displayCountry(Country showCountry);
string removeTrailingWhiteSpace(string str);

int main()
{
   // Define a CountryList object.
   CountryList *list = new CountryList;


   // Read Country information and creating link list nodes for country.
   if (!readCountries(list))
      return 1;

   // Display link list in CountryList object.
   list->displayList();

   // Search for country in CountryList object.
   searchManager(list);

   // Delete countries in CountryList object.
   deleteManager(list);
   list->displayList();

   // YOUR TASK ==================================
   // call more functions below


   // ================================================
   delete list;

   return 0;
}

//**************************************************
// Definition of function displayCountry.
// This function displays the country information in
// showCountry.
//**************************************************
void displayCountry(Country showCountry)
{
   // Display Country Data
   cout << showCountry.getCode() << "; "
        << showCountry.getName() << "; "
        << showCountry.getCapital() << "; "
        << showCountry.getPopulation();
}

//**************************************************
// Definition of function readCountries.
// This function will read all the country info from
// the file Countries.txt and insert them into a
// list, a reference parameter. This function returns
// true if read successfully, and false if it did
// not read successfully or read no country.
// ASSUMPTIONS: about Countries.txt
//  1) Each country's data member is on a separate line.
//  2) Each country is immediately after one another.
//  3) There is nothing after the last country's data.
//**************************************************
bool readCountries(CountryList *list)
{
   ifstream inFile;
   Country readCountry;
   string readStr;
   bool empty = true;

   // Open file to read, if couldn't open, display error
   // and exit with false
   inFile.open("/Users/TingtingWang/XcodeProjects/Git_Repo/Build and process a linkedList/countries.txt");
   if (!inFile)
   {
      cout << "Error opening countries.txt!\n";
      return false;
   }

   while (getline(inFile, readStr))  // get Country's Code
   {
        // finish processing Country's Code
        readCountry.setCode(removeTrailingWhiteSpace(readStr).c_str());

        // read and process Country's name
        getline(inFile, readStr);
        readCountry.setName(removeTrailingWhiteSpace(readStr));

        // read and process Country's capital
        getline(inFile, readStr);
        readCountry.setCapital(removeTrailingWhiteSpace(readStr));

        // read and process Country's population
        getline(inFile, readStr);
        readCountry.setPopulation(atoi(readStr.c_str()));

        list->insertNode(readCountry);
        empty = false;
   }

   inFile.close();

   if (empty)
      return false;

   return true;
}

//**************************************************
// Definition of function removeTrailingWhiteSpace.
// This function removes trailing white spaces at
// the back of the string, str, and returns the new
// string. Removes trailing tabs, line feeds,
// spaces, and carriage returns.
//**************************************************
string removeTrailingWhiteSpace(string str)
{
   int i = int(str.length() - 1);  // zero based
   while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' || str[i] == '\r')
   {
      str.erase(i, 1);
      i--;
   }
   return str;
}

//**************************************************
// Definition of function searchManager.
// This function will search for the country based
// upon the code entered by the user. If the country
// is found, the country data is returned in list, a
// reference parameter. Otherwise search not found
// will be displayed. This will cycle until the user
// enters QUIT.
//**************************************************
void searchManager(CountryList *list)
{
   Country searchCountry;
   string input;
   const string search_prompt = "[SEARCH COUNTRY] Please enter a code for a country:\n";

   while (cout << search_prompt, cin >> input, input != "QUIT")
   {
       searchCountry.setCode(input.c_str());
       if (!list->searchNode(searchCountry))
          cout << "Search for " << searchCountry.getCode() << " not found.\n";
       else
       {
          cout << "Country found: ";
          displayCountry(searchCountry);
          cout << ".\n";
       }
   }
}

//**************************************************
// Definition of function deleteManager.
// This function cycles, asking the user for a
// country to delete. The user enter a Code of the
// country to be deleted. If the Code is not found
// in the list, a reference parameter, then a
// message telling the user that country not found.
// If the Code was found, the node data that is
// deleted is shown. This function keeps going in a
// cycle until the user enter QUIT.
//**************************************************
void deleteManager(CountryList *list)
{
   string input;
   Country delCountry;
   const string delete_prompt = "[DELETE COUNTRY] Please enter a code for a country [QUIT to stop]:\n";

   while(cout << delete_prompt, cin >> input, input != "QUIT")
   {
      strcpy(delCountry.getCode(), input.c_str());
      if (!list->deleteNode(delCountry))
         cout << "Country, " << delCountry.getCode()<< ", was not deleted because it was not found!\n";
      else
      {
         cout << "Country Info that was deleted: ";
         displayCountry(delCountry);
         cout << ".\n";
      }
   }
}
