//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void trim_whitespace(char *line) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*line)) line++;

    // All spaces?
    if (*line == 0) {
        *line = '\0'; 
        return;
    }

    // Trim trailing space
    end = line + strlen(line) - 1;
    while (end > line && isspace((unsigned char)*end)) end--;

    // Null terminate after last non-space character
    end[1] = '\0';
}

void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (!input_file || !output_file) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    char *indent_str = malloc(INDENT_SIZE + 1);
    memset(indent_str, ' ', INDENT_SIZE);
    indent_str[INDENT_SIZE] = '\0';

    while (fgets(line, sizeof(line), input_file)) {
        trim_whitespace(line);
        
        if (strlen(line) == 0) {
            continue; // Skip empty lines
        }

        // Check for closing tags
        if (strstr(line, "</") != NULL) {
            indent_level--;
        }

        // Indent based on the current indent level
        for (int i = 0; i < indent_level; i++) {
            fputs(indent_str, output_file);
        }

        // Write the line to the output file
        fputs(line, output_file);
        fputc('\n', output_file);

        // Check for opening tags to increase indent
        if (strstr(line, "<") != NULL && strstr(line, "/>") == NULL && strstr(line, "</") == NULL) {
            indent_level++;
        }
    }

    fclose(input_file);
    fclose(output_file);
    free(indent_str);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);

    printf("HTML file beautified successfully from %s to %s\n", argv[1], argv[2]);
    
    return EXIT_SUCCESS;
}