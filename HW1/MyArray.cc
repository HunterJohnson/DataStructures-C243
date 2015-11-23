/********************************************************************
  Author:        Hunter Johnson, Dana Vrajitoru, IUSB, CS
  Class:         C243, Fall 2015
  File name:     MyArray.cc
  Last updated:  September 1, 2015.
  Description:   Implementation of a class that implements a safe array.
*********************************************************************/

#include "MyArray.h"
#include <iostream>
using namespace std;
#include <cstdlib>

// Constructor with given size, can be used as default constructor.
MyArray::MyArray(int theSize)
{
    // initialize the object as empty
    array = NULL;
    size = 0;
    // then use the resize function to allocate the memory
    resize(theSize);
} // MyArray::MyArray()

// Destructor. If the array is not empty, it must be deallocated.
MyArray::~MyArray()
{
    // call the function empty instead, so we only need to modify in 
    // one place if anything changes
    empty();
} // MyArray::~MyArray()

// Copy constructor: initializes the target object with the size of
// the object data and copies the content of the object data into the
// target object.
MyArray::MyArray(MyArray &data)
    : size(data.size) // initialize the size
{
    // allocate the array
    array = new int[size];

    // copy all the values from data
    for (int i=0; i<size; i++)
        array[i] = data.array[i];
} // MyArray::MyArray()

// Assignment operator: if the object data is different from the
// target object, initializes the target obkect with the size of the
// object data and copies the content of the object data.
MyArray &MyArray::operator=(MyArray &data)
{
    // check that we're not trying to copy an object onto itself
    if (this != &data) // different address in the memory
    {
        resize(data.size);
        for (int i=0; i<size; i++)
            array[i] = data.array[i];
    }
    else 
        cout << "Attempt to copy an object on itself. " 
             <<"Operation ignored." << endl;
    return *this;
} // MyArray::operator=()

// Deallocate the array and reset the size to 0
void MyArray::empty()
{
    // make sure we have an array to delete
    if (size != 0 && array != NULL) 
    {
        size = 0;
        delete [] array;
        array = NULL; // make the pointer NULL after deallocating 
    }
} // MyArray::empty()

// Resize the array with the new size. If the object contains an
// array, it is deallocated first.
void MyArray::resize(int theSize)
{
    if (theSize >= 0)     // check that the new size is valid
    {
        if (size > 0)     // if the array is not empty, deallocate first
            empty();
        if (theSize != 0) // allocate again if the size is not 0
        {
            size = theSize;
            array = new int[size];
        }
    }
    else                  // negative size, give an error message
        cout << "Resize attepmted with a negative size. "
             << "Operation ignored." << endl;
} // MyArray::resize()

// Access an element of the array. If the index (subscript) is out
// of the array, it prints an error message and exits the program.
int &MyArray::operator[](int index)
{
    // check that the index is in the right range
    if (index >= 0 && index < size) 
        return array[index]; 
    else // error
    {
        cerr << "Illegal access to an element of the array." << endl
             << "The size of the array was " << size 
             << " and the index was " << index << endl;
        exit(1);
    }
} // MyArray::operator[]()

// Returns the size of the array.
int MyArray::getSize()
{
    return size;
} // MyArray::getSize()


// Output the elements of the array.
void MyArray::output()
{
    // output the size
    cout << "The array of size " << size 
         << " contains the elements:" << endl;
    // then all the elements
    for (int i=0; i<size; i++)
        cout << array[i] << ' ';
    cout << endl;
} // MyArray::output()

// We define this so that we can write "cout << a;" if a is an object
// of this class. This is not a class method.
ostream &operator<<(ostream &out, MyArray &data)
{
    // output the size
    out << "The array of size " << data.size 
        << " contains the elements:" << endl;
    // then all the elements
    for (int i=0; i<data.size; i++)
        out << data.array[i] << ' ';
    out << endl;
    return out;
} // operator<<()

void MyArray::input()     // HW #1 - input elements of array initialized to given size 
{
	cout << "Input array size: " << endl;
	cin >> size;
	cout << "size is " << size << endl;
	
	resize(size);
	
	for (int i=0; i<size; i++)
	{
		cout << "Input element: " << endl;
		cin >> array[i];
	}	
}  // MyArray::input()

void MyArray::randomize(int  limit, int theSize)  // HW#2 - initialize array of given size with random values in range 0 - limit 
{	
	if(theSize > 0)
	{
		resize(theSize);
		
		for (int i=0; i<theSize; i++)
		{
			array[i] = rand() % (limit + 1);  // random number between 0 and given max limit
		}
	}
}  // MyArray::randomize()

bool MyArray::operator==(MyArray &data)   // HW#3 - check if 2 arrays are equal 
{
	if (size  != data.size)
		return false;
	
	for (int i=0; i<size; i++)
	{
		if (array[i] != data.array[i])
			return false;
	}
	
	return true;
} // MyArray::operator==

bool MyArray::operator!=(MyArray &data) // HW#3 - check if 2 arrays are not equal
{
	return !(this -> operator==(data));  
} // MyArray::operator!=
	
int MyArray::hamming(MyArray &data)  // HW#4 return Hamming distance of 2 arrays 
{
	int hdist = 0,  s = size, l = data.size;
	
	if (data.size < size)  // specify smaller array if sizes are different
	{
		s = data.size;
		l = size;
	}
	
	for (int i=0; i < s; i++)  // count number of different elements
	{
		if (array[i] != data.array[i])
			++hdist; 
	}
	
	hdist += (l - s);       // if array sizes are different add difference to count for final value
	return hdist;
} // MyArray::hamming()