//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENTATION 100

void trim_whitespace(char *line) {
    int start = 0, end = strlen(line) - 1;

    while (isspace(line[start])) start++;
    while (end >= start && isspace(line[end])) end--;

    // If the line is empty after trimming
    if (start > end) {
        line[0] = '\0';
        return;
    }

    // Move the trimmed string to the beginning of the line
    memmove(line, line + start, end - start + 1);
    line[end - start + 1] = '\0'; // Null terminate
}

int get_indentation_level(const char *line) {
    int level = 0;
    while (*line == '\t' || *line == ' ') {
        if (*line == '\t') {
            level += 4; // Assuming tab is equivalent to 4 spaces
        } else {
            level++;
        }
        line++;
    }
    return level;
}

void beautify_html(const char *input_line, char *output_line) {
    int i = 0, indent_level = 0;
    char buffer[MAX_LINE_LENGTH];
    char *ptr = output_line;

    trim_whitespace(input_line);

    // Add indentation based on previous lines
    indent_level = get_indentation_level(input_line);
    if (indent_level > MAX_INDENTATION) {
        indent_level = MAX_INDENTATION; // Limit indentation
    }

    // Add indentation spaces
    for (i = 0; i < indent_level; i++) {
        *ptr++ = ' ';
    }

    // Copy the formatted input line to output
    strcpy(ptr, input_line);
}

void process_html_file(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    
    if (input_file == NULL) {
        fprintf(stderr, "Error: Cannot open input file %s\n", input_filename);
        exit(EXIT_FAILURE);
    }
    
    if (output_file == NULL) {
        fprintf(stderr, "Error: Cannot open output file %s\n", output_filename);
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    char input_line[MAX_LINE_LENGTH];
    char output_line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(input_line, sizeof(input_line), input_file)) {
        line_number++;
        beautify_html(input_line, output_line);
        fprintf(output_file, "%s\n", output_line);
    }

    printf("Beautification completed. Processed %d lines.\n", line_number);
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_html_file(argv[1], argv[2]);
    return EXIT_SUCCESS;
}