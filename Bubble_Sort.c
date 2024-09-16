// Bubble Sort 
// Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

#include <stdio.h>
#include <stdlib.h>

int arr[8] = {24, 13, 29, 9, 19, 27, 35, 12};
void swap(int i, int j)
{
    int z = arr[i];
    arr[i] = arr[j];
    arr[j] = z;
}

void bubble_sort(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(j, j + 1);
            }
        }
    }
}

int main()
{
    bubble_sort(8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}