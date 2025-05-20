//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENTATION_SIZE 4

// Function to beautify a line of HTML code
void beautify_line(char *line, int indent_level, FILE *output_file) {
    // Output indentation
    for (int i = 0; i < indent_level; i++) {
        fprintf(output_file, "%*s", INDENTATION_SIZE, "");
    }

    // Output the line with a newline character
    fprintf(output_file, "%s\n", line);
}

// Function to check if a line is an opening or closing tag
int is_tag(char *line) {
    return (line[0] == '<' && line[strlen(line) - 1] == '>');
}

// Main function to beautify HTML file
void beautify_html(const char *input_file_path, const char *output_file_path) {
    FILE *input_file = fopen(input_file_path, "r");
    FILE *output_file = fopen(output_file_path, "w");
    
    if (!input_file || !output_file) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input_file)) {
        // Check if current line is an HTML tag
        if (is_tag(line)) {
            // Beautify the current line
            beautify_line(line, indent_level, output_file);

            // Check if this is a closing tag
            if (line[1] == '/') {
                indent_level--; // Decrease indentation for closing tags
            } else if (line[strlen(line) - 2] != '/') {
                indent_level++; // Increase indentation for opening tags
            }
        } else {
            // If it's not a tag, just output it
            beautify_line(line, indent_level, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Call the beautifier function
    beautify_html(argv[1], argv[2]);

    printf("HTML beautification completed successfully!\n");
    return EXIT_SUCCESS;
}