// This program compares the number of exchanges made by Bubble
// Sort vs. Selection Sort to sort a set of long integers.
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 30; 

// Function prototypes
int bubbleSort(long[], int);
int selectionSort(long[], int);

int main()
{
    int exchanges1, exchanges2; // number of exchanges made during the sort

    long accounts1[SIZE] =
        {7058845, 9820125, 2214122, 4007541, 5001277, 6002850,
         1200152, 8002555, 3202012, 1315352, 8115877, 9120255,
         3298831, 9523331, 8073085, 4676651, 2681002, 9691212,
         3082248, 1004354, 1243248, 2384875, 8237589, 8548383,
         2049300, 3853482, 3589983, 9389493, 1284736, 2877277};

    long accounts2[SIZE] =
        {7058845, 9820125, 2214122, 4007541, 5001277, 6002850,
         1200152, 8002555, 3202012, 1315352, 8115877, 9120255,
         3298831, 9523331, 8073085, 4676651, 2681002, 9691212,
         3082248, 1004354, 1243248, 2384875, 8237589, 8548383,
         2049300, 3853482, 3589983, 9389493, 1284736, 2877277};

    cout << "The same 30 numbers were sorted by each of two sorts.\n\n";

    exchanges1 = bubbleSort(accounts1, SIZE);
    cout << setw(3) << exchanges1
         << " exchanges were made by Bubble Sort.\n\n";

    exchanges2 = selectionSort(accounts2, SIZE);
    cout << setw(3) << exchanges2
         << " exchanges were made by Selection Sort.\n";

    return 0;
}

int bubbleSort(long array[], int numElts)
{
    bool swap;
    int exchanges = 0;
    long temp;

    do{
        swap = false; // There have been no swaps yet on this pass
        for(int count = 0; count < (numElts-1); count++)
        {
            if(array[count] > array[count+1]){
                temp = array[count];
                array[count] = array[count+1];
                array[count+1] = temp;
                swap = true;
                exchanges++; // Count the swap
            }
        }
    } while (swap); // While there was a swap on the previous pass

    return exchanges;
}

int selectionSort(long array[], int numElts)
{
    int startScan, minIndex, exchanges = 0;
    long minValue;

    for(startScan = 0; startScan < (numElts-1); startScan++){
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < numElts; index++){
            if(array[index] < minValue){
                minValue = array[index];
                minIndex = index;
            }
        }
        // Move values to their new positions
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
        exchanges++; // Count the swap
    }
    return exchanges;
}
