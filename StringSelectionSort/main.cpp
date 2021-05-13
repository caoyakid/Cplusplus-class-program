/*
Modify the selectionSort function presented in this chapter so it sorts an array of strings
instead of an array of ints.
*/

#include <iostream>
#include <string>
#include <cctype> //use isupper()
using namespace std;

//-----------Function implementation-----------
// purpose : make the string be uppercased
string upperCaseIt(const string stringIn)
{
    string s = stringIn;

    for (unsigned pos = 0; pos < s.length(); pos++)
    {
        s[pos] = toupper(s[pos]);
    }
    return s;
}

// purpose : sort the names into alphabetic(ascending) order
void selectionSort(string name[], int numStrings)
{
    int startScan, minIndex; // array index to be compared
    string minValue;

    // Sort the strings
    // Comparing from 1 to 19, get the minValue at a time ... so O(n=19)
    for (startScan = 0; startScan < (numStrings-1); startScan++){
        minIndex = startScan;
        minValue = name[startScan];
        for (int index = startScan+1; index < numStrings; index++){
            if(upperCaseIt(name[index]) < upperCaseIt(minValue)){
                minValue = name[index];
                minIndex = index; 
            }
        }
        name[minIndex] = name[startScan]; // put it backwards
        name[startScan] = minValue; // 
    }
}

// purpose : print the list of names
void displayNames(string name[], int numNames)
{
    for (int item = 0; item < numNames; item++)
    {
        cout << name[item] << endl;
    }
}



//-----------Driver program-----------
int main()
{
    const int SIZE = 20;

    // Set up the array of strings, in this case names
    string name[SIZE] =
        {"Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
         "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
         "Allison, Jeff", "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
         "Moretti, Bella", "Wu, Hong", "Patel, Renee", "Harrison, Rose",
         "Smith, Cathy", "Conroy, Pat", "Kelly, Sean", "Holland, Beth"};

    // Call a function to sort the strings
    selectionSort(name, SIZE);

    // Call a function to display the (now sorted) strings
    cout << "The names in sorted order are: \n\n";
    displayNames(name, SIZE);

    return 0;
}
