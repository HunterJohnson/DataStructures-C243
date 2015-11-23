/*** Hunter Johnson - November 2015 
         C243 HW9
		 
		 TO COMPILE using g++ in Windows (necessary because of chrono)
		 
		 g++ -std=c++11 -c quickSort.cc
		 g++ -std=c++11 -o quickSort quickSort.o
 ***/

#include "quickSort.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <algorithm>
#include <sys/time.h>

/***

LINUX Timing
declare variables
struct timeval before, after;	
double timing;
	
Before the sorting function:
gettimeofday(&before, 0);
After the function call:
gettimeofday(&after, 0);
timing = (double) ((double)after.tv_sec +
                   (double)after.tv_usec/(1000*1000)) -
         (double) ((double)before.tv_sec +
                   (double)before.tv_usec/(1000*1000));

				   ***/
				   
using namespace std::chrono;

int main(){
	
	int size, iterations;
	struct timeval before, after;
    double timing;
	
	std::cout << "Input array size: ";
	std::cin >> size;
	std::cout << "\n";
	std::cout << "Input number of quickSort() iterations to calc an average sorting time: ";
	std::cin >> iterations;
	std::cout << "\n";
	
	int a[size]; // initialize array to be sorted
	
	double times[iterations]; // initialize array of sorting times to calculate average over 100 iterations
	
	for(int i=0; i < iterations; i++) {
		for(int j =0; j < size; j++)
		{
			a[j] = rand() % size + 1;
		}
		int n = sizeof(a)/sizeof(a[0]);
	
	    high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	    quickSort(a, 0, n-1); // sort Array

        high_resolution_clock::time_point t2 = high_resolution_clock::now();
	
	    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	
	    double runTime = time_span.count() * 1000000;     // runTime in microseconds
			
        times[i] = runTime;
	}
	
	double sum = 0;
	for(int k=0; k < iterations; k++)       // calculate average runtime
		sum += times[k];
	
	double avg = (sum / iterations);  
	
	std::cout << "sorting a random array of size: " << size << " took an average of " << avg << " microseconds over " << iterations << " iterations" << std::endl;
	
	print(a, size);
	
	return 0;
} // main()


void print(int a[], int size)
{
    int i = 0;
    while(i < size){
        std::cout << a[i] << ",";
        i++;
    }
    std::cout << "\n";
} // print() - print sorted array




void quickSort(int array[], int left, int right){
      int i = left;
	  int j = right;
      int temp;
      int pivot = array[(left + right) / 2];  // set pivot to middle 
 
      // partition
      while (i <= j) {
            while (array[i] < pivot)
                  i++;
            while (array[j] > pivot)
                  j--;
            if (i <= j) {
                  temp = array[i];
                  array[i] = array[j];
                  array[j] = temp;
                  i++;
                  j--;
            }
      }
 
      // recursion
      if (left < j)
            quickSort(array, left, j);
      if (i < right)
            quickSort(array, i, right);
} // quickSort()




