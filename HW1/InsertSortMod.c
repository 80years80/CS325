#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main(){
	struct timespec start, finish;
	double elapsed;

	clock_gettime(CLOCK_MONOTONIC, &start);
	srand(time(NULL));
	int n = 15000;
	int *array = new int[n];
	for(int i = 0; i < n; i++)
		array[i] = rand() % (n+1);
	insertionSort(array, n);
	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec);

	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	printf("time is %f \n ", elapsed); 
}

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
