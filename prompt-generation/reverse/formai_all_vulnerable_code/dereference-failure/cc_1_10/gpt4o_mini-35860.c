//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 100

void beautify_html(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    char indent[MAX_INDENT];

    while (fgets(line, sizeof(line), input)) {
        char *ptr = line;
        int line_length = strlen(line);

        // Strip leading whitespace
        while (*ptr == ' ' || *ptr == '\t') {
            ptr++;
        }

        // Check for closing tags
        if (strncmp(ptr, "</", 2) == 0) {
            indent_level--;
        }

        // Print current indent
        memset(indent, ' ', indent_level * 4);
        indent[indent_level * 4] = '\0';  // Null-terminate indent string

        // Write the indented line to output
        fprintf(output, "%s%s", indent, ptr);

        // Check for opening tags, comments and adjust indent level
        if (strncmp(ptr, "<", 1) == 0) {
            if (strncmp(ptr, "<!--", 4) != 0 && strncmp(ptr, "</", 2) != 0) {
                indent_level++;
            } 
            if (strncmp(ptr, "</", 2) == 0 || strncmp(ptr + line_length - 2, "/>", 2) == 0) {
                indent_level--;
            }
        }
    }
}

void display_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <input.html> <output.html>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification complete! Output saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}