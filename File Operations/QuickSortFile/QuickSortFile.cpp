#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<time.h>
#include<ctime>
#define CLOCKS_PER_SECS 1000;
using namespace std;

int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);

int main()
{
    fstream myFile;
    string srg;
    int i=0;
    int arrsize=6100054;
    int arr[arrsize] = {0};
    double end;
    clock_t start;

    myFile.open("input.txt", ios::in);
    if(myFile.is_open())
    {
        while(getline(myFile,srg))
        {
            string ss=srg;
            stringstream gs(ss);
            int num=0;
            gs >> num;
            arr[i++]=num;
        }
        myFile.close();
    }
    
    cout << "Reading data from file.\n";
    cout << "Reading data from file complete.\n";
    
    cout << "\nNow sorting...\n";

    start = clock();
    QuickSort(arr, 0, arrsize-1);
    end = ((double) clock() - start)/CLOCKS_PER_SEC;


    cout << "\nNumber of data: " << arrsize << endl;
    cout << "Time needed to execute: " << end << endl;

    myFile.open("output.txt", ios::out);
    if(myFile.is_open())
    {
        myFile << "Array after sorting: \n";
        for(int i=0;i<arrsize;i++)
            myFile << arr[i] << "\n";
        myFile.close();
    }
}

int Partition(int arr[], int left, int right)
{
    int pivot = arr[right];
	int i = left-1;
    for(int j=left; j<right; j++)
    {
    	if(arr[j] <= pivot)
    		{
    			i++;
    			swap(arr[i], arr[j]);
			}
	}
	swap(arr[i+1], arr[right]);
	return i+1;
}

void QuickSort(int arr[], int left, int right)
{
    if(left<right)
    {
        int mid = Partition(arr, left, right);
        QuickSort(arr, left, mid-1);
        QuickSort(arr, mid+1, right);   
    }
}
