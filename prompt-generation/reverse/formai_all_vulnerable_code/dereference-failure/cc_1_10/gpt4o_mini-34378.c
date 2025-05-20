//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

// Function to trim whitespace from a string
char* trim_whitespace(char* str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the trimmed string
    *(end + 1) = '\0';

    return str;
}

// Function to check if the line is an opening tag
bool is_opening_tag(const char* line) {
    return line[0] == '<' && line[1] != '/' && line[strlen(line)-1] == '>';
}

// Function to check if the line is a closing tag
bool is_closing_tag(const char* line) {
    return line[0] == '<' && line[1] == '/' && line[strlen(line)-1] == '>';
}

// Function to beautify the HTML content
void beautify_html(FILE* input_file, FILE* output_file) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    
    while (fgets(line, sizeof(line), input_file)) {
        char* trimmed_line = trim_whitespace(line);

        // Determine if we need to add indentation
        for (int i = 0; i < indent_level; i++) {
            fprintf(output_file, "%*s", INDENT_SIZE, "");
        }

        // Write the current line to the output file
        fprintf(output_file, "%s\n", trimmed_line);

        // Adjust indentation level based on the type of tag
        if (is_opening_tag(trimmed_line)) {
            indent_level++;
        } else if (is_closing_tag(trimmed_line)) {
            indent_level--;
            // Make sure we don't go negative
            if (indent_level < 0) {
                indent_level = 0;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification completed. Output written to %s\n", argv[2]);
    return EXIT_SUCCESS;
}