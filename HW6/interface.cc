/*****************************************************************************
  Authors:       Dana Vrajitoru, IUSB, CS
                 William Knight, IUSB, CS
  Class:         C243 Data Structures
  File name:     interface.cc
  Last updated:  October 10, 2015.
  Description:   Interface functions.
******************************************************************************/

#include <iostream>
using namespace std;
#include <cstdlib>

#include "tree.h"
#include "interface.h"

/*************  P R I N T   E X P L A N A T O R Y   M E S S A G E  ***********

This function prints a message to the interactive user explaining briefly
what the program is going to do.  Documented and coded by W. Knight. */

void  printExplanatoryMessage()
{
    cout << "\n\nThis program allows an interactive user to create, modify,\n";
    cout << "display, and destroy binary trees.  The program is menu driven.\n";
    cout << "Press the Enter key to continue.";
    while (cin.get() != '\n');  // Clear the input stream up through newline.
                                // Note the empty loop body.
} // printExplanatoryMessage()

/********************  P E R F O R M   A C T I O N  **************************

This function performs an action on the tree based on the reponse character. 
Documented and coded by W. Knight and Dana Vrajitoru */

void performAction(NodePtr &treep, char response)
{
    switch (response)  // Response is necessarily one of the following.
    {
    case 'B' :
    case 'b' : buildABinaryTree (treep);
               break;
    case 'C' :
    case 'c' : cout << "\nThere are " 
                    << countOfZeroDataValues (treep)
                    << " zero data values in the current tree.\n";
               break;
    case 'D' :
    case 'd' : cout << endl;
               destroyABinaryTree (treep);
               cout << "\nThe tree should now be empty.\n";
    break;
    case 'H' :
    case 'h' : cout << "\nThe height of the tree is " << height(treep)
                    << ".\n";
               break;
    case 'I' :
    case 'i' : incrementEachDatum (treep);
               cout << "\nEvery data value should have been "
                    << "incremented.\n";
    break;
    case 'P' : 
    case 'p' : if (!treep)
                   cout << "\nThe tree is empty." << endl;
               else
                   graphPrint (treep);
               break;
    case 'Q' :
    case 'q' : break; // Do nothing.  The program will quit.
    case 'R' :
    case 'r' : cout << endl;
               reverse(treep);
               cout << "\nThe tree should now be the mirror image "
                    << "of what it was.\n";
               break;
    case 'S' :
    case 's' : cout << "\nThe sum of the negative data values is "
                    << sumOfNegativeData (treep) << endl;
               break;
    }
} // performAction()


/************  R E A D   A N D   E C H O   C H A R   R E S P O N S E  *********

This utility function assumes that an interactive user has been prompted
to enter a one-character response, followed by a newline character.
It reads the first non-white-space response character and then clears all 
other characters from the input stream, up through the first newline character.
It also echoes the character back to the user.  Documented and coded by  
W.Knight. */

void readAndEchoCharResponse (char & response)
{
    cin >> response;
    while (cin.get() != '\n'); // Clear the line.
    cout << response << endl;
}

/************  R E A D   A N D   E C H O   I N T   R E S P O N S E  *********

This utility function assumes that an interactive user has been prompted
to enter an integer value, followed by a newline character.
It reads the first integer on the line and then clears all 
other characters from the input stream, up through the first newline character.
It also echoes the integer back to the user.  Documented and coded by 
W.Knight. */

void readAndEchoIntResponse (int & response)
{
    cin >> response;
    while (cin.get() != '\n');  // Clear the line.
    cout << response << endl;
} // readAndEchoIntResponse()


/**********  P R I N T   M E N U   A N D   G E T   A C T I O N  *************

This function displays a menu of actions and asks an interactive user to 
select one.  It will not return until it has read an acceptable response. 
Documented and coded by W.Knight. */

void printMenuAndGetAction (char & response)
{
    cout << "\n\n";
    cout << "Which of the following actions do you wish to take?\n";
    cout << "   B)uild or modify the current tree interactively.\n";
    cout << "   C)ount and report number of zero data values in "
        "current tree\n";
    cout << "   D)estroy the current tree.\n";
    cout << "   H)eight of the tree -- determine it.\n";
    cout << "   I)ncrement every data value in the current tree by 1.\n";
    cout << "   P)rint the current tree on the screen.\n";
    cout << "   Q)uit.\n";
    cout << "   R)eplace the current tree by its mirror image.\n";
    cout << "   S)um the negative data values in the current tree.\n";
    cout << "\n";
    cout << "Your choice:  ";
    
    readAndEchoCharResponse (response);
    
    while (1) // loop will continue until user gives an appropriate response
    {
        switch (response)
        {
        case 'B': case 'b': case 'C': case 'c': 
        case 'D': case 'd': case 'H': case 'h': 
        case 'I': case 'i': case 'P': case 'p': 
        case 'Q': case 'q': case 'R': case 'r': 
        case 'S': case 's' :
            return;  // EXIT FROM THE FUNCTION WITH PARAMETER HAVING OK VALUE 
        default : cout << "Improper Response  "
                "Please type an appropriate letter.   ";
        }
        readAndEchoCharResponse (response);
    }
} // printMenuAndGetAction()

  
/*******************  T E S T   D Y N A M I C   A L L O C A T I O N  *********

This utility function assumes that the value of the parameter "pointer" 
has been obtained by a call to the "new" function.  If that function
was unable to dynamically allocate the required amount of memory space,
then it returned the value NULL.  This function tests to see whether
the value returned was NULL, and if it was, it terminates the program.
The parameter type is "pointer-to-void" so that any pointer data type
can be passed to this function.   Documented and coded by W. Knight. */

void testDynamicAllocation (void * pointer)
{
    if (!pointer)  // if "pointer" is NULL
    {
        cout << "\nDynamic allocation failure.  Program being terminated."
             << endl;
        exit(1);  // EXIT FROM THE ENTIRE PROGRAM
    }
} // testDynamicAllocation()
