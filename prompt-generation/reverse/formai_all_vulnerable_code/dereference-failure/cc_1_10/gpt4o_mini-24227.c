//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is whitespace
int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Function to beautify HTML content
void beautify_html(FILE *input_file, FILE *output_file) {
    char ch;
    int indent_level = 0;  // To keep track of the indent level
    int in_tag = 0;        // To check if we are inside an HTML tag
    int new_line_needed = 0; // Flag to determine newline
    
    // Iterating through each character in the input file
    while ((ch = fgetc(input_file)) != EOF) {
        if (ch == '<') {
            // If we are not in a tag, it's time to likely indent
            if (!in_tag && new_line_needed) {
                fprintf(output_file, "\n");
                for (int i = 0; i < indent_level; i++) {
                    fputc('\t', output_file); // Indentation
                }
            }
            in_tag = 1; // We're now inside a tag
            fprintf(output_file, "%c", ch);
            new_line_needed = 0; // Reset new line need since we're in a tag

            // Check for self-closing tags or comments
            if (fgetc(input_file) == '/') {
                indent_level--; // Decrease indent level for closing tags
            } else {
                ungetc(ch, input_file); // Push back the character we read
                if (strstr(&ch, "?") != NULL) {
                    indent_level++; // Increase indent for new elements
                }
            }
        } else if (ch == '>') {
            in_tag = 0; // We're leaving the tag
            fprintf(output_file, "%c", ch);
            new_line_needed = 1; // Mark that we need a new line after the tag
        } else {
            // Handle ordinary characters outside the tags
            if (!in_tag) {
                if (is_whitespace(ch)) {
                    if (new_line_needed) {
                        continue; // Skip unnecessary whitespaces
                    }
                } else {
                    if (new_line_needed) {
                        fprintf(output_file, "\n");
                        for (int i = 0; i < indent_level; i++) {
                            fputc('\t', output_file); // Indentation
                        }
                        new_line_needed = 0; // Reset after writing newline
                    }
                }
            }
            fprintf(output_file, "%c", ch);
        }

        // Check for end of line to possibly alter indentation rules
        if (ch == '\n') {
            // Control the newline state based on input characters
            if (in_tag) {
                new_line_needed = 0;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    // Check if the user has provided the right number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input-html-file> <output-html-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");  // Opening the input file
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w"); // Opening the output file
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    // Call the beautify_html function to process the input file
    beautify_html(input_file, output_file);

    // Close the opened files
    fclose(input_file);
    fclose(output_file);
    
    printf("Beautification completed! Check your output file: %s\n", argv[2]);
    return EXIT_SUCCESS;
}