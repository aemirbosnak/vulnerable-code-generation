//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NEST_LEVEL 100

typedef struct {
    int indent;
    char line[MAX_LINE_LENGTH];
} IndentedLine;

// Function declarations
void beautify_html(const char *file_path);
void process_line(const char *line, IndentedLine *indented_lines, int *indent_level, int *line_count);
void print_beautified_html(IndentedLine *indented_lines, int line_count);
void trim_whitespace(char *str);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <html_file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *file_path = argv[1];
    beautify_html(file_path);
    
    return EXIT_SUCCESS;
}

void beautify_html(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    IndentedLine indented_lines[MAX_LINE_LENGTH];
    int indent_level = 0;
    int line_count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        process_line(line, indented_lines, &indent_level, &line_count);
    }
    fclose(file);
    
    print_beautified_html(indented_lines, line_count);
}

void process_line(const char *line, IndentedLine *indented_lines, int *indent_level, int *line_count) {
    char trimmed_line[MAX_LINE_LENGTH];
    strcpy(trimmed_line, line);
    trim_whitespace(trimmed_line);

    // Ignore empty lines
    if (strlen(trimmed_line) == 0) return;

    // Detect opening tags
    if (trimmed_line[0] == '<' && trimmed_line[1] != '/') {
        indented_lines[*line_count].indent = *indent_level;
        strcpy(indented_lines[*line_count].line, trimmed_line);
        (*line_count)++;
        (*indent_level)++;
    } 
    // Detect closing tags
    else if (trimmed_line[0] == '<' && trimmed_line[1] == '/') {
        if (*indent_level > 0) (*indent_level)--;
        indented_lines[*line_count].indent = *indent_level;
        strcpy(indented_lines[*line_count].line, trimmed_line);
        (*line_count)++;
    } 
    // Non-tag lines
    else {
        indented_lines[*line_count].indent = *indent_level;
        strcpy(indented_lines[*line_count].line, trimmed_line);
        (*line_count)++;
    }
}

void print_beautified_html(IndentedLine *indented_lines, int line_count) {
    for (int i = 0; i < line_count; i++) {
        for (int j = 0; j < indented_lines[i].indent; j++) {
            putchar('\t'); // Indent using tab characters
        }
        printf("%s\n", indented_lines[i].line);
    }
}

void trim_whitespace(char *str) {
    // Trim leading whitespace
    while (isspace((unsigned char)*str)) str++;
    
    // Trim trailing whitespace
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    
    // Null terminate the trimmed string
    *(end + 1) = '\0';
}