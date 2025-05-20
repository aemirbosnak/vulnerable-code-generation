//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void indent_lines(char *line, int indent_count) {
    char *indented_line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    if (indented_line == NULL) {
        perror("Unable to allocate memory for indented line");
        exit(EXIT_FAILURE);
    }
    
    // Create indentation
    for (int i = 0; i < indent_count * INDENT_SIZE; i++) {
        indented_line[i] = ' ';
    }
    indented_line[indent_count * INDENT_SIZE] = '\0'; // Null-terminate
    
    // Concatenate indentation and line
    strcat(indented_line, line);
    strcpy(line, indented_line);
    
    free(indented_line);
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    if (in_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    
    FILE *out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        fclose(in_file);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    int indent_count = 0;
    
    while (fgets(line, sizeof(line), in_file)) {
        // Remove leading whitespace
        char *trimmed_line = line;
        while (*trimmed_line == ' ') trimmed_line++;
        
        // Detect opening tags
        if (strstr(trimmed_line, "<") == trimmed_line) {
            // Check if it is a closing tag
            if (strstr(trimmed_line, "</") == trimmed_line) {
                indent_count--;
            }
            indent_lines(line, indent_count);
            // Check if it is an opening tag
            if (strstr(trimmed_line, "/>") == NULL && strstr(trimmed_line, "</") == NULL) {
                indent_count++;
            }
        } else {
            // In case of text outside tags, we apply current indent
            indent_lines(line, indent_count);
        }
        
        fputs(line, out_file);
    }
    
    fclose(in_file);
    fclose(out_file);
}

void display_usage(const char *program_name) {
    printf("Usage: %s <input_html_file> <output_html_file>\n", program_name);
    printf("This program beautifies the given HTML file and saves the result to a new file.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);

    printf("HTML beautification completed. Output saved to: %s\n", argv[2]);
    
    return EXIT_SUCCESS;
}