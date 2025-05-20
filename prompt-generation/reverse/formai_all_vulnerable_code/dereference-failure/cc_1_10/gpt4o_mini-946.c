//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_STRING "    " // Four spaces for indentation
#define MAX_INDENT_LEVEL 100

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    FILE *out_file = fopen(output_file, "w");
    if (!in_file || !out_file) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int i, j;

    while (fgets(line, sizeof(line), in_file)) {
        // Process line for opening tags
        for (i = 0; line[i] != '\0'; i++) {
            if (line[i] == '<' && line[i + 1] != '/') {
                // Opening tag found
                fprintf(out_file, "%s", INDENT_STRING);
                indent_level++;
                break;
            } else if (line[i] == '<' && line[i + 1] == '/') {
                // Closing tag found
                indent_level--;
                fprintf(out_file, "%s", INDENT_STRING);
            }
        }

        // Apply indentation
        for (j = 0; j < indent_level; j++) {
            fprintf(out_file, "%s", INDENT_STRING);
        }

        // Write the line after indenting
        fprintf(out_file, "%s", line);

        // Check for self-closing tags
        if (strstr(line, "/>")) {
            indent_level--; // No need to increase indent
        }

        // Reset line reading for next loop
        memset(line, 0, sizeof(line));
    }

    fclose(in_file);
    fclose(out_file);
    printf("HTML beautification completed. Output saved to %s.\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    return EXIT_SUCCESS;
}