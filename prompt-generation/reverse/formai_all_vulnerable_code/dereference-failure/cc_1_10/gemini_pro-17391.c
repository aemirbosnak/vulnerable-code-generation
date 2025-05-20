//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

// Custom error codes
enum errors {
    ERR_NO_ERROR = 0,
    ERR_INVALID_INPUT = 1,
    ERR_MEMORY_ALLOCATION_FAILED = 2,
    ERR_FILE_OPEN_FAILED = 3,
    ERR_FILE_WRITE_FAILED = 4
};

// Custom error handling function
void handle_error(int error_code, const char *error_message) {
    // Print the error message
    fprintf(stderr, "Error: %s\n", error_message);

    // Exit the program with the appropriate error code
    exit(error_code);
}

int main() {
    // Get the user's name
    char name[MAX_NAME_LEN];
    printf("Enter your name: ");
    if (fgets(name, MAX_NAME_LEN, stdin) == NULL) {
        handle_error(ERR_INVALID_INPUT, "Invalid input");
    }

    // Remove the newline character from the name
    name[strcspn(name, "\n")] = '\0';

    // Validate the user's name
    if (strlen(name) == 0) {
        handle_error(ERR_INVALID_INPUT, "Name cannot be empty");
    }

    // Open a file to write the user's name
    FILE *fp = fopen("name.txt", "w");
    if (fp == NULL) {
        handle_error(ERR_FILE_OPEN_FAILED, "Could not open file");
    }

    // Write the user's name to the file
    if (fwrite(name, strlen(name), 1, fp) != 1) {
        handle_error(ERR_FILE_WRITE_FAILED, "Could not write to file");
    }

    // Close the file
    if (fclose(fp) != 0) {
        handle_error(ERR_FILE_OPEN_FAILED, "Could not close file");
    }

    // Print a success message
    printf("Successfully wrote %s to file\n", name);

    return ERR_NO_ERROR;
}