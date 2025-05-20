//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INDENTATION_LEVEL 4

void beautify_html_line(char *line, FILE *output) {
    static int indent_level = 0;
    char *ptr = line;
    char buffer[MAX_LINE_LENGTH];
    int in_tag = 0;
    int buffer_index = 0;
    int i;

    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] == '<') {
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                fprintf(output, "%*s%s\n", indent_level * INDENTATION_LEVEL, "", buffer);
                buffer_index = 0;
            }
            in_tag = 1; // we are now inside a tag
            buffer[buffer_index++] = line[i];
        } else if (line[i] == '>') {
            buffer[buffer_index++] = line[i];
            buffer[buffer_index] = '\0';
            fprintf(output, "%*s%s\n", indent_level * INDENTATION_LEVEL, "", buffer);
            buffer_index = 0;
            in_tag = 0;
            // Check if it's an opening or closing tag to adjust indent level
            if (line[i - 1] != '/') {
                // If it is an opening tag
                indent_level++;
            }
        } else if (in_tag) {
            buffer[buffer_index++] = line[i];
        } else if (!isspace(line[i])) {
            buffer[buffer_index++] = line[i];
        }
    }
    // If there's remaining text in the buffer, output it.
    if (buffer_index > 0) {
        buffer[buffer_index] = '\0';
        fprintf(output, "%*s%s\n", indent_level * INDENTATION_LEVEL, "", buffer);
    }
    // Adjust the indentation for the closing tags
    if (line[i-1] == '/') {
        indent_level--;
    }
}

int beautify_html_file(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (!input_file || !output_file) {
        perror("Error opening file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), input_file)) {
        beautify_html_line(line, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return 1;
    }

    if (beautify_html_file(argv[1], argv[2]) != 0) {
        fprintf(stderr, "Failed to beautify HTML file.\n");
        return 1;
    }

    printf("Beautification completed! Output written to %s\n", argv[2]);
    return 0;
}