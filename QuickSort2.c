#include <stdio.h>
#include <stdlib.h>

int arr[8] = {24, 13, 29, 9, 19, 27, 35, 12};
int partition(int left, int right)
{
    int pivot = arr[left];
    int left_array[8];
    int right_array[8];
    int lc = 0;
    int rc = 0;
    int i;
    for (i = left + 1; i <= right; i++)
    {
        if (arr[i] < pivot)
        {
            left_array[lc] = arr[i];
            lc++;
        }
        else
        {
            right_array[rc] = arr[i];
            rc++;
        }
    }

    for (i = 0; i < lc; i++)
    {
        arr[left + i] = left_array[i];
    }
    arr[left + i] = pivot;
    int PI = left + i;
    i++;
    for (int j = 0; j < rc; j++)
    {
        arr[left + i + j] = right_array[j];
    }

    return PI;
}

void quick_sort(int left, int right)
{

    if (left < right)
    {
        int PI = partition(left, right);
        quick_sort(left, PI - 1);
        quick_sort(PI + 1, right);
    }
}
int main()
{
    quick_sort(0, 7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d -> ", arr[i]);
    }

    return 0;
}

