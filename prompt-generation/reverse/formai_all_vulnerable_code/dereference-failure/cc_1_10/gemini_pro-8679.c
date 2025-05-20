//GEMINI-pro DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a line of text
typedef struct {
    char *data;
    int length;
} Line;

// Function to read a line of text from a file
Line read_line(FILE *file) {
    Line line;
    char buffer[1024];

    // Read a line of text from the file
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        line.data = NULL;
        line.length = 0;
    } else {
        // Allocate memory for the line of text
        line.data = malloc(strlen(buffer) + 1);

        // Copy the line of text into the allocated memory
        strcpy(line.data, buffer);

        // Set the length of the line of text
        line.length = strlen(buffer);
    }

    // Return the line of text
    return line;
}

// Function to write a line of text to a file
void write_line(FILE *file, Line line) {
    // Write the line of text to the file
    fprintf(file, "%s", line.data);
}

// Function to free the memory allocated for a line of text
void free_line(Line line) {
    // Free the memory allocated for the line of text
    free(line.data);
}

// Main function
int main() {
    // Open the input file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Open the output file
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // Read the lines of text from the input file
    Line line;
    while ((line = read_line(input_file)).length > 0) {
        // Write the lines of text to the output file
        write_line(output_file, line);

        // Free the memory allocated for the line of text
        free_line(line);
    }

    // Close the input file
    fclose(input_file);

    // Close the output file
    fclose(output_file);

    return EXIT_SUCCESS;
}