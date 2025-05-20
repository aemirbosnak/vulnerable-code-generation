//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

// Function prototypes
void beautify_html(const char *input_filename, const char *output_filename);
void write_indented(FILE *output_file, const char *line, int indent_level);
int is_opening_tag(const char *line);
int is_closing_tag(const char *line);
void trim_whitespace(char *str);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

// Function to beautify HTML
void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    if (!input_file || !output_file) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    char line[BUFFER_SIZE];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input_file) != NULL) {
        char trimmed_line[BUFFER_SIZE];
        strcpy(trimmed_line, line);
        trim_whitespace(trimmed_line);

        write_indented(output_file, trimmed_line, indent_level);

        if (is_opening_tag(trimmed_line)) {
            indent_level++;
        } 
        if (is_closing_tag(trimmed_line)) {
            indent_level--;
        }
    }

    fclose(input_file);
    fclose(output_file);
}

// Function to write indented line to output file
void write_indented(FILE *output_file, const char *line, int indent_level) {
    if (indent_level < 0) indent_level = 0; // Prevent negative indentation
    for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
        fputc(' ', output_file);
    }
    fputs(line, output_file);
}

// Check if the line contains an opening HTML tag
int is_opening_tag(const char *line) {
    return (strstr(line, "<") && strstr(line, ">") && line[1] != '/');
}

// Check if the line contains a closing HTML tag
int is_closing_tag(const char *line) {
    return (strstr(line, "</") != NULL);
}

// Function to trim whitespace from the beginning and end of a string
void trim_whitespace(char *str) {
    int start_index = 0;
    int end_index = strlen(str) - 1;

    // Trim leading whitespace
    while (str[start_index] == ' ' || str[start_index] == '\t') {
        start_index++;
    }

    // Trim trailing whitespace
    while (end_index >= start_index && (str[end_index] == ' ' || str[end_index] == '\t' || str[end_index] == '\n')) {
        end_index--;
    }

    // Null terminate the trimmed string
    str[end_index + 1] = '\0';
    
    // Move trimmed string to the beginning if needed
    if (start_index > 0) {
        memmove(str, str + start_index, end_index + 2);
    }
}