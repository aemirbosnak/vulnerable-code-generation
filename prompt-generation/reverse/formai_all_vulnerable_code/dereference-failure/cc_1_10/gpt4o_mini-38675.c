//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to simulate a file operation
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s'. %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Read content from the file
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Check if there was an error ending the reading
    if (ferror(file)) {
        fprintf(stderr, "Error: Reading from file '%s'. %s\n", filename, strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

// Function to allocate memory and handle potential errors
void *allocateMemory(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return ptr;
}

// Function to demonstrate usage of dynamically allocated memory
void processData(int size) {
    int *data = (int *)allocateMemory(size * sizeof(int));
    
    // Initialize data
    for (int i = 0; i < size; i++) {
        data[i] = i * 2;
    }

    // Output the data
    printf("Processed data:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    free(data);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];

    // Read the file
    readFile(filename);

    // Process dynamic memory
    int size = 10;
    processData(size);

    // Success message
    printf("Program executed successfully.\n");
    return EXIT_SUCCESS;
}