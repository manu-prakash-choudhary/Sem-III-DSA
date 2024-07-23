// Quick Sort Algorithm

#include <stdio.h>
#include <stdlib.h>

int arr[8] = {24, 13, 29, 9, 19, 27, 35, 12};
void swap(int i, int j)
{
    int z = arr[i];
    arr[i] = arr[j];
    arr[j] = z;
}
int partition(int left, int right)
{
    int pivot;
    pivot = arr[left];
    int i, j;
    i = left + 1;
    j = right;
    while (i < j)
    {
        while (i <= right && arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (arr[i] < pivot)
        {
            break;
        }
        if (i < j)
        {
            swap(i, j);
        }
    }
    swap(left, j);
    return j;
}

void quick_sort(int left, int right)
{
    if (left < right)
    {
        int PI;
        PI = partition(left, right);
        printf("PI value -> %d\n", PI);
        quick_sort(left, PI - 1);
        quick_sort(PI + 1, right);
    }
}

int main()
{
    printf("Burrah\n");
    quick_sort(0, 7);
    printf("Burrah2\n");

    for (int i = 0; i < 8; i++)
    {
        printf("%d -> ", arr[i]);
    }

    return 0;
}
