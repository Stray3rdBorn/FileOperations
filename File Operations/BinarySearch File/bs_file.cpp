#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
//store each number in separate line inside the text file
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int main () {
//for storing each line from the file
  string srg;
  //new empty array
  int myArray[10] = { 0 };
  //index for inserting array
  int i = 0;
  //size of array
  int n = 10;
  //file operation initialization
  ifstream filestream("testout.txt");
  if (filestream.is_open())
  {
    while ( getline (filestream,srg) )
    {

      string ss = srg;

		//converting string to int for storing in array
      stringstream gs(ss);
      int num = 0;
      gs >> num;
      //storing the converted int in array
      myArray[i++] = num;

    }
    filestream.close();
  }
  else {
      cout << "File opening is fail."<<endl;
    }
//checking the elements of array
//    for (int i = 0; i < 10; i++) {
//	  cout << myArray[i] << "\n";
//	}

int result = binarySearch(myArray, 0, n-1, 799);
(result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
  return 0;
}
