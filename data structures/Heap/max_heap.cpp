#include <bits/stdc++.h>
using namespace std;

#define MAX 1000 // Max-size of MaxHeap

void heapAfterInsertion(int arr[], int n, int i)
{
    int parent = floor(i/2.0);

    if (arr[parent] > 0) {
        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapAfterInsertion(arr, n, parent);
        }
    }
}

void heapAfterDeletion(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;


    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapAfterDeletion(arr, n, largest);
    }
}

void deleteRoot(int arr[], int *n)
{
    int lastElement = arr[*n];

    arr[0] = lastElement;
    *n = *n - 1;
    heapAfterDeletion(arr, *n, 0);
}


void insertNode(int arr[], int* n, int Key)
{
    *n = *n + 1;
    arr[*n] = Key;
    heapAfterInsertion(arr, *n, *n);
}


void printArray(int arr[], int n)
{
    for (int i = 1; i <= n; ++i)
        cout << arr[i] << " ";

    cout << "\n";
}


int main()
{
    int arr[MAX + 1] = {-1, 10, 5, 3, 2, 4 }; // 1-indexed

    int n = 5;
    int key = 15;

    printArray(arr, n);

    insertNode(arr, &n, key);

    printArray(arr, n);

    deleteRoot(arr, &n);

    printArray(arr, n);

    return 0;
}
