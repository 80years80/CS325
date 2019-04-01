#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main(){
	ifstream infile("data.txt");
	string line;
	ofstream outfile;
	outfile.open ("insert.out");
	
	while(getline(infile, line))
	{
		istringstream iss(line);
		int n;
		vector<int> v;

	while(iss >> n)
		v.push_back(n);
	//cout << v[0] << endl;

	int x = v.size();
//	for(int i = 0; i < x; i++)
//	{
//		cout << v[i] << endl;
//	}
	int j = 0;
	x = x - 1;	
	int *array = new int[x];
//	cout << "x is " << x << endl;
	for(int i = 0; i < x; i++)
	{
		j++;	
		array[i] = v[j];	
	}
	//for(int i = 0; i < x; i++)
	//	outfile << array[i] << " ";
	//outfile << endl;
	insertionSort(array, x);
//	cout << "Sorted now" << endl;
	for(int i = 0; i < x; i++)
		outfile << array[i] << " ";
	outfile << endl;
//	printArray(array, x);
	
	}
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
