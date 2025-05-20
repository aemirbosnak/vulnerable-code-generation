//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUFFER 256

void handleError(const char *message) {
    fprintf(stderr, "Error: %s. Reason: %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handleError("Failed to open file");
    }

    char buffer[MAX_BUFFER];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    if (ferror(file)) {
        handleError("Error reading from file");
    }

    if (fclose(file) != 0) {
        handleError("Failed to close file");
    }
}

void allocateMemory(int size) {
    int *array = malloc(size * sizeof(int));
    if (!array) {
        handleError("Memory allocation failed");
    }

    for (int i = 0; i < size; ++i) {
        array[i] = i * i; // Store squares of indices
    }

    printf("Squares of indices up to %d:\n", size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <size>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    int size = atoi(argv[2]);

    if (size <= 0) {
        fprintf(stderr, "Size must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    printf("Attempting to read the file: %s\n", filename);
    readFile(filename);

    printf("Attempting to allocate memory for %d integers.\n", size);
    allocateMemory(size);

    return EXIT_SUCCESS;
}