//// The following main function shows way of taking values in and out of the console
#include<iostream> //C++ library called iostream (input/output stream library), short for input-output stream.

using namespace std; //In C++, all standard library features are grouped under a namespace called std

int main(){
    cout << "Give me an integer : ";  //cout refers to console output. '<<' (insertion operator - sends data to output stream) means send this to output stream
    int the_input_intger;
    cin >> the_input_intger; // cin refers to console input. '>>' (extraction operator) means take something from keyboard
    cout << endl << "You have entered " << the_input_intger; // 'endl' displays newline
    return 0;
}

//
//#include <iostream>
//using namespace std;
//
//int main() {
//    char choice;
//
//    cout << "Do you want to give an input?  ";
//    cin >> choice;
//
//    if (choice == 'Y') {
//        int the_input_integer;
//        cout << "Give me an integer: ";
//        cin >> the_input_integer;
//        cout << endl << "You have entered " << the_input_integer << endl;
//    }
//    else if (choice == 'N' || choice == 'n') {
//        cout << "No input given. Exiting program." << endl;
//    }
//    else {
//        cout << "Invalid choice. Please run again and enter Y or N." << endl;
//    }
//
//    return 0;
//}

//// The following main function shows basic mathematical operations
#include <iostream>

using namespace std;

int main(){
    double fahrenheit, celsius;
    cout << "Please enter the value in Fahrenheit : ";
    cin >> fahrenheit;
    celsius = ((fahrenheit - 32) * 5)/9;
    cout << "The value in Celsius is : " << celsius;
    return 0;
}

//// The following main function shows mathematical operation with cmath library and use of const variable
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double area, radius;
    const double pi = 3.1416;
    cout << "Please provide the radius : ";
    cin >> radius;

    cout << pi * pow(radius, 2);
    return 0;
}

//// The following main function shows type casting
#include <iostream>

using namespace std;

int main(){
    char a = 'a';
    bool a4 = true;
    cout << (int) a4;
    return 0;
}


//Bubble sort -> repeatedly goes through the list, compares adjacent elements, and swaps them if they are in the wrong order.
#include <iostream>
using namespace std;

int main() {
    // Initialize array of 4 numbers
    int arr[] = {5, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]); // number of elements

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

