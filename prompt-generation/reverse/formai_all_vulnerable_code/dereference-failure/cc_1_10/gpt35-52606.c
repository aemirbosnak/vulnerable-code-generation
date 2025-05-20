//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define SIZE 200000000 //200MB

int main() {
    char *ptr1, *ptr2, *ptr3;

    //Allocate 100MB of memory to ptr1
    ptr1 = (char*) malloc(SIZE/2);
    if (ptr1 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //Allocate another 100MB of memory to ptr2
    ptr2 = (char*) malloc(SIZE/2);
    if (ptr2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //Copy contents of ptr1 to ptr2
    for (int i = 0; i < SIZE/2; i++) {
        ptr2[i] = ptr1[i];
    }

    //Free ptr1 to make it available for other processes
    free(ptr1);

    //Allocate 50MB of memory to ptr3
    ptr3 = (char*) malloc(SIZE/4);
    if (ptr3 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //Copy contents of ptr2 to ptr3
    for (int i = 0; i < SIZE/4; i++) {
        ptr3[i] = ptr2[i];
    }

    //Free ptr2 to make it available for other processes
    free(ptr2);

    //Allocate remaining 50MB of memory to ptr1
    ptr1 = (char*) malloc(SIZE/4);
    if (ptr1 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //Copy contents of ptr3 to ptr1
    for (int i = 0; i < SIZE/4; i++) {
        ptr1[i] = ptr3[i];
    }

    //Free ptr3 to make it available for other processes
    free(ptr3);

    //Print messages to show successful memory management
    printf("Memory allocated and copied successfully!\n");
    printf("Size of allocated memory: %d bytes.\n", SIZE/2 + SIZE/4);

    return 0;
}