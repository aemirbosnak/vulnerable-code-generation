//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Custom error handling function
void my_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(void) {
    char buffer[MAX_LENGTH];
    int number;
    FILE *file;

    printf("Welcome to the serene error handling program.\n");

    // Allocate memory for a string
    char *string = malloc(MAX_LENGTH * sizeof(char));
    if (string == NULL) {
        my_error("Memory allocation failed.\n");
    }

    // Read a line from the user
    printf("Please enter a line: ");
    fgets(buffer, MAX_LENGTH, stdin);
    size_t length = strlen(buffer);

    // Check if the line is too long
    if (length >= MAX_LENGTH) {
        printf("Line too long. Maximum length is %d.\n", MAX_LENGTH);
        free(string);
        exit(EXIT_FAILURE);
    }

    // Copy the line to the allocated memory
    strcpy(string, buffer);

    // Open a file for writing
    file = fopen("output.txt", "w");
    if (file == NULL) {
        my_error("Failed to open output file.\n");
    }

    // Read an integer from the user
    printf("Please enter a number: ");
    if (scanf("%d", &number) != 1) {
        my_error("Invalid input.\n");
    }

    // Write the string and number to the file
    fprintf(file, "%s %d\n", string, number);

    // Free allocated memory and close the file
    free(string);
    fclose(file);

    printf("File written successfully.\n");

    return EXIT_SUCCESS;
}