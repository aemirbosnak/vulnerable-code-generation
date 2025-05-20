//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Custom error handling function
void handle_error(const char *error_message) {
    // Print the error message
    fprintf(stderr, "%s\n", error_message);

    // Exit the program with an error code
    exit(EXIT_FAILURE);
}

// Custom function to check for errors in a file pointer
void check_file_error(FILE *fp, const char *filename) {
    // Check if the file pointer is NULL
    if (fp == NULL) {
        // Handle the error
        handle_error(strerror(errno));
    }
}

// Custom function to check for errors in a memory allocation
void check_memory_error(void *ptr) {
    // Check if the pointer is NULL
    if (ptr == NULL) {
        // Handle the error
        handle_error(strerror(errno));
    }
}

// Custom function to check for errors in a string comparison
void check_string_error(int result) {
    // Check if the result is less than 0
    if (result < 0) {
        // Handle the error
        handle_error(strerror(errno));
    }
}

int main() {
    // Declare a file pointer
    FILE *fp;

    // Open a file for reading
    fp = fopen("test.txt", "r");

    // Check for errors in the file pointer
    check_file_error(fp, "test.txt");

    // Declare a buffer for reading the file
    char buffer[1024];

    // Read the file into the buffer
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), fp);

    // Check for errors in the file read
    if (bytes_read == 0) {
        // Handle the error
        handle_error("Error reading file");
    }

    // Declare a string for storing the file contents
    char *file_contents;

    // Allocate memory for the file contents
    file_contents = malloc(bytes_read + 1);

    // Check for errors in the memory allocation
    check_memory_error(file_contents);

    // Copy the file contents into the string
    memcpy(file_contents, buffer, bytes_read);

    // Add a null terminator to the string
    file_contents[bytes_read] = '\0';

    // Compare the file contents to a known string
    int result = strcmp(file_contents, "Hello world!");

    // Check for errors in the string comparison
    check_string_error(result);

    // Print the file contents if they match
    if (result == 0) {
        printf("%s\n", file_contents);
    } else {
        // Handle the error
        handle_error("File contents do not match");
    }

    // Close the file
    fclose(fp);

    // Free the memory allocated for the file contents
    free(file_contents);

    return EXIT_SUCCESS;
}