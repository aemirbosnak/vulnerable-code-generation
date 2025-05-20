//FormAI DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Welcome to the Memory Management Program!\n\n");
    printf("This program will demonstrate dynamic memory allocation in C using the malloc() and free() functions.\n\n");
    printf("First, let's allocate memory for an integer variable using malloc() function:\n\n");
    
    // Allocating memory for an integer variable using malloc() function
    int *ptr1 = (int*)malloc(sizeof(int));

    // Checking if memory allocation was successful or not 
    if(ptr1 == NULL){
        printf("Failed to allocate memory for integer variable.");
        exit(0);
    }

    printf("Memory for integer variable allocated successfully!\n");
    printf("Now, let's assign a value to the integer variable:\n\n");

    // Assigning value to the integer variable
    *ptr1 = 20;
    printf("The value stored in the integer variable is: %d\n\n", *ptr1);

    printf("Wow! We allocated memory for an integer variable.\n");

    printf("Now, let's allocate memory for an array of 5 integers using malloc() function:\n\n");

    // Allocating memory for an array of 5 integers using malloc() function
    int *ptr2 = (int*)malloc(5*sizeof(int));

    // Checking if memory allocation was successful or not
    if(ptr2 == NULL){
        printf("Failed to allocate memory for array of integers.");
        exit(0);
    }

    printf("Memory for array of 5 integers allocated successfully!\n");
    printf("Now, let's assign some values to the array:\n\n");

    // Assigning values to the array
    for(int i=0; i<5; i++){
        ptr2[i] = i+1;
        printf("Element %d: %d\n", i+1, ptr2[i]);
    }

    printf("\nAmazing! We allocated memory for an array of 5 integers.\n");

    printf("\nNow, let's free the allocated memory using the free() function:\n\n");

    // Freeing the allocated memory for integer variable
    free(ptr1);

    printf("Memory for integer variable has been freed successfully!\n");

    // Freeing the allocated memory for array of integers
    free(ptr2);

    printf("Memory for array of 5 integers has been freed successfully!\n");

    printf("\nThank you for using this Memory Management Program!\n");

    return 0;
}