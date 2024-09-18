// Radix Sort Algorithm
// Radix Sort is a non-comparative sorting algorithm. It avoids comparison by creating and distributing elements into buckets according to their radix. For elements with more than one digit, each element is placed in a particular bucket based on the value of the most significant digit. The process is repeated for each digit, moving from the least significant digit to the most significant digit. The time complexity of Radix Sort is O(d*(n+b)), where n is the number of elements, b is the base for representing numbers, and d is the number of digits in the maximum number.

#include <stdio.h>
#include <stdlib.h>

int arr[8] = {24, 13, 29, 9, 19, 27, 35, 12};
int exp;
int n = 8;

int getMax()
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int n)
{
    int output[8];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}



int main()
{
    
    
    int m = getMax();
    printf("Max value -> %d\n", m);
    exp = 1;
    while(m > 0){
        countSort(n);
        exp = exp*10;
        m /= 10;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}