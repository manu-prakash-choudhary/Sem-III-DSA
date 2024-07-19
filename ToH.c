#include <stdio.h>
#include <stdlib.h>

// Tower of Hanoi
void ToH(int n, char A, char B, char C){
    if (n == 1){
        printf("Move disk 1 from %c to %c\n", A, C);
        return;
    }
    ToH(n-1, A, C, B);
    printf("Move disk %d from %c to %c\n", n, A, C);
    ToH(n-1, B, A, C);
}

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    ToH(n, 'A', 'B', 'C');
    return 0;
}