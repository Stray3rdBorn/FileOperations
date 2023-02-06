#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

int main()
{
    int size, first=0;
    cout << "Enter array size: ";
    cin >> size;
    int arr[size];

    ifstream read;
    read.open("input.txt");
    for(int i=0; i < size; i++)
    {
    	read >> arr[i];
	}

	cout << "Reading data from file.\n";
    cout << "Reading data from file complete.\n";

    cout << "\nNumber of data: " << size << endl;

    int item;
    cout << "\nEnter an element you would like to search: ";
    cin >> item;
    
    cout << "\nSearching...\n";
	double end;
	clock_t start;
    start = clock();

    int middle = (first+size)/2;
    while(first <= size)
    {
        if(arr[middle]==item)
        {
        	cout << item << " found at position " << middle << endl;
            break;
		}	
        if(arr[middle]<item)
			first = middle+1;
        else
            size = middle-1;
        middle = (first+size)/2;
    }
    if(first>size)
        cout << item << " is not found." << endl;

    end = ((double) clock() - start)/CLOCKS_PER_SEC;

    cout << "\nTime needed to execute: " << end << endl;
    return 0;
}
