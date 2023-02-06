#include<iostream>
#include<fstream>
#include<time.h>
#define CLOCKS_PER_SEC 1000
using namespace std;

int main()
{
    int size;
    cout << "Enter data size: ";
    cin >> size;
    int data[size];
    double end;
    clock_t start;

    ifstream read;
    read.open("input.txt");
    for(int i=0;i<size;i++)
    {
    	read >> data[i];
	}
    
    cout << "Reading data from file.\n";
    cout << "Reading data from file complete.\n";

    int item;
    cout << "\nEnter an element to be searched: ";
    cin >> item;
    
    cout << "\nSearching...\n";

    start=clock();
	
	int i;
    for(i = 0; i < size; i++)
    {
        if(data[i] == item)
        {
            cout << "Element " << item << " found at index " << i;
            break;
        }
    }
    if(i == size)
        cout  << "Element is not present in array.\n";

    end = ((double) clock() - start)/CLOCKS_PER_SEC;

    cout << "\n\nNo.of data\tTime needed for execution";
    cout << "\n------------|----------------------------";
    cout << "\n" << size << "\t\t" << end << endl;

    return 0;
}
