//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 20

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        fprintf(stderr, "Error: Cannot open input file.\n");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        fprintf(stderr, "Error: Cannot open output file.\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        char *trim_line = strtok(line, "\n"); // Remove newline character
        
        // Check for opening and closing tags
        if (strstr(trim_line, "</") != NULL) {
            // Decrease indentation level before writing closing tags
            indent_level--;
            for (int i = 0; i < indent_level; i++) {
                fprintf(output, "\t");
            }
            fprintf(output, "%s\n", trim_line);
        } else if (strstr(trim_line, "<") != NULL && strstr(trim_line, "/>") == NULL) {
            // Write opening tags with current indentation
            for (int i = 0; i < indent_level; i++) {
                fprintf(output, "\t");
            }
            fprintf(output, "%s\n", trim_line);
            // Increase indent level if it's not a self-closing tag
            if (strstr(trim_line, "/>") == NULL && strstr(trim_line, "<!DOCTYPE") == NULL) {
                indent_level++;
            }
        } else {
            // Write non-tag lines with current indentation
            for (int i = 0; i < indent_level; i++) {
                fprintf(output, "\t");
            }
            fprintf(output, "%s\n", trim_line);
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautification completed successfully!\n");
    
    return EXIT_SUCCESS;
}