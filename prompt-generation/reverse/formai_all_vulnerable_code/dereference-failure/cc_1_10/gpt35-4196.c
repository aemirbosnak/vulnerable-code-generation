//FormAI DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2, *ptr3, *ptr4;
    ptr1 = (int*)malloc(sizeof(int)); // allocate memory block of size of integer type
    if (ptr1 == NULL) { // check if memory allocation was successful
        printf("Memory allocation failed for ptr1\n");
        exit(1); // exit the program with error code
    }
    else {
        *ptr1 = 10; // assign value to allocated memory block
        printf("Value of ptr1: %d\n", *ptr1);
    }

    ptr2 = (int*)calloc(3, sizeof(int)); // allocate memory block of size of integer type and initialize all values to 0
    if (ptr2 == NULL) {
        printf("Memory allocation failed for ptr2\n");
        exit(1);
    }
    else {
        printf("Values of ptr2: %d %d %d\n", ptr2[0], ptr2[1], ptr2[2]);
    }

    ptr3 = (int*)realloc(ptr2, 5 * sizeof(int)); // reallocate memory block of ptr2 to a larger size of 5 integers
    if (ptr3 == NULL) {
        printf("Memory reallocation failed for ptr2\n");
        exit(1);
    }
    else {
        ptr3[3] = 20; // assign value to newly allocated memory block
        ptr3[4] = 30;
        printf("Values of ptr3: %d %d %d %d %d\n", ptr3[0], ptr3[1], ptr3[2], ptr3[3], ptr3[4]);
    }

    free(ptr1); // deallocate memory block of ptr1 to prevent memory leaks
    free(ptr3); // deallocate memory block of ptr3 (originally allocated as ptr2) to prevent memory leaks

    ptr4 = (int*)malloc(sizeof(int)); // allocate memory block of size of integer type
    if (ptr4 == NULL) {
        printf("Memory allocation failed for ptr4\n");
        exit(1);
    }
    else {
        *ptr4 = 40; // assign value to allocated memory block
        printf("Value of ptr4: %d\n", *ptr4);
    }

    return 0;
}