/*** Hunter Johnson November 2015 ***/

#include "quickSort.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;

int main(){
	
	int a[100];
	
	for(int i=0; i < 100; i++)
		a[i] = rand() % 100 + 1;
	
	for(int i = 0; i < 100; i++)
		std::cout << a[i] << std::endl;
	
	int first = a[0];
	int last = a[99];
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	quickSort(a, first, last);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
	
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	
	std::cout << "sorting took " << time_span.count() << " seconds" << std::endl;


	for(int i = 0; i < 100; i++)
		std::cout << a[i] << std::endl;
	
	return 0;
} // main()

void quickSort(int array[], int left, int right){
      int i = left;
	  int j = right;
      int temp;
      int pivot = array[(left + right) / 2];
 
      /* partition */
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
 
      /* recursion */
      if (left < j)
            quickSort(array, left, j);
      if (i < right)
            quickSort(array, i, right);
} // quickSort()

