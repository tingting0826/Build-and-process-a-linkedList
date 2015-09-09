// Specification file for the CountryList class
#ifndef COUNTRYLIST_H
#define COUNTRYLIST_H

#include <string>
#include "Country.h"

using namespace std;


class CountryList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      Country country;        // The value in this node
      ListNode *next;         // To point to the next node
   };

   ListNode *head;            // List head pointer
   int count;

public:
   // Constructor
   CountryList();

   // Destructor
   ~CountryList();

   // Linked list operations
   void insertNode(Country countryIn);
   bool deleteNode(Country &countryData);
   void deleteCharNode(char codeChar);
   bool searchNode(Country &countryData);
   void displayList() const;
   int getCount();

};
#endif
