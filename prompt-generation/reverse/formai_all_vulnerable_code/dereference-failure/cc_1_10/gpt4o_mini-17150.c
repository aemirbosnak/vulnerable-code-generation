//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

// Function to trim leading whitespace characters
char *trim_whitespace(char *line) {
    char *start = line;
    while (isspace((unsigned char)*start)) start++; // Trim leading spaces
    return start;
}

// Function to add indentation based on level
void add_indentation(FILE *output, int indent_level) {
    for (int i = 0; i < indent_level; i++) {
        for (int j = 0; j < INDENT_SIZE; j++) {
            fputc(' ', output); // Print spaces for indentation
        }
    }
}

// Function to beautify an HTML line
void beautify_html_line(FILE *output, char *line, int *indent_level) {
    char *trimmed_line = trim_whitespace(line);
    
    if (strncmp(trimmed_line, "</", 2) == 0) {
        // Closing tag decreases indentation
        (*indent_level)--;
    }
    
    add_indentation(output, *indent_level);
    fputs(trimmed_line, output);
    fputc('\n', output);
    
    if (trimmed_line[strlen(trimmed_line) - 1] == '>') {
        if (trimmed_line[1] != '/') {
            // Opening tag increases indentation, skip self-closing tags
            if (!strstr(trimmed_line, "/>")) {
                (*indent_level)++;
            }
        }
    }
}

// Function to beautify the entire HTML file
void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (!input || !output) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        beautify_html_line(output, line, &indent_level);
    }

    fclose(input);
    fclose(output);
}

// Function to print usage instructions
void print_usage() {
    printf("Usage: html_beautifier <input_file> <output_file>\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    printf("Beautification Completed! Check %s for output.\n", argv[2]);

    return EXIT_SUCCESS;
}