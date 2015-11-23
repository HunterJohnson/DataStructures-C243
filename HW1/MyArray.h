/********************************************************************
  Author:       Hunter Johnson, Dana Vrajitoru, IUSB, CS
  Class:         C243, Fall 2015
  File name:     MyArray.h
  Last updated:  September 1, 2015.
  Description:   Definition of a class that implements a safe array.
*********************************************************************/

#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <iostream>
using namespace std;

class MyArray 
{
protected:
    int size;
    int *array;

public:
    // Constructor with given size, can be used as default constructor.
    MyArray(int theSize = 0);

    // Destructor. If the array is not empty, it must be deallocated.
    ~MyArray();

    // Copy constructor
    MyArray(MyArray &data);

    // Assignment operator
    MyArray &operator=(MyArray &data);

    // Deletes the array and sets the size to 0.
    void empty();

    // Resize the array.
    void resize(int theSize = 0);

    // Access an element of the array. If the index (subscript) is out
    // of the array, it prints an error message and exits the program.
    int &operator[](int index);

    // Returns the size of the array.
    int getSize();

    // Output the elements of the array.
    void output();

    // We define this so that we can write "cout << a;" if a is an
    // object of this class.
    friend ostream &operator<<(ostream &out, MyArray &data);
    //friend istream &operator>>(istream &in, MyArray &data);
	
	// Input the elements of the array through the console  -- HW#1
	void input();
	
	//Initialize the elements of the array with random values between 0 and a given maximum limit
    //provided as a parameter. The size of the array will be provided as a second parameter.  -- HW#2
	void randomize(int limit, int theSize = 0);
	
	/*Compare the elements of the array with another one and decide if they are equal or not (2    -- HW #3
    functions). One of the operators must be explicitly implemented with a for loop comparing the
    elements of the arrays one by one. The other operator should simply return the opposite of the
    first one by calling it (one line of code).
	
	Note. If the arrays don't have the same size, they are not equal no matter what the elements are.
    This is a simple test since we know the size of the arrays explicitly and it should be done before
    the for loop. */
	
     bool operator==(MyArray &data);
     bool operator!=(MyArray &data);
	 
	/* Compute the Hamming distance between two arrays, by counting the number of elements in the  -- HW #4
    two arrays that are different. For example, the distance between the following arrays
          2 1 6 3 4
          5 1 6 8 4
     is 2 because the first and fourth elements of the two arrays are different. If the two arrays are
     equal, the distance between the should be 0. */
     
	 int hamming(MyArray &data);

}; // class MyArray

#endif
