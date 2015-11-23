/*** Hunter Johnson / Jonathan Wideman- November 2015 
         C243 HW9
 ***/

#include "quickSort.h"
#include <iostream>
#include <sys/time.h>

using namespace std;

int main(){
	
	int size;
	struct timeval before, after;
    double timing;
	
	cout << "Input array size: ";
	cin >> size;
	cout << "\n";
	
	int a[size]; // initialize array to be sorted
	
    cout << "Input array elements: ";
	
		for(int i=0; i < size; i++)
		{
			cin >> a[i];
		}
		
	cout << "\n";
		
	int n = sizeof(a)/sizeof(a[0]);

    gettimeofday(&before, 0); // timing function
		
    quickSort(a, 0, n-1); // sort Array
		
	gettimeofday(&after, 0);
		
    timing = (double) ((double)after.tv_sec +
                   (double)after.tv_usec/(1000*1000)) -
         (double) ((double)before.tv_sec +
                   (double)before.tv_usec/(1000*1000));
				   
	print(a, size);
	
	cout << "Sorting an array of size = " << size << " took " << timing << " seconds. \n";
	
	return 0;
} // main()

void print(int a[], int size)
{
    int i = 0;
    while(i < size){
        cout << a[i] << ",";
        i++;
    }
   cout << "\n";
} // print() S

void quickSort(int array[], int left, int right){
      int i = left;
	  int j = right;
      int temp;
      int pivot = array[(left + right) / 2];  // set pivot = to middle 
 
      // partition
      while(i <= j) {
            while(array[i] < pivot)
                  i++;
            while(array[j] > pivot)
                  j--;
            if(i <= j) {
                  temp = array[i];
                  array[i] = array[j];
                  array[j] = temp;
                  i++;
                  j--;
            }
      }
 
      // recursion
      if(left < j)
          quickSort(array, left, j);
      if(i < right)
          quickSort(array, i, right);
} // quickSort()




