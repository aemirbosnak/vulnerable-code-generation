//Falcon-180B DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_STRING_LENGTH 50

typedef struct {
    int data;
    int size;
} MyStruct;

int main() {
    int i, j;
    int *ptr;
    int **matrix;
    MyStruct *mystruct;
    char *str;

    // Allocate memory for an integer pointer
    ptr = (int *) malloc(sizeof(int));

    // Allocate memory for an integer matrix
    matrix = (int **) malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++) {
        matrix[i] = (int *) malloc(5 * sizeof(int));
    }

    // Allocate memory for a structure
    mystruct = (MyStruct *) malloc(sizeof(MyStruct));

    // Allocate memory for a string
    str = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));

    // Initialize the integer pointer
    ptr = (int *) 0x12345678;

    // Initialize the integer matrix
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            matrix[i][j] = i * 5 + j;
        }
    }

    // Initialize the structure
    mystruct->data = 42;
    mystruct->size = 24;

    // Initialize the string
    strcpy(str, "Hello, world!");

    // Print the values
    printf("Integer pointer: %p\n", ptr);
    printf("Integer matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Structure:\n");
    printf("Data: %d\n", mystruct->data);
    printf("Size: %d\n", mystruct->size);
    printf("String: %s\n", str);

    // Free the memory
    free(ptr);
    for (i = 0; i < 3; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(mystruct);
    free(str);

    return 0;
}