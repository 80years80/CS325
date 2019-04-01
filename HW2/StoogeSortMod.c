#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void stoogesort(int arr[],int l, int h);
void swap(int low, int high);
int main(){
	struct timespec start, finish;
	double elapsed;

	clock_gettime(CLOCK_MONOTONIC, &start);
	srand(time(NULL));
	int n = 700;
	int *array = new int[n];
	for(int i = 0; i < n; i++)
		array[i] = rand() % (n+1);
	stoogesort(array, 0, n-1);
	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec);

	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	printf("time is %f \n ", elapsed);
}

void stoogesort(int arr[],int l, int h)//got this from http://www.geeksforgeeks.org/stooge-sort/
{
    if (l >= h)
      return;

    // If first element is smaller than last,
    // swap them
    if (arr[l] > arr[h])
	{
       swap(arr[l], arr[h]);
	}

    // If there are more than 2 elements in
    // the array
    if(h-l+1>2)
    {
        int t = (h-l+1)/3;

        // Recursively sort first 2/3 elements
        stoogesort(arr, l, h-t);

        // Recursively sort last 2/3 elements
        stoogesort(arr, l+t, h);

        // Recursively sort first 2/3 elements
        // again to confirm
        stoogesort(arr, l, h-t);
    }
}

void swap(int low, int high)
{
	int temp = low;
	low = high;
	high = temp;
	
}
// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
