//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void trim_whitespace(char *line) {
    char *end;

    // Trim leading whitespace
    while (isspace((unsigned char)*line)) line++;

    // Trim trailing whitespace
    if (*line == 0) return;  // All spaces
    end = line + strlen(line) - 1;
    while (end > line && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

void add_indentation(char *line, int indent_level) {
    int i;
    for (i = 0; i < indent_level * INDENT_SIZE; i++) {
        printf(" ");
    }
    printf("%s\n", line);
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    if (!input || !output) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    bool in_tag = false, self_closing = false;

    while (fgets(line, sizeof(line), input)) {
        trim_whitespace(line);

        if (strlen(line) == 0) {
            continue;  // Skip empty lines
        }

        // Check for opening and closing tags
        if (line[0] == '<') {
            if (line[1] != '/') { // Opening tag
                add_indentation(line, indent_level);
                indent_level += !self_closing; // Increase indentation for non-self-closing tags
                if (strchr(line, '/')) {
                    self_closing = true;
                } else {
                    self_closing = false;
                }
            } else { // Closing tag
                indent_level--;
                add_indentation(line, indent_level);
            }
        } else {
            add_indentation(line, indent_level);
        }
    }

    fclose(input);
    fclose(output);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <input_file.html> <output_file.html>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    return EXIT_SUCCESS;
}