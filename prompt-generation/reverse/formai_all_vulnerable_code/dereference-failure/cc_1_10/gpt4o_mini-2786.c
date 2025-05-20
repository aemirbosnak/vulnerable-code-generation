//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

// Function to trim leading and trailing whitespace
char *trimwhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-whitespace character
    *(end + 1) = '\0';

    return str;
}

// Function to check if the line is a closing tag
bool is_closing_tag(const char *line) {
    return line[0] == '<' && line[1] == '/' && line[strlen(line) - 1] == '>';
}

// Function to beautify HTML based on indentation size
void beautify_html(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    bool inside_tag = false;

    while (fgets(line, sizeof(line), input)) {
        // Trim the line
        char *trimmed_line = trimwhitespace(line);

        // Check for empty line
        if (strlen(trimmed_line) == 0) {
            fprintf(output, "\n");
            continue;
        }

        // Increase or decrease indentation based on tags
        if (strncmp(trimmed_line, "<", 1) == 0) {
            if (is_closing_tag(trimmed_line)) {
                indent_level--;
            }

            // Print indentations
            for (int i = 0; i < indent_level; i++) {
                fprintf(output, " ");
            }
            
            // Print the line itself
            fprintf(output, "%s\n", trimmed_line);

            // If it's not a closing tag, increase indentation for opening tags
            if (!is_closing_tag(trimmed_line) && trimmed_line[strlen(trimmed_line) - 2] != '/') {
                indent_level++;
            }
        } else {
            // For non-tag lines, print in the current indentation level
            for (int i = 0; i < indent_level; i++) {
                fprintf(output, " ");
            }
            fprintf(output, "%s\n", trimmed_line);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input HTML file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output HTML file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification completed successfully!\n");
    return EXIT_SUCCESS;
}