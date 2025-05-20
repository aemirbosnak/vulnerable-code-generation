//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function prototypes
void read_file(const char *filename);
void perform_calculation(int a, int b);
void allocate_memory(size_t size);

int main() {
    char filename[100];
    int a, b;

    // Get filename from user
    printf("Enter the filename to read: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error: Unable to read filename. %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    // Remove newline character from filename
    filename[strcspn(filename, "\n")] = 0;

    // Read the file
    read_file(filename);

    // Get two integers for calculation from user
    printf("Enter two integers for division (a / b): ");
    if (scanf("%d %d", &a, &b) != 2) {
        fprintf(stderr, "Error: Invalid input. Expected two integers. %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Perform calculation
    perform_calculation(a, b);

    // Allocate memory
    size_t size;
    printf("Enter the number of elements to allocate memory for: ");
    if (scanf("%zu", &size) != 1) {
        fprintf(stderr, "Error: Invalid input. Expected a positive integer. %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    allocate_memory(size);

    return EXIT_SUCCESS;
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'. %s\n", filename, strerror(errno));
        return;
    }

    char line[256];
    printf("Contents of the file '%s':\n", filename);
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error: An error occurred while reading the file. %s\n", strerror(errno));
    }

    fclose(file);
}

void perform_calculation(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero is undefined.\n");
    } else {
        printf("Result of %d / %d = %.2f\n", a, b, (double) a / b);
    }
}

void allocate_memory(size_t size) {
    if (size == 0) {
        fprintf(stderr, "Error: Size must be greater than zero.\n");
        return;
    }

    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed. %s\n", strerror(errno));
        return;
    }

    // Initialize memory
    for (size_t i = 0; i < size; i++) {
        array[i] = i;
    }

    printf("Memory allocated successfully for %zu elements.\n", size);
    printf("Array contents:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free allocated memory
    free(array);
    printf("Memory freed successfully.\n");
}