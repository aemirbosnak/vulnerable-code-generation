//FormAI DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef enum error_codes {
    ERROR_NONE,
    ERROR_IO,
    ERROR_MEM,
    ERROR_RANGE
} error_codes;

void handle_error(error_codes error_code) {
    switch (error_code) {
        case ERROR_IO:
            fprintf(stderr, "Error: Input/Output error occurred.\n");
            exit(EXIT_FAILURE);
        case ERROR_MEM:
            fprintf(stderr, "Error: Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        case ERROR_RANGE:
            fprintf(stderr, "Error: Index out of range.\n");
            exit(EXIT_FAILURE);
        default:
            break;
    }
}

int main() {
    int* arr = NULL;
    int arr_size = 0;

    printf("Enter the size of the array: ");
    if (scanf("%d", &arr_size) != 1) {
        handle_error(ERROR_IO);
    }

    arr = malloc(arr_size * sizeof(int));
    if (!arr) {
        handle_error(ERROR_MEM);
    }

    for (int i = 0; i < arr_size; ++i) {
        printf("Enter element %d of the array: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            handle_error(ERROR_IO);
        }
    }

    int index = 0;
    printf("Enter an index to access the array: ");
    if (scanf("%d", &index) != 1) {
        handle_error(ERROR_IO);
    }

    if (index < 0 || index >= arr_size) {
        handle_error(ERROR_RANGE);
    }

    printf("The element at index %d is %d.\n", index, arr[index]);

    free(arr);
    arr = NULL;

    return 0;
}