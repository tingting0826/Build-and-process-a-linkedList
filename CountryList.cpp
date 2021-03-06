// Implementation file for the CountryList class
#include <iostream>  // For cout and NULL
#include <iomanip>   // For setw()
#include <cstring>   // For strcmp()
#include "CountryList.h"
#include <string>

using namespace std;

//**************************************************
// Constructor                                     *
//**************************************************
CountryList::CountryList()
{
    head = NULL;
    head = new ListNode;
    head->next = NULL;
    count = 0;
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void CountryList::displayList() const
{
   int longestName = 0;
   int longestCapital = 0;
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head->next;

   // Display the header
   cout << left << "CODE  " << setw(20)
                << "COUNTRY_NAME" << setw(15)
                << "CAPITAL" << "     POPULATION\n";

   // While nodePtr points to a node, traverse the list.
   while (nodePtr)
   {
      // Display the value in this node in columns.
      cout << left << setw(6)   << nodePtr->country.getCode()
      << setw(20)          << nodePtr->country.getName()
      << setw(15)          << nodePtr->country.getCapital()
           << right << setw(15) << nodePtr->country.getPopulation() << endl;

      // Move to the next node.
      nodePtr = nodePtr->next;
   }
}

//**************************************************
// The searchNode function searches for a node     *
// with nodeData.code. If the node was found       *
// then true is returned and the Country data of   *
// node found is returned in nodeData. If the node *
// was not found, then false is returned and       *
// nodeData reference variable is unchanged.       *
//**************************************************
bool CountryList::searchNode(Country &nodeData)
{
   ListNode *nodePtr;            // To traverse the list

   // Position nodePtr at the head of list.
   nodePtr = head->next;

   // Skip all nodes that doesn't matches code of nodeData
   while (nodePtr != NULL && strcmp(nodePtr->country.getCode(), nodeData.getCode()) != 0)
   {
      // Move to the next node
      nodePtr = nodePtr->next;
   }

   // If nodePtr is NULL (not found)
   if (!nodePtr)
      return false;

   // Load nodeData with data from the found node
   nodeData = nodePtr->country;
   return true;
}

//**************************************************
// The insertNode function inserts a node with     *
// countryIn copied to its country member.         *
//**************************************************

void CountryList::insertNode(Country countryIn)
{
   ListNode *newNode;             // A new node
   ListNode *nodePtr;             // To traverse the list
   ListNode *previousNode = head; // The previous node

   // Allocate a new node and store countryIn there.
   newNode = new ListNode;
   newNode->country = countryIn;

   // Position nodePtr at the head of list.
   nodePtr = head->next;

   // Skip all nodes whose value is less than code.
   while (nodePtr != NULL && strcmp(nodePtr->country.getCode(), countryIn.getCode())<0)
   {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
   }
   previousNode->next = newNode;
   newNode->next = nodePtr;
   count++;
}

//**************************************************
// The deleteNode function searches for a node     *
// with the same code in nodeData. If node is found*
// it is deleted from the list and from memory. The*
// function returns true if node was deleted & the *
// node to delete country information is returned  *
// in nodeData. If node to delete is not found (or *
// there is nothing to delete) then a false is     *
// returned.                                       *
//**************************************************

bool CountryList::deleteNode(Country &nodeData)
{
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode;  // To point to the previous node

   // Initialize nodePtr to head of list
   nodePtr = head->next;
   previousNode = head;

   // Skip all nodes whose code is not equal to the code pointed by pDeleteCode.
   while (nodePtr != NULL && strcmp(nodePtr->country.getCode(), nodeData.getCode()) != 0)
   {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
   }

   // If node-to-delete not found OR no nodes
   if (!nodePtr)
      return false;
   
   nodeData = nodePtr->country;  // return the deleted data
   previousNode->next = nodePtr->next;
   delete nodePtr;
   count--;
   return true;
}

void CountryList::deleteCharNode(char codeChar)
{
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode;  // To point to the previous node
   
   // Initialize nodePtr to head of list
   nodePtr = head->next;
   previousNode = head;
   
   codeChar = toupper(codeChar);

   
   while(nodePtr != NULL)
   {
      string codeString = nodePtr->country.getCode();
      char char1 = codeString[0];
      char char2 = codeString[1];
      // Skip all nodes whose code is not equal to the code pointed by pDeleteCode.
      if (char1 != codeChar && char2 != codeChar)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }
      
      else
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
         nodePtr = previousNode->next;
         count--;
      }
   }
}
//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

CountryList::~CountryList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head->next;

   // While nodePtr is not at the end of the list...
   while (nodePtr != NULL)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
   delete head;
}

int CountryList::getCount()
{
   return count;
}