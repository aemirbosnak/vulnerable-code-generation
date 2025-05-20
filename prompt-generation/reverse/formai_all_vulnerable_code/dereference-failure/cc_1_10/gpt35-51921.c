//FormAI DATASET v1.0 Category: Memory management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Surprise, surprise! Welcome to the Memory Management program!\n");
    printf("This program is designed to demonstrate how memory is allocated and deallocated in C programming.\n");

    // Allocating an array of integers using malloc
    int* arr = malloc(sizeof(int) * 10);
    if(arr == NULL) {
        printf("Oops, malloc failed to allocate memory!\n");
        return 1;
    }

    printf("An array of integers has been allocated!\n");

    // Assigning values to the array
    for(int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }

    printf("Values have been assigned to the array!\n");

    // Printing the array
    printf("Printing the array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deallocating the array
    free(arr);
    arr = NULL;

    printf("The array has been deallocated!\n");

    // Allocating a string using calloc
    char* str = calloc(20, sizeof(char));
    if(str == NULL) {
        printf("Uh-oh, calloc failed to allocate memory!\n");
        return 1;
    }

    printf("A string has been allocated!\n");

    // Assigning a value to the string
    str = "Surprise!";

    printf("A value has been assigned to the string!\n");

    // Printing the string
    printf("Printing the string: %s\n", str);

    // Deallocating the string
    free(str);
    str = NULL;

    printf("The string has been deallocated!\n");

    printf("That's it for this program! Hope you enjoyed the surprise!\n");

    return 0;
}