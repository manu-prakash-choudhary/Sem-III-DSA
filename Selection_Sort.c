// Selection Sort is a simple sorting algorithm that divides the input list into two parts: the sublist of items already sorted and the sublist of items remaining to be sorted. The algorithm selects the smallest element from the unsorted sublist and swaps it with the leftmost unsorted element.

#include <stdio.h>
#include <stdlib.h>

int arr[8] = {24, 13, 29, 9, 19, 27, 35, 12};
void swap(int i, int j)
{
    int z = arr[i];
    arr[i] = arr[j];
    arr[j] = z;
}

void selection_sort(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(i, min);
    }
}

int main()
{
    selection_sort(8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}