//Takes 5 integers from the user and stores them in a vector.
//Takes another integer as the search key.
//Performs Linear Search:
//Looks for the key in the vector from left to right.
//If found → prints the index
//If not → prints “Element not found”.


#include<bits/stdc++.h> //includes all standard libraries of C++

using namespace std;

int LinearSearch(vector<int>& v, int searchKey) { //takes a reference to vector (efficient, no copying) -> '&' means pass-by-reference
    for(int i=0;i<v.size();i++) { //loops through all elements
        if(v[i] == searchKey) return i; //if current element matches the key, returns its index
    }
    return -1; // else returns -1, key not found in the vector
}

int main()
{
    vector<int> a;
    int x, key;

    cout << "Enter elements: ";
    for(int i=0;i<5;i++) {
        cin >> x;
        a.push_back(x);
    }

    cout << "Enter search value: ";
    cin >> key;

    int y = LinearSearch(a,key);

    if(y==-1) cout << "Element not found";
    else cout << "Element found at " << y << " index!";

}
