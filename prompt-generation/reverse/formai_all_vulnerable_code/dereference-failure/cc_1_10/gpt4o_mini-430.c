//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000
#define INDENT_SPACES 4

void beautify_html(char *input, char *output) {
    int indent_level = 0;
    int in_tag = 0;
    int i = 0, j = 0;
    int len = strlen(input);
    char ch;

    while (i < len) {
        ch = input[i];

        // Check if the character is a '<'
        if (ch == '<') {
            // If it's not a closing tag, increase the indent level
            if (input[i + 1] != '/') {
                if (indent_level > 0) {
                    output[j++] = '\n'; // New line after previous tag
                    for (int k = 0; k < indent_level * INDENT_SPACES; k++) {
                        output[j++] = ' '; // Add spaces for indentation
                    }
                }
                indent_level++;
            } else {
                indent_level--;
                if (indent_level < 0) {
                    indent_level = 0; // Don't allow negative indent
                }
                output[j++] = '\n'; // New line before the closing tag
                for (int k = 0; k < indent_level * INDENT_SPACES; k++) {
                    output[j++] = ' '; // Add spaces for indentation
                }
            }
            in_tag = 1; // We are in a tag
        } else if (ch == '>') {
            in_tag = 0; // We are out of a tag
        }

        output[j++] = ch; // Copy the character
        i++;
    }

    output[j] = '\0'; // Null-terminate the output string
}

void read_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fread(buffer, 1, MAX_LENGTH, file);
    fclose(file);
}

void write_file(const char *filename, const char *buffer) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", buffer);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *input_buffer = (char *)malloc(MAX_LENGTH);
    char *output_buffer = (char *)malloc(MAX_LENGTH);

    read_file(input_file, input_buffer);
    beautify_html(input_buffer, output_buffer);
    write_file(output_file, output_buffer);

    free(input_buffer);
    free(output_buffer);

    printf("HTML beautification completed. Output written to %s\n", output_file);
    return EXIT_SUCCESS;
}