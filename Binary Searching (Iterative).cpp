//Takes n from the user
//Reads n sorted values into an array
//Takes a search value
//Uses Binary Search to find the value
//Prints the index if found, otherwise prints Not found
//Here code assumes that the input is already sorted (in ascending or descending order)


#include <bits/stdc++.h>

using namespace std;

int binarySearch(int array[], int x, int low, int high) { // low - starting index, high ending index

  while (low <= high) { //search continues as long as there are elements between high and low
    int mid = low + (high - low) / 2; //prevents integer overflow

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int n, value;
    cout << "Enter value of n: ";
    cin >> n;

    int a[n];
    cout << "Enter values: ";
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter search value: ";
    cin >> value;

    int result = binarySearch(a, value, 0, n - 1);
    if (result == -1)
        cout << "Not found";
    else
        cout << "Item found at " << result;
}
