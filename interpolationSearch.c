#include <stdio.h>
#include <stdlib.h>

count = 0;
// consider a sorted array with uniform distribution
// int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};

int size_arr = sizeof(arr) / sizeof(arr[0]);

void interpolation_recursive_search(int left, int right, int key)
{
    if (left <= right && key >= arr[left] && key <= arr[right])
    {
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (key - arr[left]));
        if (arr[pos] == key)
        {
            printf("Element found at index %d\n", pos);
            return;
        }
        if (arr[pos] < key)
        {
            interpolation_recursive_search(pos + 1, right, key);
        }
        else
        {
            interpolation_recursive_search(left, pos - 1, key);
        }
    }
    else
    {
        printf("Element not found\n");
    }
}

int main()
{
    interpolation_recursive_search(0, size_arr - 1, 50);
    // interpolation_recursive_search(0, size_arr - 1, 100);
    // interpolation_recursive_search(0, size_arr - 1, 10);
    // interpolation_recursive_search(0, size_arr - 1, 110);
    return 0;
}

