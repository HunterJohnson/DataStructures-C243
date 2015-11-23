/*****************************************************************************
  Authors:       Dana Vrajitoru, IUSB, CS
                 William Knight, IUSB, CS
                 Chad George, IUSB alumni
  Class:         C243 Data Structures
  File name:     tree.cc
  Last updated:  October 22, 2015 - Hunter Johnson
  Description:   Implementation of functions for trees
******************************************************************************/

#include <iostream>
using namespace std;
#include <cstdlib>

#include <vector>
#include <string>
#include <sstream>

#include "interface.h"
#include "tree.h"

#define A(x)   cout << x << endl;       // Debugging macro
#define B(x,y) cout << x << y << endl;  // Debugging macro

/******************  P R I N T   T R E E   V E R T I C A L L Y  **************

The following function prints a binary tree vertically graphically
showing the connections between parent and child nodes The function
and support functions were written by C. George, C243, Fall 2004. */

void graphPrint(NodePtr rootp)
{
    if (rootp == NULL) return;
	
    // create an array to hold the output as is it generated
    vector<string> output;
    int pos = 0;
    pos = graphPrintWalk(rootp, pos, 0, output);

    // print the root Node
    cout << string(pos,' ') << rootp << endl;
    
    // print the other levels from top to bottom
    for(int i=0;i<output.size();i++)
    {
        cout << output[i] << endl;
    }
} // graphPrint()

// This function walks through the tree in-order to calculate the x
// position of each node in the tree. It then prints any child nodes
// to the appropriate output string and also prints inner-connecting
// links

int graphPrintWalk(NodePtr rootp, int &pos, int level, 
                   vector<string>& output)
{
    if (rootp == NULL) 
        return pos;
    else
    {
        // Expand the size of the output array if this is the first
        // node on a new level
        if(output.size() <= (level*2))
        {
            output.push_back("");
            output.push_back("");
        }
    
        // Calculate the x position of both child nodes and the current node
        int leftPos = graphPrintWalk(rootp->left, pos, level+1, output);
    
        int currPos = pos;
        
        ostringstream currDatum;
        currDatum << rootp;
        pos += currDatum.str().length()+1;
        
        int rightPos = graphPrintWalk(rootp->right, pos, level+1, output);
    
        // initialize the output streams with the current output for the level
        
        ostringstream linkLine, NodeLine;
    
        linkLine << output[level*2];
        NodeLine << output[level*2+1];
        
        // calculate the center of the current node
        int currOffset = currPos + (currDatum.str().length() / 2) - 1;
        
        // add the left node and its link to the current output for the level
        if(rootp->left != NULL)
        {
            // calculate the center of the left child node
            ostringstream leftDatum;
            leftDatum << rootp->left;
            int leftOffset = leftPos + (leftDatum.str().length() / 2) - 1;
            
            NodeLine << string(leftPos - NodeLine.str().length(), ' ') 
                     << rootp->left;
            
			
            // draw a link from this Node to the left child node
            linkLine << string((leftOffset+1) - linkLine.str().length(), ' ') 
                     << string((currOffset)-(leftOffset+1), '_') << "/";
			
        }
    
        // add the right node and its link to the current output for the level
        if(rootp->right != NULL)
        {
            // calculate the center of the right child node
            ostringstream rightDatum;
            rightDatum << rootp->right;
            int rightOffset = rightPos + (rightDatum.str().length() / 2) - 1;
      
      
            NodeLine << string(rightPos - NodeLine.str().length(),' ') 
                     << rootp->right;
            
            // draw a link from this node to the right child node
            linkLine << string((currOffset+1) - linkLine.str().length(),' ') 
                     << "\\" <<	string((rightOffset-1) - (currOffset), '_') 
                     << " ";
        }

        // save the results for the current level
        output[level*2]   = linkLine.str();
        output[level*2+1] = NodeLine.str();
    
        return currPos;
    }
} // graphPrintWalk()

// This stream formatter outputs the contents of a node with a leading digit
// for datum values 0-9

ostream &operator<<(ostream &out, NodePtr rootp)
{
    out << ((rootp->datum >= 0 && rootp->datum < 10)?"0":"")
        << rootp->datum;
    return out;
} // operator<<()

/**************************  P R E T T Y   P R I N T  *************************
                                                                           
The following function sends to standard output a list of the integer data
values of the nodes in the binary tree pointed to by "rootp".  The values
are written in such a way as to show the logical structure of the tree.
The parameter "margin" should have a non-negative value, which determines 
the number of blank spaces that will be printed to the left of the root 
of the tree.  If no second argument is used when this function is called,
then the default value 0 will be used (see the function prototype).  
The function is recursive.   Documented and coded by W.Knight. */

void prettyPrint (NodePtr rootp, int margin) // 
{
    const int INDENTATION = 4;
    
    if (!rootp)
        return;
    
    else
    {
        prettyPrint(rootp->right, margin + INDENTATION);

        for (int i = 1; i <= margin; ++i)
            cout << " ";
    
        cout << rootp->datum << endl;
        
        prettyPrint(rootp->left, margin + INDENTATION);
    }
} // prettyPrint()


/*****************  B U I L D   A   B I N A R Y   T R E E  ******************
                                                                           
The following function allows an interactive user to construct a binary   
tree whose nodes hold integer data values.  The function is recursive. 
Documented and coded by W.Knight. 
Added by D. Vrajitoru in 2012: an option to delete the subtree when the 
rootp pointer is not null. */

void buildABinaryTree (NodePtr &rootp) // Parameter passed by REFERENCE!
{
    char action;

    while(1)  // Endless loop; there are two "return" statements in the loop.
              // They are executed whenever the user wants to move up the tree.
    {
        if (rootp == NULL)  // The tree or subtree pointed to by rootp is empty.
        {
            do  // This loop continues until the user responds with 'U' or 'C'.
            {
                cout << "\nYou are currently at an empty tree. If you wish to ";
                cout << "create\na new Node at this position, type C and press";
                cout << " Enter.\nOtherwise ";
                cout << "type U to go up to the parent Node (if any).  ";
                readAndEchoCharResponse (action);
            } while (action != 'C' && action!= 'c' && action!= 'U' 
                     && action!= 'u');
            if (action == 'U' || action == 'u')
                return; // Return control to the calling function
            else
            {
                rootp = new Node;
                testDynamicAllocation (rootp);
                rootp->left  = rootp->right = NULL;
                cout << "Enter an integer for the new Node:  ";
                readAndEchoIntResponse (rootp->datum);
            }	
        }
        else  // tree is not NULL
        {
            do  // This loop continues until user gives a suitable response.
            {      
                cout << "\nThe datum of the Node at which you have arrived is\n";
                cout << "         ";
                cout << rootp->datum << endl;
                cout << "Enter  U  to go up to the parent Node,\n";
                cout << "       L  to go down to the left,\n";
                cout << "       R  to go down to the right,\n";
                cout << "       P  print the current subtree,\n";
                cout << "       M  to modify value of the datum stored here,\n";
                cout << "       D  to delete the whole subtree.\n";
                readAndEchoCharResponse (action);
            }
            while (action != 'U' && action !='u' && action !='L' && action !='l' 
                   && action != 'R' && action !='r' && action !='M' && action !='m'
                   && action != 'P' && action != 'p' && action != 'D' && action != 'd');
      
            switch (action)
            { 
            case 'U': case 'u': return;   // Go back to the calling function.
            case 'L': case 'l': buildABinaryTree (rootp->left);  break;
            case 'R': case 'r': buildABinaryTree (rootp->right); break;
            case 'P': case 'p': graphPrint(rootp); break;
            case 'M': case 'm': cout << "Enter a new datum value to replace"
                    " the current value.  ";
                readAndEchoIntResponse (rootp->datum);
                break;
            case 'D': case 'd': destroyABinaryTree(rootp); // the parameter is 
                // also passed by reference
            } // end of "switch"
        }   // end of "else"     
    }     // end of "while(1)" 
}       // end of function 


/*************  C O U N T   O F   Z E R O   D A T A   V A L U E S  **********

The following function traverses the binary tree pointed to by "rootp"
and counts every node whose datum value is zero.  The function
returns that count as its value.  The function is recursive.  The function
documentation and heading were written by W. Knight.  */

int countOfZeroDataValues (NodePtr rootp)
{
   int count = 0;
   
   if(rootp)
   {
        if(rootp->datum == 0)
            count++;
        
        count += countOfZeroDataValues(rootp->left);
        count += countOfZeroDataValues(rootp->right);
   }
      
    return count;  // A "dummy instruction" that lets the program compile.
} // countOfZeroDataValues()


/****************  D E S T R O Y   A   B I N A R Y   T R E E  ***************
                                                                           
The following function deallocates all the nodes in the binary tree 
pointed to by "rootp", and it makes the tree empty (i.e., it changes to 
NULL the value of the pointer passed to it).  The function is recursive.  
The function documentation and heading were written by W. Knight.  */

void destroyABinaryTree (NodePtr &rootp)
{
    if(rootp)
    {
         destroyABinaryTree(rootp->left);
         destroyABinaryTree(rootp->right);
        
         delete rootp;
         rootp = NULL;
    }
} // destroyABinaryTree()


/***************************  H E I G H T  ********************************

The following function calculates and returns the height of the binary
tree pointed to by "rootp".  The function is recursive.  The function
documentation and heading were written by W. Knight.  */

int height (NodePtr rootp)
{
    int lh, rh;
    
    if(!rootp)
        return 0;
    
    else
    {
         lh = height(rootp->left);
         rh = height(rootp->right);
         
         if(lh >= rh)
              return 1 + lh;
          
          else
              return 1 + rh;
    }
         
} // height()


/********************  I N C R E M E N T   E A C H   D A T U M  **************

The following function traverses the binary tree pointed to by "rootp"
and replaces the datum value in each node by the number that's greater
by  1  in value.  The function is recursive.  The function documentation 
and heading were written by W. Knight.  */

void incrementEachDatum (NodePtr rootp)
{
     if(rootp)
     {
          rootp->datum++;
         
          incrementEachDatum(rootp->left);
          incrementEachDatum(rootp->right);
     }
} // incrementEachDatum()


/****************************  R E V E R S E  ******************************
                                                                          
This function replaces the binary tree pointed to by "rootp" with its     
mirror image.  The function is recursive.  The function documentation and
heading were written by W. Knight.                              */

void reverse (NodePtr &rootp)
{
    NodePtr temp;
    
    if(rootp)
    {
        reverse(rootp->left);
        reverse(rootp->right);
        
        temp = rootp->left;
        rootp->left = rootp->right;
        rootp->right = temp;
    }
} // reverse()


/*****************  S U M   O F   N E G A T I V E   D A T A ****************

The following function traverses the binary tree pointed to by "rootp",
sums the data values that are negative, and returns that sum.  For example,
if the tree contains nodes with data values  -2 , -6 , and -1 , and no
other nodes contain negative data, then the function will return the 
number  -9 .  If the tree contains no node with negative data value,
then the function returns zero .  The function is recursive.  The function
documentation and heading were written by W. Knight.  */

int sumOfNegativeData (NodePtr rootp)
{
     int sum = 0;
     
     if(rootp)
     {
          if(rootp->datum < 0)
              sum += rootp->datum;
          
          sum += sumOfNegativeData(rootp->left);
          sum += sumOfNegativeData(rootp->right);
     }
     
     return sum;
} // sumOfNegativeData()
