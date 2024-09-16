// MergeSort algorithm implementation. MergeSort is a divide and conquer algorithm that divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.

#include <stdio.h>
#include <stdlib.h>

int arr[8] = {24, 13, 29, 9, 19, 27, 35, 12};

void merge(int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort(int l, int r)
{
    if (l < r)
    {
        int m = (l+r) / 2;

        merge_sort(l, m);
        merge_sort(m + 1, r);

        merge(l, m, r);
    }
}


int main()
{
    merge_sort(0, 7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
