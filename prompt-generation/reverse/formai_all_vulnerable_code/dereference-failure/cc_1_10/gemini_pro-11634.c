//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line of text.
#define MAX_LINE_LENGTH 256

// Define the maximum number of lines in the text.
#define MAX_NUM_LINES 100

// Define the name of the input file.
#define INPUT_FILE_NAME "input.txt"

// Define the name of the output file.
#define OUTPUT_FILE_NAME "output.txt"

// Read the text from the input file.
char *read_text(const char *file_name) {
    // Open the input file.
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the text.
    char *text = malloc(MAX_NUM_LINES * MAX_LINE_LENGTH);
    if (text == NULL) {
        perror("Error allocating memory for text");
        exit(EXIT_FAILURE);
    }

    // Read the text from the input file.
    int num_lines = 0;
    while (fgets(text + num_lines * MAX_LINE_LENGTH, MAX_LINE_LENGTH, file) != NULL) {
        num_lines++;
    }

    // Close the input file.
    fclose(file);

    // Return the text.
    return text;
}

// Write the text to the output file.
void write_text(const char *file_name, const char *text) {
    // Open the output file.
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Write the text to the output file.
    int num_lines = 0;
    while (text[num_lines * MAX_LINE_LENGTH] != '\0') {
        fputs(text + num_lines * MAX_LINE_LENGTH, file);
        num_lines++;
    }

    // Close the output file.
    fclose(file);
}

// Remove the duplicates from the text.
char *remove_duplicates(char *text) {
    // Allocate memory for the new text.
    char *new_text = malloc(MAX_NUM_LINES * MAX_LINE_LENGTH);
    if (new_text == NULL) {
        perror("Error allocating memory for new text");
        exit(EXIT_FAILURE);
    }

    // Copy the first line of the text to the new text.
    strcpy(new_text, text);

    // Loop through the remaining lines of the text.
    int i = 1;
    while (text[i * MAX_LINE_LENGTH] != '\0') {
        // Check if the current line is a duplicate of any of the previous lines.
        int is_duplicate = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(text + i * MAX_LINE_LENGTH, text + j * MAX_LINE_LENGTH) == 0) {
                is_duplicate = 1;
                break;
            }
        }

        // If the current line is not a duplicate, copy it to the new text.
        if (!is_duplicate) {
            strcpy(new_text + i * MAX_LINE_LENGTH, text + i * MAX_LINE_LENGTH);
            i++;
        }
    }

    // Return the new text.
    return new_text;
}

// Main function.
int main(void) {
    // Read the text from the input file.
    char *text = read_text(INPUT_FILE_NAME);

    // Remove the duplicates from the text.
    char *new_text = remove_duplicates(text);

    // Write the new text to the output file.
    write_text(OUTPUT_FILE_NAME, new_text);

    // Free the memory allocated for the text.
    free(text);
    free(new_text);

    return EXIT_SUCCESS;
}