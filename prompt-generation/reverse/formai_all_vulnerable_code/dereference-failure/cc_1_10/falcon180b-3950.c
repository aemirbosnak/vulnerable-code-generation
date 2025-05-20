//Falcon-180B DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom error type
typedef enum {
    OK = 0,
    ERROR_MEMORY_ALLOCATION_FAILED,
    ERROR_FILE_NOT_FOUND,
    ERROR_INVALID_ARGUMENT,
    ERROR_INVALID_OPERATION,
    ERROR_UNKNOWN
} ErrorCode;

// Function to allocate memory and handle errors
void* safeMalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to read a file and handle errors
char* readFile(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    char* buffer = safeMalloc(fileSize + 1);
    fread(buffer, fileSize, 1, fp);
    fclose(fp);

    buffer[fileSize] = '\0';
    return buffer;
}

// Function to write to a file and handle errors
int writeFile(const char* filename, const char* data) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(EXIT_FAILURE);
    }

    int bytesWritten = fwrite(data, strlen(data), 1, fp);
    if (bytesWritten!= 1) {
        printf("Error: Failed to write to file.\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return 0;
}

// Function to perform some operation and handle errors
int doSomething(int arg1, int arg2) {
    if (arg1 <= 0 || arg2 <= 0) {
        printf("Error: Invalid argument.\n");
        return ERROR_INVALID_ARGUMENT;
    }

    // Perform some operation here

    return OK;
}

// Main function
int main() {
    char* input = readFile("input.txt");
    if (input == NULL) {
        return 1;
    }

    int result = doSomething(atoi(input), 42);
    if (result!= OK) {
        return result;
    }

    writeFile("output.txt", "Operation successful!");

    return 0;
}