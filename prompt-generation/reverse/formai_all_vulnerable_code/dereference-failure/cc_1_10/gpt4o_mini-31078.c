//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

// Function prototypes
void handleError(const char *msg);
void readNumbersFromFile(const char *filename, int **numbers, int *count);
void printNumbers(int *numbers, int count);

int main() {
    int *numbers = NULL; // Pointer to hold the dynamically allocated array
    int count = 0;      // Variable to hold the number of integers read

    // Read numbers from a file called "numbers.txt"
    readNumbersFromFile("numbers.txt", &numbers, &count);
    
    // Print the numbers read from the file
    printNumbers(numbers, count);

    // Free allocated memory
    free(numbers);
    return 0;
}

// Function to handle errors and print messages
void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to read integers from a file
void readNumbersFromFile(const char *filename, int **numbers, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handleError("Error opening file");
    }

    // Allocate memory for storing integers
    *numbers = (int *)malloc(MAX_NUMBERS * sizeof(int));
    if (*numbers == NULL) {
        handleError("Memory allocation failed");
    }

    // Read integers from the file
    while (fscanf(file, "%d", &((*numbers)[*count])) != EOF) {
        (*count)++;
        if (*count >= MAX_NUMBERS) {
            // In case we read more numbers than we allocated space for
            printf("Warning: Maximum number of integers exceeded. Only the first %d will be processed.\n", MAX_NUMBERS);
            break;
        }
    }
    
    if (ferror(file)) {
        handleError("Error reading file");
    }

    fclose(file);
}

// Function to print the numbers
void printNumbers(int *numbers, int count) {
    if (count == 0) {
        printf("No numbers available to print.\n");
        return;
    }

    printf("Numbers read from file:\n");
    for (int i = 0; i < count; i++) {
        printf("%d\n", numbers[i]);
    }
}