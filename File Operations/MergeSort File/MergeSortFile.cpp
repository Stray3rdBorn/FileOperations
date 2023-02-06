#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<time.h>
#define CLOCKS_PER_SECS 1000;
using namespace std;

void Merge(int arr[], int left, int mid, int right);
void MergeSort(int arr[], int left, int right);

int main()
{
    fstream myFile;
    string srg;
    int i=0;
    int arrsize=50740;
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
    MergeSort(arr, 0, arrsize-1);
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

void Merge(int arr[], int left, int mid, int right)
{
    int L[50740],R[50740],i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;

    for(i=1;i<=n1;i++)
        L[i]=arr[left+i-1];
    for(j=1;j<=n2;j++)
        R[j]=arr[mid+j];

    L[n1+1]=2000000;
    R[n2+1]=2000000;
    i=1;
    j=1;

    for(k=left;k<=right;k++)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
    }
}

void MergeSort(int arr[], int left, int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        MergeSort(arr,left, mid);
        MergeSort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}
