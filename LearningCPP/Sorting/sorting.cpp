// sorting algorithm comparison between: bubble, insertion, selection, merge

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iomanip>

using namespace std;

// Bubble Sort
void bubbleSort(vector<int>& arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // if the current element is greater than the next element
            {
                swap(arr[j], arr[j + 1]); // swap the elements
                swapped = true;
            }
        }
        if (swapped == false) // if no elements were swapped, break out of the loop
            break;
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // key is the current element
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key) // if the current element is greater than the key
        {
            arr[j + 1] = arr[j]; // move the element to the right
            j = j - 1;
        }
        arr[j + 1] = key; // insert the key into the correct position
    }
}

// Selection Sort
void selectionSort(vector<int>& arr, int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i; // set the minimum index to the current element
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) // if the current element is less than the minimum index
                min_idx = j; // set the minimum index to the current element

        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
}

// Merge Sort
void merge(vector<int>& arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; // size of the left subarray
    int n2 = r - m; // size of the right subarray

    /* create temp arrays */
    vector<int> L(n1), R(n2);

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) // copy the left subarray
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++) // copy the right subarray
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = l; // initial index of merged subarray
    while (i < n1 && j < n2) // while there are still elements in both subarrays
    {
        if (L[i] <= R[j]) // if the current element in the left subarray is less than or equal to the current element in the right subarray
        {
            arr[k] = L[i]; // copy the current element in the left subarray to the merged subarray
            i++; // increment the index of the left subarray
        }
        else // if the current element in the right subarray is less than the current element in the left subarray
        {
            arr[k] = R[j]; // copy the current element in the right subarray to the merged subarray
            j++; // increment the index of the right subarray
        }
        k++; // increment the index of the merged subarray
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) // while there are still elements in the left subarray
    {
        arr[k] = L[i]; // copy the current element in the left subarray to the merged subarray
        i++; // increment the index of the left subarray
        k++; // increment the index of the merged subarray
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) // while there are still elements in the right subarray
    {
        arr[k] = R[j]; // copy the current element in the right subarray to the merged subarray
        j++; // increment the index of the right subarray
        k++; // increment the index of the merged subarray
    }
}

void mergeSort(vector<int>& arr, int l, int r)
{
    if (l >= r) // if the left index is greater than or equal to the right index
    {
        return; // return
    }
    int m = l + (r - l) / 2; // find the middle index
    mergeSort(arr, l, m); // sort the left subarray
    mergeSort(arr, m + 1, r); // sort the right subarray
    merge(arr, l, m, r); // merge the two subarrays
}

// main
int main()
{
    srand(time(NULL)); // seed the random number generator

    // create a vector of 100,000 random numbers
    vector<int> arr(100000);
    for (int i = 0; i < 100000; i++)
    {
        arr[i] = rand() % 100000;
    }

    // create a copy of the vector
    vector<int> arr2 = arr;
    vector<int> arr3 = arr;
    vector<int> arr4 = arr;

    // bubble sort
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr, arr.size());
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Bubble Sort: " <<  elapsed.count() << " seconds" << endl;

    // insertion sort
    start = chrono::high_resolution_clock::now();
    insertionSort(arr2, arr2.size());
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Insertion Sort: " <<  elapsed.count() << " seconds" << endl;

    // selection sort
    start = chrono::high_resolution_clock::now();
    selectionSort(arr3, arr3.size());
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Selection Sort: " << elapsed.count() << " seconds" << endl;

    // merge sort
    start = chrono::high_resolution_clock::now();
    mergeSort(arr4, 0, arr4.size() - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Merge Sort: " << elapsed.count() << " seconds" << endl;

    return 0;
}


