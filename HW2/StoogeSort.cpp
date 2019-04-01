#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void stoogesort(int arr[],int l, int h);

int main(){
	ifstream infile("data.txt");
	string line;
	ofstream outfile;
	outfile.open ("stooge.out");
	
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
	//insertionSort(array, x);
	stoogesort(array, 0, x-1);
	
//	cout << "Sorted now" << endl;
	for(int i = 0; i < x; i++)
		outfile << array[i] << " ";
	outfile << endl;
//	printArray(array, x);
	
	}
}

void stoogesort(int arr[],int l, int h)//got this from http://www.geeksforgeeks.org/stooge-sort/
{
    if (l >= h)
      return;

    // If first element is smaller than last,
    // swap them
    if (arr[l] > arr[h])
       swap(arr[l], arr[h]);

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



// A utility function ot print an array of size n


