//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define INDENT_SIZE 4

typedef enum { false, true } bool;

void strip_whitespace(char *line) {
    char *end = line + strlen(line) - 1;
    while (end > line && (*end == ' ' || *end == '\t')) end--;
    *(end + 1) = '\0';
}

void indent_line(char *line, int level, char *buffer) {
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        buffer[i] = ' ';
    }
    strcpy(buffer + level * INDENT_SIZE, line);
}

bool is_empty_line(const char *line) {
    return (line[0] == '\0');
}

bool is_opening_bracket(char c) {
    return c == '{';
}

bool is_closing_bracket(char c) {
    return c == '}';
}

void process_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    
    if (!input || !output) {
        fprintf(stderr, "Error: Unable to open input or output file.\n");
        return;
    }

    char line[MAX_LINE_LEN];
    char indented_line[MAX_LINE_LEN];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        strip_whitespace(line);

        if (is_empty_line(line)) {
            continue;
        }

        for (size_t i = 0; i < strlen(line); i++) {
            if (is_opening_bracket(line[i])) {
                indent_line(line, indent_level, indented_line);
                fprintf(output, "%s\n", indented_line);
                indent_level++;
                break;
            } else if (is_closing_bracket(line[i])) {
                indent_level--;
                indent_line(line, indent_level, indented_line);
                fprintf(output, "%s\n", indented_line);
                indent_level++;
                break;
            }
        }

        if (indent_level < 0) {
            indent_level = 0;
        }
        
        if (!is_opening_bracket(line[strlen(line) - 1]) && !is_closing_bracket(line[strlen(line) - 1])) {
            indent_line(line, indent_level, indented_line);
            fprintf(output, "%s\n", indented_line);
        }
    }

    fclose(input);
    fclose(output);
}

void display_success_message() {
    printf("The transformation of reality is complete, the HTML has been beautified.\n");
    printf("In this uncanny realm, your code flowers like a surreal dream.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    process_html(argv[1], argv[2]);
    display_success_message();

    return 0;
}