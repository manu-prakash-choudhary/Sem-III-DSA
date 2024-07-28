#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age;
    int Resident_of_India;

    printf("Enter Your Age\n");
    scanf("%d", &age);
    printf("Entered age is %d\n", age);

    printf("Enter 1 if resident of India else 0\n");
    scanf("%d", &Resident_of_India);
    // Nested if-else
    if(age>=18){
        if(Resident_of_India == 1){

            printf("Eligible for Voting");
        }
        else{
            printf("Eligible for Voting But not in India");
        }
    }
    else{
        printf("Not Eligible for voting");
    }

    return 0;
}
