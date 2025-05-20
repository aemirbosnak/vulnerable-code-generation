//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 100

// Function to check if a character is a whitespace
int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

// Function to beautify a line of HTML
void beautify_html_line(char *line, FILE *output, int *indent_level) {
    int length = strlen(line);
    char *formatted_line = (char *)malloc(MAX_LINE_LENGTH);
    int indent = *indent_level;
    int i = 0, j = 0;

    // Process the line for indentation
    for (i = 0; i < length; i++) {
        if (line[i] == '<') {
            // Check for closing tags
            if (line[i + 1] == '/') {
                indent--;
            }

            // Add indentation to the formatted output
            for (int k = 0; k < indent; k++) {
                formatted_line[j++] = ' ';
                formatted_line[j++] = ' ';
            }

            formatted_line[j++] = '<';
        } else if (line[i] == '>') {
            formatted_line[j++] = '>';
            // Increment indent after an opening tag
            if (line[i - 1] != '/') {
                indent++;
            }
        } else {
            formatted_line[j++] = line[i];
        }
    }

    formatted_line[j] = '\0'; // Terminate the string

    // Write to the output file
    fprintf(output, "%s\n", formatted_line);
    free(formatted_line); // Free the allocated memory
    *indent_level = indent; // Update indent level
}

// Function to beautify an entire HTML file
void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    
    if (!input_file || !output_file) {
        fprintf(stderr, "Error opening files.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input_file)) {
        beautify_html_line(line, output_file, &indent_level);
    }

    fclose(input_file);
    fclose(output_file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return 1;
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautification complete! Output written to %s.\n", argv[2]);
    
    return 0;
}