//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Define a structure to represent custom errors
typedef struct {
    int code;
    char message[256];
} CustomError;

// Function to initialize a CustomError object
CustomError initError(int code, const char *message) {
    CustomError error;
    error.code = code;
    strncpy(error.message, message, sizeof(error.message) - 1);
    error.message[sizeof(error.message) - 1] = '\0'; // Ensure null-termination
    return error;
}

// Function that simulates a file operation and errors
CustomError simulateFileRead(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return initError(errno, "Failed to open file for reading");
    }

    // Simulate reading data from the file
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        fclose(file);
        return initError(errno, "Failed to read from file");
    }

    printf("File content: %s", buffer);
    fclose(file);
    return initError(0, "Success");
}

// Function to handle and display error messages
void handleError(CustomError error) {
    if (error.code != 0) {
        fprintf(stderr, "Error (%d): %s\n", error.code, error.message);
        exit(error.code); // Exit with the error code
    }
}

// Function that simulates memory allocation
CustomError simulateMemoryAllocation(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        return initError(errno, "Memory allocation failed");
    }

    // Simulate doing something with allocated memory
    memset(ptr, 0, size); // Busy work for demonstration
    free(ptr); // Remember to free memory
    return initError(0, "Memory allocation successful and freed");
}

// Main function to drive the example
int main() {
    // Part 1: Simulate a file read operation
    CustomError fileError = simulateFileRead("example.txt");
    handleError(fileError);

    // Part 2: Simulate a memory allocation operation
    CustomError memError = simulateMemoryAllocation(1024);
    handleError(memError);

    // Part 3: Notify completion
    printf("All operations completed successfully.\n");
    return 0;
}