/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: serva
 *
 * Created on September 22, 2019, 7:29 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

// Function prototypes
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

int main()
{
    // variable to hold user choice of number of donations
    int numElements;
    cout << "Enter number of donations: ";
    cin >> numElements;

    //validate input
    while(numElements < 1){
        cout << "Please enter a number not less than 1: ";
        cin >> numElements;
    }

    // dynamically allocate array of ints
    int *donations = new int[numElements];

    //read values into array
    for(int count = 0; count < numElements; count++){
        cout << "Donation " << count+1 << ": ";
        cin >> *(donations + count);
    }

    // An array of pointers to int.
    int *arrPtr[numElements];

    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count < numElements; count++ )
        arrPtr[count] = &donations[count];

    // Sort the elements of the array of pointers.
    arrSelectSort(arrPtr, numElements);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in ascending order are: \n";
    showArrPtr(arrPtr, numElements);

    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(donations, numElements);
    return 0;
}

//***************************************************************
// Definition of function arrSelectSort.                        *
// This function performs an ascending order selection sort on  *
// arr, which is an array of pointers. Each element of array    *
// points to an element of a second array. After the sort,      *
// arr will point to the elements of the second array in        *
// ascending order.                                             *
//***************************************************************
//sort the selected array
void arrSelectSort(int *arr[], int size){
    int startScan, minIndex; 
    int *minElem; 
    
    for(startScan =0; startScan<size-1; startScan++){
        minIndex = startScan; 
        minElem = arr[startScan];
        for(int index = startScan +1; index < size; index++){
            if(*(arr[index])>*minElem){ //flip the greater or less than sign to 
                minElem = arr[index];   //descend it
                minIndex=index; 
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem; 
    }
}

//display the array
void showArray(const int arr[], int size){
    for(int count=0; count < size; count++){
        cout<<arr[count]<<" "<<endl;
    }
}

//print the array
void showArrPtr(int *arr[], int size){
    for(int count = 0; count < size; count++){
        cout<< *(arr[count])<<" "<<endl; 
    }
}