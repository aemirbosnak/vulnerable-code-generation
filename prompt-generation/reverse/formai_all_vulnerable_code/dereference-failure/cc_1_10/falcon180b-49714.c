//Falcon-180B DATASET v1.0 Category: Error handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void readFile(FILE* file, char** buffer, int* size);
void processData(char* buffer, int size);
void printResults(int numResults, int* results);

int main() {
    FILE* file;
    char* buffer;
    int size;

    // Open the file for reading
    file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Error: Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    // Read the file into memory
    readFile(file, &buffer, &size);

    // Process the data
    processData(buffer, size);

    // Print the results
    int* results = malloc(sizeof(int) * 10);
    int numResults = 0;

    for (int i = 0; i < 10; i++) {
        if (results[i]!= 0) {
            numResults++;
        }
    }

    printResults(numResults, results);

    // Free memory and close the file
    free(buffer);
    fclose(file);

    return 0;
}

void readFile(FILE* file, char** buffer, int* size) {
    fseek(file, 0, SEEK_END);
    *size = ftell(file);

    rewind(file);

    *buffer = malloc(*size * sizeof(char));

    fread(*buffer, sizeof(char), *size, file);
}

void processData(char* buffer, int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (buffer[i] == 'a') {
            count++;
        }
    }

    printf("Number of occurrences of 'a': %d\n", count);
}

void printResults(int numResults, int* results) {
    if (numResults == 0) {
        printf("No results to display.\n");
    } else {
        printf("Results:\n");

        for (int i = 0; i < numResults; i++) {
            printf("%d\n", results[i]);
        }
    }
}