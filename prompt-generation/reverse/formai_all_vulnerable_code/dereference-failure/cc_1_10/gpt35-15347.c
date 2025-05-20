//FormAI DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

// Function to handle errors
void die(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

// Function to print the usage message
void print_usage() {
    printf("Usage: htmlbeautifier [input_file] [output_file]\n");
    printf("If input_file is not specified, reads from stdin.\n");
    printf("If output_file is not specified, writes to stdout.\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Variables
    FILE *input_file = stdin;
    FILE *output_file = stdout;
    char *input_buffer = NULL;
    char *output_buffer = NULL;
    char *line_start = NULL; // Pointer to the start of the current line
    int input_buffer_size = 0;
    int output_buffer_size = 0;
    int c = 0; // Current character
    int indent_level = 0; // Current indentation level
    int i = 0; // Counter variable

    // Parse the command-line arguments
    if (argc > 3) die("Too many arguments");
    if (argc >= 2) {
        input_file = fopen(argv[1], "r");
        if (!input_file) die("Cannot open input file");
    }
    if (argc == 3) {
        output_file = fopen(argv[2], "w");
        if (!output_file) die("Cannot open output file");
    }

    // Read the input file into a buffer
    while ((c = fgetc(input_file)) != EOF) {
        if (input_buffer_size == 0) {
            input_buffer = malloc(sizeof(char));
            if (!input_buffer) die("Memory allocation failed");
        } else {
            input_buffer = realloc(input_buffer, input_buffer_size + 1);
            if (!input_buffer) die("Memory allocation failed");
        }
        input_buffer[input_buffer_size] = (char) c;
        input_buffer_size++;
    }

    // Add a trailing newline to the input buffer if it doesn't have one
    if (input_buffer_size > 0 && input_buffer[input_buffer_size - 1] != '\n') {
        input_buffer = realloc(input_buffer, input_buffer_size + 1);
        if (!input_buffer) die("Memory allocation failed");
        input_buffer[input_buffer_size] = '\n';
        input_buffer_size++;
    }

    // Allocate memory for the output buffer
    output_buffer = malloc(sizeof(char) * input_buffer_size * TAB_SIZE);
    if (!output_buffer) die("Memory allocation failed");

    // Begin processing the input buffer
    line_start = input_buffer;
    while (*line_start != '\0') {
        // Handle whitespace at the beginning of the line
        while (isspace(*line_start)) {
            line_start++;
        }
        for (i = 0; i < indent_level; i++) {
            output_buffer[output_buffer_size] = '\t';
            output_buffer_size++;
        }

        // Copy the rest of the line to the output buffer
        while (*line_start != '\n' && *line_start != '\0') {
            output_buffer[output_buffer_size] = *line_start;
            line_start++;
            output_buffer_size++;
        }

        // Add a newline character to the output buffer
        output_buffer[output_buffer_size] = '\n';
        output_buffer_size++;

        // Update the indent level
        if (*line_start == '<' && *(line_start + 1) != '/') {
            indent_level++;
        } else if (*line_start == '<' && *(line_start + 1) == '/') {
            indent_level--;
        }

        // Move the line_start pointer to the next line
        line_start++;
    }

    // Write the output buffer to the output file
    fwrite(output_buffer, sizeof(char), output_buffer_size, output_file);

    // Clean up
    free(input_buffer);
    free(output_buffer);
    fclose(input_file);
    fclose(output_file);

    return 0;
}