//FormAI DATASET v1.0 Category: Memory management ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

int main() {
    void *ptr_1, *ptr_2, *ptr_3;
    int size_1, size_2, size_3;

    // Allocate some memory
    size_1 = 10;
    ptr_1 = malloc(size_1);
    if (ptr_1 == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    // Allocate more memory
    size_2 = 100;
    ptr_2 = malloc(size_2);
    if (ptr_2 == NULL) {
        printf("Error allocating memory!\n");
        free(ptr_1);
        exit(1);
    }

    // Fill the memory with garbage
    for (int i = 0; i < size_2; i++) {
        *(char*)(ptr_2 + i) = 0xEF;
    }

    // Try to allocate too much memory
    size_3 = 1000000000;
    ptr_3 = malloc(size_3);
    if (ptr_3 != NULL) {
        printf("Error: allocation succeeded when it should have failed!\n");
        free(ptr_1);
        free(ptr_2);
        free(ptr_3); // Just in case
        exit(1);
    }

    // Free the memory
    free(ptr_1);
    free(ptr_2);
    
    // Try to free the same memory again
    free(ptr_1);
    free(ptr_2);

    return 0;
}