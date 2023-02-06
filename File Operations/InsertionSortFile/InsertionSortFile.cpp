#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<time.h>
#define CLOCKS_PER_SEC 1000
using namespace std;

int main()
{
    fstream myFile;
    string srg;
    int i = 0, j, key;
    int datasize = 50740;
    int data[datasize] = {0};
    double end;
    clock_t start;

    myFile.open("input.txt", ios::in);
    if(myFile.is_open())
    {
        while(getline(myFile, srg))
        {
            string ss = srg;
            stringstream gs(ss);
            int num = 0;
            gs >> num;
            data[i++] = num;
        }
        myFile.close();
    }

	cout << "Reading data from file.\n";
	cout << "Reading data from file complete.\n";
	cout << "\nNow sorting data...\n";

    start=clock();

    for(j=1;j<=datasize;j++)
    {
        key=data[j];
        i=j-1;
        while(i>=0 && data[i]>key)
        {
            data[i+1]=data[i];
            i=i-1;
        }
        data[i+1]=key;
    }
    end = ((double) clock() - start)/CLOCKS_PER_SEC;

    cout << "Sorting completed." << endl;

    cout << "\n\nNo.of data\tTime needed for execution";
    cout << "\n-------------|----------------------------";
    cout << "\n" << datasize << "\t\t" << end << endl;

    myFile.open("output.txt", ios::out);
    if(myFile.is_open())
    {
        myFile << "Array elements after sorting:\n";
        for(i = 0; i < datasize; i++)
        {
            myFile << data[i] << "\n";
        }
        cout << endl;
        myFile.close();
    }

    return 0;
}
