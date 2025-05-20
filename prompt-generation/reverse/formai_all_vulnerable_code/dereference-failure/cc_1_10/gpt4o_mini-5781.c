//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void beautify_html(const char *filename);
void process_line(const char *line, int indent_level);
void print_indent(int level);
int is_opening_tag(const char *line);
int is_closing_tag(const char *line);
int is_self_closing_tag(const char *line);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1]);
    return EXIT_SUCCESS;
}

void beautify_html(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        process_line(line, indent_level);
        
        // Check if the line contains opening or closing tags to adjust indentation
        if (is_opening_tag(line) && !is_self_closing_tag(line)) {
            indent_level++;
        }
        else if (is_closing_tag(line)) {
            indent_level--;
        }
    }

    fclose(file);
}

void process_line(const char *line, int indent_level) {
    // Print indentation based on the current indent level
    print_indent(indent_level);
    printf("%s", line);
}

void print_indent(int level) {
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        putchar(' ');
    }
}

int is_opening_tag(const char *line) {
    return (line[0] == '<' && line[1] != '/' && line[strlen(line) - 2] != '/');
}

int is_closing_tag(const char *line) {
    return (line[0] == '<' && line[1] == '/');
}

int is_self_closing_tag(const char *line) {
    return (line[strlen(line) - 2] == '/');
}