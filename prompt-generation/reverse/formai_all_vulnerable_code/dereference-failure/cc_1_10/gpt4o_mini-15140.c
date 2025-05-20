//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

// Function to trim leading and trailing spaces
char* trim_whitespace(char* str) {
    while (*str == ' ') str++;
    char* end = str + strlen(str) - 1;
    while (end > str && *end == ' ') end--;
    *(end + 1) = '\0';
    return str;
}

// Function to beautify a single line of HTML
void beautify_line(const char* line, FILE* output_file, int indent_level) {
    char indented_line[MAX_LINE_LENGTH];
    int i;
    
    // Apply indentation
    for (i = 0; i < indent_level * INDENT_SIZE; i++) {
        indented_line[i] = ' ';
    }
    indented_line[i] = '\0';
    
    // Append the trimmed line to the indented line
    strcat(indented_line, trim_whitespace((char*)line));

    // Write to output file
    fprintf(output_file, "%s\n", indented_line);
}

// Function to check for opening and closing HTML tags
int is_opening_tag(const char* line) {
    return line[0] == '<' && line[1] != '/';
}

int is_closing_tag(const char* line) {
    return line[0] == '<' && line[1] == '/';
}

// Function to beautify the HTML file
void beautify_html(const char* input_filename, const char* output_filename) {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    // Open input file for reading
    if ((input_file = fopen(input_filename, "r")) == NULL) {
        perror("Error opening input file");
        return;
    }

    // Open output file for writing
    if ((output_file = fopen(output_filename, "w")) == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return;
    }

    // Read lines from the input file
    while (fgets(line, sizeof(line), input_file)) {
        if (is_opening_tag(line)) {
            beautify_line(line, output_file, indent_level);
            indent_level++;
        } else if (is_closing_tag(line)) {
            indent_level--;
            beautify_line(line, output_file, indent_level);
        } else {
            beautify_line(line, output_file, indent_level);
        }
    }

    // Clean up
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    
    printf("HTML beautification completed: %s -> %s\n", argv[1], argv[2]);
    return EXIT_SUCCESS;
}