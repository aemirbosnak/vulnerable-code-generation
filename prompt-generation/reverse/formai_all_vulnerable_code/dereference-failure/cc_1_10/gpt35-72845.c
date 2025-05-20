//FormAI DATASET v1.0 Category: Memory management ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //Initializing variables
    int *ptr1, *ptr2, *ptr3;
    int n = 5, i;
 
    //Dynamic memory allocation using malloc()
    ptr1 = (int*)malloc(n * sizeof(int));
    ptr2 = (int*)malloc(n * sizeof(int));
 
    //Printing message for user
    printf("Memory is allocated for ptr1 and ptr2 using malloc().\n");

    //Giving values to pointers
    for(i=0; i<n; i++)
    {
        *(ptr1+i) = i;
        *(ptr2+i) = i+1;
    }

    //Printing values of pointers
    printf("Values of ptr1 are: ");
    for(i=0; i<n; i++)
        printf("%d ", *(ptr1+i));
 
    printf("\nValues of ptr2 are: ");
    for(i=0; i<n; i++)
        printf("%d ", *(ptr2+i));
  
    //Dynamic memory allocation using calloc()
    ptr3 = (int*)calloc(n, sizeof(int));
  
    //Printing message for user
    printf("\n\nMemory is allocated for ptr3 using calloc().\n");

    //Giving values to pointer
    for(i=0; i<n; i++)
        *(ptr3+i) = i+10;

    //Printing values of pointer
    printf("Values of ptr3 are: ");
    for(i=0; i<n; i++)
        printf("%d ", *(ptr3+i));

    //Reallocation of memory
    ptr1 = realloc(ptr1, 10 * sizeof(int));
    ptr2 = realloc(ptr2, 10 * sizeof(int));
    ptr3 = realloc(ptr3, 10 * sizeof(int));
  
    //Printing message for user
    printf("\n\nMemory for ptr1, ptr2, ptr3 is reallocated to hold 10 integers.\n");

    //Printing values of pointers
    printf("New Values of ptr1 are: ");
    for(i=0; i<10; i++)
        printf("%d ", *(ptr1+i));
 
    printf("\nNew Values of ptr2 are: ");
    for(i=0; i<10; i++)
        printf("%d ", *(ptr2+i));
  
    printf("\nNew Values of ptr3 are: ");
    for(i=0; i<10; i++)
        printf("%d ", *(ptr3+i));

    //Deallocating memory using free()
    free(ptr1);
    free(ptr2);
    free(ptr3);
  
    //Printing message for user
    printf("\n\nMemory for ptr1, ptr2, ptr3 is freed using free().\n\n");
  
    //End of program
    return 0;
}