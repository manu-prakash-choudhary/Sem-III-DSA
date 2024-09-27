#include <stdio.h>


int main(){
    int size = 6;
    int arr[6] = {10,
                  15,
                  17,
                  20,
                  8,
                  4};

    int arr2[6];

    for (int j = 0; j < 6; j++){

        int a = arr[j] * arr[j];
        printf("%d ", a);
        arr2[j] = a;
    }
    printf("\n");
    
}