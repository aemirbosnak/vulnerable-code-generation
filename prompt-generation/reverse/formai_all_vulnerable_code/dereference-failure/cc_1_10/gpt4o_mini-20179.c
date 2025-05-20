//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 10

void trim_whitespace(char *line) {
    char *end;

    // Trim leading space
    while(*line == ' ') line++;

    // Trim trailing space
    end = line + strlen(line) - 1;
    while(end > line && *end == ' ') end--;
    *(end + 1) = '\0';
}

void beautify_line(char *line, int indent_level) {
    for(int i = 0; i < indent_level; i++) {
        printf("    "); // Use 4 spaces for indentation
    }
    printf("%s\n", line);
}

bool is_opening_tag(const char *line) {
    return strchr(line, '<') && !strchr(line, '/');
}

bool is_closing_tag(const char *line) {
    return strchr(line, '<') && strchr(line, '/');
}

void beautify_html(const char *input_file) {
    FILE *file = fopen(input_file, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    bool inside_tag = false;

    while (fgets(line, sizeof(line), file)) {
        trim_whitespace(line);

        if (strlen(line) == 0) {
            continue; // Skip empty lines
        }

        if (is_opening_tag(line)) {
            beautify_line(line, indent_level);
            indent_level++;
            inside_tag = true;
        } else if (is_closing_tag(line)) {
            indent_level--;
            beautify_line(line, indent_level);
            inside_tag = false;
        } else {
            if (inside_tag) {
                beautify_line(line, indent_level);
            } else {
                beautify_line(line, indent_level);
            }
        }

        if (!inside_tag) {
            beautify_line("", indent_level); // Add a blank line for clarity
        }
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1]);
    return EXIT_SUCCESS;
}