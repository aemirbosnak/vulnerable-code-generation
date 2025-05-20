//FormAI DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Allocate memory for an integer array of 5 elements
    int *arr = (int*) malloc(5 * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    // Fill the array with values
    for (int i=0; i<5; i++) {
        arr[i] = i+1;
    }

    // Print the contents of the array
    printf("Array contents: ");
    for (int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }

    // Deallocate the memory
    free(arr);

    // Allocate memory for a character array of 10 elements
    char *str = (char*) malloc(10 * sizeof(char));

    // Check if memory allocation was successful
    if (str == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    // Fill the array with characters
    str[0] = 'H';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] = ' ';
    str[6] = 'W';
    str[7] = 'o';
    str[8] = 'r';
    str[9] = 'l';
    str[10] = 'd';

    // Print the contents of the string
    printf("\nString contents: %s", str);

    // Deallocate the memory
    free(str);

    return 0;
}