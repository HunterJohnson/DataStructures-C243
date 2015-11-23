/*********************************************************************
  Author:        Hunter Johnson 
  Class:         C243 Data Structures
  File name:     Queue.cc
  Last updated:  September 15, 2015
  Description:   Implementation of a class Queue derived from a list.
**********************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Queue.h"

// Default constructor: create an empty stack.
Queue::Queue() : List()
{
} // Queue::Queue()


// Insert an object into the queue.
void Queue::enqueue(int data)
{
	insertBack(data);
} // Queue::enqueue()


// Remove the front object and return its value.
int Queue::dequeue()
{
	int result = front();
    removeFront();
    return result;
} // Queue::dequeue()


// Inspect the value of the front object.
int Queue::front()
{
	 if (!isEmpty()) 
        return *begin();
    else 
    {
        cout << "attempt to access the front of an empty Queue" << endl;
        exit(1);
    }
}


// Delete all the objects in the queue.
void Queue::makeEmpty()
{
	List::makeEmpty(); 
} // Queue::makeEmpty()


// Test if the queue is empty.
bool Queue::isEmpty()
{
	return List::isEmpty();
} // Queue::isEmpty()


// Concatenate two queues.
void Queue::concatenate(Queue &other)
{
	List::concatenate(other);
}

// Very simple display of the queue for the purpose of the game.
void Queue::print()
{
    display();
} // Queue::print()

// The number of objects in the stack.
int Queue::stored()
{
    return getSize();
} // Queue::stored()
