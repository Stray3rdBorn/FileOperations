#include <iostream>
#include<fstream>
#include<time.h>
using namespace std;

int binarysearch(int arr[], int s, int e, int item)
{
    while(s <= e)
    {
        int m = (s+e)/2;
        if(arr[m] == item)
            return m;
        if(arr[m] < item)
            s = m + 1;
        else
            e = m - 1;
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int arr[size];

    ifstream read;
    read.open("input.txt");
    for(int i=0; i < size; i++)
    {
    	read >> arr[i];
	}
	
	cout << "Reading data from file complete.\n";

    int item;
    cout << "\nEnter an element you would like to search: ";
    cin >> item;
    cout << "\nNow searching...\n";
    
    double end;
    clock_t start;
    start=clock();
    int res = binarysearch(arr, 0, size-1, item);
    end = ((double) clock()- start)/1000;
    
    if(res == -1)
        cout << item << " is not found in the given array.\n";
    else
        cout << item << " is found at index " << res << endl;
    cout << "\n";
    
    cout << "Number of data: " << size << endl;
    cout << "Time needed to execute: " << end << endl;
    return 0;
}
