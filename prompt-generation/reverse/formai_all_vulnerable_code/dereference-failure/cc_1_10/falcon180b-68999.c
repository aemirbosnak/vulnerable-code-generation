//Falcon-180B DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *ptr, i;
    char *str_ptr, *str;

    // Allocate memory dynamically for an integer variable
    ptr = (int *) malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    // Allocate memory dynamically for a string variable
    str_ptr = (char *) malloc(100 * sizeof(char));
    if (str_ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    // Initialize the integer variable
    for (i = 0; i < 10; i++) {
        *ptr = i;
        printf("Integer value: %d\n", *ptr);
    }

    // Initialize the string variable
    str = str_ptr;
    strcpy(str, "Enthusiastic Programming in C");
    printf("String value: %s\n", str);

    // Reallocate memory for the string variable
    str_ptr = (char *) realloc(str_ptr, 200 * sizeof(char));
    if (str_ptr == NULL) {
        printf("Memory reallocation failed\n");
        exit(0);
    }

    // Modify the string variable
    str = str_ptr;
    strcat(str, " - Let's code with passion!");
    printf("Modified string value: %s\n", str);

    // Free the allocated memory
    free(ptr);
    free(str_ptr);

    return 0;
}