/*****************************************************************************
  Authors:       Dana Vrajitoru, IUSB, CS
                 William Knight, IUSB, CS
  Class:         C243 Data Structures
  File name:     main.cc
  Last updated:  October 10, 2015.
  Description:   Main function.
******************************************************************************/

#include <iostream>
using namespace std;
#include <cstdlib>

#include "tree.h"
#include "interface.h"

/************************  M A I N   F U N C T I O N  **********************/

int main()
{
    NodePtr  treep  = NULL;     // "treep" stands for "tree pointer";  will be
    char     response;          // used to point to the root of a binary tree
    
    void  printExplanatoryMessage();

    do  // until interactive user signals to quit
    {
        printMenuAndGetAction (response);  // Insists on a valid response
        performAction(treep, response);    // Take an action
    } while (response != 'Q' && response != 'q');
    
    cout << "\n\n";
    return 0; // Indicate normal termination.
} // main()

