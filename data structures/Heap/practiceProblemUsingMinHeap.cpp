/*
Using your implementation, insert 10 arbitrary integer values in the heap. And provide a sorted list
of those number in ascending order.
*/


#include <bits/stdc++.h>
using namespace std;

#define MAX 1000 // Max-size of MinHeap


void makingHeap(int arr[], int n, int i)
{
    int parent = floor(i/2.0);

    if (arr[parent] > 0) {
        if (arr[i] < arr[parent]) {
            swap(arr[i], arr[parent]);
            makingHeap(arr, n, parent);
        }
    }
}


void heapify(int arr[], int n, int i){

    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l < n && arr[l] < arr[largest])
        largest = l;

    if (r < n && arr[r] < arr[largest])
        largest = r;


    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }

}

void printReverseHeap(int arr[], int n)
{
    for (int i = n; i >= 1; i--)
        cout << arr[i] << " ";

    cout << "\n";
}


void heapSort(int arr[], int n)
{
    for (int i = n/2; i >= 1; i--)
        heapify(arr, n, i);

    for (int i = n ; i >= 1; i--) {
        swap(arr[1], arr[i]);
        heapify(arr, i, 1);
    }

    printReverseHeap(arr, n);
}

void insertNode(int arr[], int* n, int Key)
{
    *n = *n + 1;
    arr[*n] = Key;
    makingHeap(arr, *n, *n);
}

void printArray(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    cout << "\n";
}


int main()
{
    int arr[10] = {1,5,7,6,25,12,33,14,12,20}; // 1-indexed

    int heapArray[MAX + 1];

    heapArray[0] = -1;
    int n = 0;

    for(int i = 0; i < 10; i++){
        insertNode(heapArray, &n, arr[i]);
    }

    printArray(heapArray, n);

    heapSort(heapArray, n);

    printArray(heapArray, n);


    return 0;
}
