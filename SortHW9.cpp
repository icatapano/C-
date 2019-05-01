// Homework 9 Sorting Algorithm
// Class C243
// By Ian Catapano
// Created 11/17/2014

#include <cstdlib>
#include <iostream>
#include <sys/time.h>

using namespace std;

// Function Prototypes
void quickSort(long* array, long first, long last);
void displayArray(long array[], long size);

// Main function
int main()
{
    struct timeval before, after;
    double timing;
    long *inputArray;
    long size = 0;
    
    cout << "Please enter the size of the array to be sorted." << endl;
    cin >> size;
    inputArray = new long[size];
    cout << "Enter the elements of the array." << endl;
    for (long i = 0; i < size; i++)
        cin >> inputArray[i];
    gettimeofday(&before, 0);
    quickSort(inputArray, 0, size - 1);
    gettimeofday(&after, 0);
    timing = (double)((double)after.tv_sec + (double)after.tv_usec / (1000 * 1000)) -
             (double)((double)before.tv_sec + (double)before.tv_usec / (1000 * 1000));
    displayArray(inputArray, size);
    cout << "Sort time: " << timing << endl;
    delete[] inputArray;
    system("PAUSE");
    return 0;
}

// Quick sort array used to sort an array entered by the user.
void quickSort(long* array, long first, long last)
{
    if (last <= first)
        return;
    long pivot = array[first];
    long i = first + 1, j = last;
    while (i < j)
    {
        while (array[i] < pivot && i < j)
            i++;
        while (array[j] > pivot)
            j--;
        if (i < j)
            swap(array[i++], array[j--]);
    }
    if (array[j] > pivot)
        j--;
    swap(array[j], array[first]);
    quickSort(array, first, j - 1);
    quickSort(array, j + 1, last);
} // quickSort()

// Function to display contents of the array.
void displayArray(long array[], long size)
{
    for (long i = 0; i < size; i++)
        cout << array[i] << endl;
    return;
}// displayArray()