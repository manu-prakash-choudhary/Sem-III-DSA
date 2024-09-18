// Insertion Sort
// Insertion Sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

#include <stdio.h>
#include <stdlib.h>

int arr[8] = {24, 13, 29, 9, 19, 27, 35, 12};

void insertion_sort(int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    insertion_sort(8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}