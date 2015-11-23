/********************************************************************
  Author:        Hunter Johnson, Dana Vrajitoru, IUSB, CS
  Class:         C243, Fall 2015
  File name:     main.cc
  Last updated:  September 1, 2015.
  Description:   Testing the class MyArray.
*********************************************************************/

#include "MyArray.h"
#include <iostream>
using namespace std;

// main function
int main()
{
    MyArray a1, a2, a3;
	
	a1.input();
	
	a2.randomize(10, a1.getSize());
	a3.randomize(10, a1.getSize());
	
	if (a1 == a2)
		cout << "Arrays 1 and 2 are equal" << endl;
	else
		cout << "Arrays 1 and 2 are not equal" << endl;
	
	int hamm = a2.hamming(a3);
	
	cout << "The Hamming distance of arrays 2 and 3 is: " << hamm << endl;
	
    return 0;
} // main()

