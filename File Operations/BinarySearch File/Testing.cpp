#include<iostream>
#include<fstream>
#include<sstream>
#include<time.h>
#include<ctime>
#include<string>
#define CLOCKS_PER_SEC 1000
using namespace std;

int main()
{
    fstream myfile;
    string srg1;
    int i = 0, first = 0;
    int arrsize = 5000;
    int arr[arrsize] = {0};

    myfile.open("input.txt", ios::in);
    if(myfile.is_open())
    {
        while(getline(myfile, srg1))
        {
            string srg2=srg1;
            stringstream convert(srg2);
            int num = 0;
            convert >> num;
            arr[i++]=num;
        }
        myfile.close();
    }

    cout << "Number of data: " << arrsize << endl;

    int item;
    cout << "\nEnter an element you would like to search: ";
    cin >> item;

    double end;
    clock_t start;
    start = clock();


    int middle = (first+arrsize)/2;
    while(first <= arrsize)
    {
        if(arr[middle]<item)
            first = middle+1;
        else if(arr[middle]==item)
        {
            cout << "\nThe number " << item << " found at position " << middle << endl;
            break;
        }
        else
            arrsize = middle-1;
        middle = (first+arrsize)/2;
    }
    if(first>arrsize)
        cout << "\nThe number " << item << " is not found in given Array." << endl;

    end = ((double) clock() - start)/CLOCKS_PER_SEC;

    cout << "\nTime needed to execute: " << end << endl;
    return 0;
}

