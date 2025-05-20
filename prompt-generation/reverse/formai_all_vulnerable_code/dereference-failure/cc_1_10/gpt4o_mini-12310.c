//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some error codes
#define SUCCESS 0
#define FILE_ERROR 1
#define MEMORY_ERROR 2
#define INPUT_ERROR 3

// Function to log errors to the console
void log_error(const char *message, int error_code) {
    switch (error_code) {
        case FILE_ERROR:
            fprintf(stderr, "[ERROR] File Error: %s\n", message);
            break;
        case MEMORY_ERROR:
            fprintf(stderr, "[ERROR] Memory Error: %s\n", message);
            break;
        case INPUT_ERROR:
            fprintf(stderr, "[ERROR] Input Error: %s\n", message);
            break;
        default:
            fprintf(stderr, "[ERROR] Unknown Error: %s\n", message);
            break;
    }
}

// Function to read integers from a file
int read_integers_from_file(const char *filename, int **array, size_t *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        log_error("Unable to open file", FILE_ERROR);
        return FILE_ERROR;
    }

    size_t capacity = 10; // Starting capacity
    *array = malloc(capacity * sizeof(int));
    if (*array == NULL) {
        fclose(file);
        log_error("Memory allocation failed", MEMORY_ERROR);
        return MEMORY_ERROR;
    }

    *size = 0;
    while (fscanf(file, "%d", &(*array)[*size]) == 1) {
        (*size)++;
        if (*size >= capacity) {
            capacity *= 2;
            int *temp = realloc(*array, capacity * sizeof(int));
            if (temp == NULL) {
                free(*array);
                fclose(file);
                log_error("Memory reallocation failed", MEMORY_ERROR);
                return MEMORY_ERROR;
            }
            *array = temp;
        }
    }

    fclose(file);
    return SUCCESS;
}

// Function to print an array of integers
void print_integers(int *array, size_t size) {
    printf("Integers read from the file:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function that integrates all components
int main(int argc, char *argv[]) {
    if (argc != 2) {
        log_error("Usage: ./error_handling_example <filename>", INPUT_ERROR);
        return INPUT_ERROR;
    }

    int *numbers = NULL;
    size_t size = 0;
    int result = read_integers_from_file(argv[1], &numbers, &size);
    if (result != SUCCESS) {
        return result; // Propagating error code
    }

    print_integers(numbers, size);

    // Clean up
    free(numbers);
    return SUCCESS;
}