//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the error codes
#define ERR_INVALID_ARGUMENT -1
#define ERR_FILE_NOT_FOUND -2
#define ERR_MEMORY_ALLOCATION_FAILED -3
#define ERR_IO_ERROR -4

// Define the error messages
const char *error_messages[] = {
    "Invalid argument",
    "File not found",
    "Memory allocation failed",
    "IO error"
};

// Function to print the error message
void print_error(int error_code) {
    if (error_code < 0 && error_code >= -4) {
        printf("Error: %s\n", error_messages[-error_code]);
    } else {
        printf("Unknown error\n");
    }
}

// Function to open a file
FILE *open_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }
    return fp;
}

// Function to read a file
char *read_file(const char *filename) {
    FILE *fp = open_file(filename);
    if (fp == NULL) {
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        fclose(fp);
        return NULL;
    }
    fread(buffer, file_size, 1, fp);
    fclose(fp);
    buffer[file_size] = '\0';
    return buffer;
}

// Function to write a file
int write_file(const char *filename, const char *data) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return ERR_FILE_NOT_FOUND;
    }
    fwrite(data, strlen(data), 1, fp);
    fclose(fp);
    return 0;
}

// Function to main
int main() {
    char *filename = "test.txt";
    char *data = "Hello world!";

    // Open the file
    FILE *fp = open_file(filename);
    if (fp == NULL) {
        print_error(ERR_FILE_NOT_FOUND);
        return ERR_FILE_NOT_FOUND;
    }

    // Read the file
    char *buffer = read_file(filename);
    if (buffer == NULL) {
        print_error(ERR_MEMORY_ALLOCATION_FAILED);
        return ERR_MEMORY_ALLOCATION_FAILED;
    }

    // Write the file
    int result = write_file(filename, data);
    if (result != 0) {
        print_error(result);
        return result;
    }

    // Free the buffer
    free(buffer);

    return 0;
}