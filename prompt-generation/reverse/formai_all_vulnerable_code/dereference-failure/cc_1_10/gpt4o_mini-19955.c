//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

// Function declarations
void beautify_html(const char *input_file, const char *output_file);
void indent_line(char *line, int level, FILE *output);
void process_tag(char *line, int *indent_level, FILE *output);
int is_tag(const char *token);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return 1;
    }

    beautify_html(argv[1], argv[2]);
    return 0;
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    if (!input) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_file, "w");
    if (!output) {
        perror("Failed to open output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        char *ptr = line;
        while (*ptr) {
            // Skip leading whitespace
            if (isspace(*ptr)) {
                ptr++;
                continue;
            }

            // Process tags
            if (*ptr == '<') {
                // Handle opening and closing tags
                if (strncmp(ptr, "</", 2) == 0) {
                    indent_level--;
                    fprintf(output, "\n");
                    indent_line(ptr, indent_level, output);
                    ptr = strchr(ptr, '>');
                    if (ptr) {
                        ptr++;
                    }
                    continue;
                } else {
                    indent_line(ptr, indent_level, output);
                    ptr = strchr(ptr, '>');
                    if (ptr) {
                        ptr++;
                    }
                    if (*(ptr - 2) != '/') { // Not self-closing
                        indent_level++;
                    }
                    continue;
                }
            }

            // Print any text outside tags
            char *end_of_line = strchr(ptr, '<');
            if (end_of_line) {
                *end_of_line = '\0';
                fprintf(output, "%s", ptr);
                ptr = end_of_line;
            } else {
                fprintf(output, "%s", ptr);
                ptr += strlen(ptr); // Move to end of line
            }
        }
    }

    fclose(input);
    fclose(output);
    printf("HTML beautification completed.\n");
}

void indent_line(char *line, int level, FILE *output) {
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        fputc(' ', output);
    }

    fputs(line, output);
}

void process_tag(char *line, int *indent_level, FILE *output) {
    char *token = strtok(line, " \t\n");
    if (token == NULL) return;

    if (is_tag(token)) {
        // Opening tag identified
        fprintf(output, "%s\n", token);
        (*indent_level)++;
    } else if (strncmp(token, "</", 2) == 0) {
        // Closing tag identified
        (*indent_level)--;
        fprintf(output, "%s\n", token);
    } else {
        fputs(line, output);
    }
}

int is_tag(const char *token) {
    return token[0] == '<' && token[strlen(token) - 1] == '>';
}