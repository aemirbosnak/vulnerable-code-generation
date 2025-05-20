//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error codes
enum errors {
    ERR_INVALID_INPUT = 1,
    ERR_FILE_NOT_FOUND = 2,
    ERR_MEMORY_ALLOCATION_FAILED = 3,
    ERR_UNEXPECTED = 4
};

// Custom error handling function
void handle_error(int error_code) {
    switch (error_code) {
        case ERR_INVALID_INPUT:
            printf("Error: Invalid input.\n");
            break;
        case ERR_FILE_NOT_FOUND:
            printf("Error: File not found.\n");
            break;
        case ERR_MEMORY_ALLOCATION_FAILED:
            printf("Error: Memory allocation failed.\n");
            break;
        case ERR_UNEXPECTED:
            printf("Error: Unexpected error occurred.\n");
            break;
        default:
            printf("Error: Unknown error code.\n");
            break;
    }
}

// Function to open a file and read its contents
int read_file(const char *filename, char **buffer) {
    FILE *fp;
    long file_size;
    
    // Open the file in read mode
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return ERR_FILE_NOT_FOUND;
    }
    
    // Get the file size
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    // Allocate memory for the buffer
    *buffer = malloc(file_size + 1);
    if (*buffer == NULL) {
        fclose(fp);
        return ERR_MEMORY_ALLOCATION_FAILED;
    }
    
    // Read the file contents into the buffer
    if (fread(*buffer, file_size, 1, fp) != 1) {
        free(*buffer);
        fclose(fp);
        return ERR_UNEXPECTED;
    }
    
    // Add a null terminator to the end of the buffer
    (*buffer)[file_size] = '\0';
    
    // Close the file
    fclose(fp);
    
    return 0;
}

// Function to parse a string and extract integers
int parse_integers(const char *input, int **numbers, int *n) {
    char *endptr;
    int num, count = 0;
    char *str;
    
    // Allocate memory for the numbers array
    *numbers = malloc(sizeof(int) * strlen(input));
    if (*numbers == NULL) {
        return ERR_MEMORY_ALLOCATION_FAILED;
    }
    
    // Parse each integer in the string
    str = strdup(input);
    while (*str != '\0') {
        num = strtol(str, &endptr, 10);
        if (endptr == str) {
            free(str);
            free(*numbers);
            return ERR_INVALID_INPUT;
        }
        (*numbers)[count++] = num;
        str = endptr;
    }
    
    free(str);
    
    *n = count;
    
    return 0;
}

// Main function
int main() {
    char *buffer;
    int *numbers;
    int n, error_code;
    
    // Read the input file
    error_code = read_file("input.txt", &buffer);
    if (error_code != 0) {
        handle_error(error_code);
        return error_code;
    }
    
    // Parse the integers from the input file
    error_code = parse_integers(buffer, &numbers, &n);
    if (error_code != 0) {
        free(buffer);
        handle_error(error_code);
        return error_code;
    }
    
    // Process the integers in the array
    for (int i = 0; i < n; i++) {
        printf("Number: %d\n", numbers[i]);
    }
    
    // Free the allocated memory
    free(buffer);
    free(numbers);
    
    return 0;
}