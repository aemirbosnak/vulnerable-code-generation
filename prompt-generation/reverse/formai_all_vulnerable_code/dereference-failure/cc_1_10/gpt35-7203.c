//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Memory Management Funhouse!\n\n");

    int* ptr1;
    int* ptr2;
    char* ptr3;
    float* ptr4;
    double* ptr5;

    printf("Time to allocate memory!\n");
    ptr1 = (int*) malloc(5 * sizeof(int));
    ptr2 = (int*) calloc(5, sizeof(int));
    ptr3 = (char*) malloc(50 * sizeof(char));
    ptr4 = (float*) malloc(10 * sizeof(float));
    ptr5 = (double*) malloc(2 * sizeof(double));

    printf("Memory allocation complete! Now let's party!\n");

    // We have some silly fun with our memory
    for(int i = 0; i < 5; i++) {
        ptr1[i] = i * 2 + 1;
        ptr2[i] = i * 10;
    }

    for(int i = 0; i < 50; i++) {
        ptr3[i] = 'a' + i%26;
    }

    for(int i = 0; i < 10; i++) {
        ptr4[i] = (float)(i * 0.5);
    }

    for(int i = 0; i < 2; i++) {
        ptr5[i] = i * 0.01;
    }

    printf("Our memory is full of fun! Now let's free it.\n");

    // We free the memory and say goodbye
    free(ptr1);
    free(ptr2);
    free(ptr3);
    free(ptr4);
    free(ptr5);

    printf("Memory is free. Goodbye, Memory Management Funhouse!\n");

    return 0;
}