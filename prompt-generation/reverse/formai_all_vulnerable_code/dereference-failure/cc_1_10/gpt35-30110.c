//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include<stdio.h>
#include<stdlib.h>

#define ARR_SIZE 100 // size of integer array

int main()
{
    // allocate memory for integer and character arrays
    int* intArr = (int*)malloc(sizeof(int) * ARR_SIZE);
    char* charArr = (char*)calloc(ARR_SIZE, sizeof(char));

    // check if memory allocation successful
    if (intArr == NULL || charArr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // assign values to integer array
    for (int i = 0; i < ARR_SIZE; i++) {
        intArr[i] = i + 1;
    }

    // print integer array
    printf("Printing integer array:\n");
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n\n");

    // assign values to character array
    for (int i = 0; i < ARR_SIZE; i++) {
        charArr[i] = 'a' + i;
    }

    // print character array
    printf("Printing character array:\n");
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%c ", charArr[i]);
    }
    printf("\n\n");

    // reallocate memory for integer array
    intArr = (int*)realloc(intArr, sizeof(int) * (ARR_SIZE + 50));

    // check if memory reallocation successful
    if (intArr == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    // assign new values to integer array
    for (int i = ARR_SIZE; i < ARR_SIZE + 50; i++) {
        intArr[i] = i + 1;
    }

    // print updated integer array
    printf("Printing updated integer array:\n");
    for (int i = 0; i < ARR_SIZE + 50; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n\n");

    // free allocated memory
    free(intArr);
    free(charArr);

    return 0;
}