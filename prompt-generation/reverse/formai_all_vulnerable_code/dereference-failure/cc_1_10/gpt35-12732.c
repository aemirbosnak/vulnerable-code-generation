//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr1,*ptr2,*ptr3;
    int i;

    //Allocating memory to ptr1
    ptr1 = (int*) malloc(3 * sizeof(int));
    printf("Memory allocated to ptr1.\n");

    //Allocating memory to ptr2
    ptr2 = (int*) calloc(3 , sizeof(int));
    printf("Memory allocated to ptr2.\n");

    //Allocating memory to ptr3
    ptr3 = (int*) realloc(ptr1 , 5 * sizeof(int));
    printf("Memory reallocated to ptr3.\n");

    //Writing to ptr1
    *ptr1 = 1;
    *(ptr1 + 1) = 3;
    *(ptr1 + 2) = 5;

    //Writing to ptr2
    *ptr2 = 2;
    *(ptr2 + 1) = 4;
    *(ptr2 + 2) = 6;

    //Writing to ptr3
    *(ptr3 + 3) = 7;
    *(ptr3 + 4) = 9;

    //Printing values of ptr1
    printf("Values stored in ptr1:\n");
    for(i = 0 ; i < 3 ; i++){
        printf("%d " , *(ptr1 + i));
    }

    //Printing values of ptr2
    printf("\n\nValues stored in ptr2:\n");
    for(i = 0 ; i < 3 ; i++){
        printf("%d " , *(ptr2 + i));
    }

    //Printing values of ptr3
    printf("\n\nValues stored in ptr3:\n");
    for(i = 0 ; i < 5 ; i++){
        printf("%d " , *(ptr3 + i));
    }

    //Deallocating memory
    free(ptr1);
    free(ptr2);
    free(ptr3);

    printf("\n\nMemory deallocated successfully.");

    return 0;
}