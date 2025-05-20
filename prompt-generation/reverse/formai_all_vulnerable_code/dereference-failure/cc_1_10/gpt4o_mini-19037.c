//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INDENTATION_SPACES 4

// Function prototypes
void beautify_html(const char* input_file, const char* output_file);
void process_line(char* line, FILE* output);
void add_indentation(FILE* output, int level);
int is_opening_tag(const char* token);
int is_closing_tag(const char* token);
int is_self_closing_tag(const char* token);
int is_tag(const char* token);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return 1;
    }

    beautify_html(argv[1], argv[2]);

    return 0;
}

void beautify_html(const char* input_file, const char* output_file) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");
    if (!input || !output) {
        fprintf(stderr, "Error opening files!\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int indentation_level = 0;

    while (fgets(line, MAX_LINE_LENGTH, input)) {
        process_line(line, output);
        // Adjust indentation based on tags
        char* token = strtok(line, " \t\n");
        while (token != NULL) {
            if (is_opening_tag(token)) {
                indentation_level++;
            } else if (is_closing_tag(token)) {
                indentation_level--;
            }
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(input);
    fclose(output);
}

void process_line(char* line, FILE* output) {
    char* trimmed_line = strtok(line, "\n");
    // Skip empty lines
    if (trimmed_line[0] != '\0') {
        int level = 0;
        // Count indentation level
        for (int i = 0; i < strlen(trimmed_line); i++) {
            if (trimmed_line[i] == '<') {
                level++;
            }
        }
        // Write indentation
        add_indentation(output, level);
        fprintf(output, "%s\n", trimmed_line);
    }
}

void add_indentation(FILE* output, int level) {
    for (int i = 0; i < (level * INDENTATION_SPACES); i++) {
        fputc(' ', output);
    }
}

int is_opening_tag(const char* token) {
    return (token[0] == '<' && token[1] != '/' && token[strlen(token) - 1] != '/');
}

int is_closing_tag(const char* token) {
    return (token[0] == '<' && token[1] == '/');
}

int is_self_closing_tag(const char* token) {
    return (token[0] == '<' && token[strlen(token) - 1] == '/');
}

int is_tag(const char* token) {
    return (token[0] == '<' && token[strlen(token) - 1] == '>');
}