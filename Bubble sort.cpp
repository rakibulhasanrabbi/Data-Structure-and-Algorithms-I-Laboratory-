  //Bubble sort -> repeatedly goes through the list, compares adjacent elements, and swaps them if they are in the wrong order.
#include <iostream>
using namespace std;

int main() {
    // Initialize array of 4 numbers
    int arr[] = {5, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]); // number of elements (total bytes of array / byte of one element)

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Bubble Sort algorithm
    for (int i = 0; i < n - 1; i++) { // outer loop for passes
        for (int j = 0; j < n - i - 1; j++) { // inner loop for comparisons
            if (arr[j] > arr[j + 1]) { // swap if out of order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        // Print array after each pass (to see sorting progress)
        cout << "After pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }

    // Print the final sorted array
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
