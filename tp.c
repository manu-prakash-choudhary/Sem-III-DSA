// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


int main(){
    char a = '*';
    for (int i = 1; i <=4;i++)
    {
        for (int j = 1; j < 3 + i  ;j++){
            printf("%c", a);
            
        }
        printf("\n");
    }

    return 0;
}