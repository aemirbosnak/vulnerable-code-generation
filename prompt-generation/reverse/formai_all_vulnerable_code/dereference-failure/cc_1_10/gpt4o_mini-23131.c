//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void beautify_html(const char *input_filename, const char *output_filename);
void add_indent(FILE *output_file, int indent_level);
int is_tag(const char *buffer);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return 1;
    }

    beautify_html(argv[1], argv[2]);
    return 0;
}

void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    if (!input_file) {
        perror("Error opening input file");
        return;
    }
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    int indent_level = 0;
    while (fgets(buffer, sizeof(buffer), input_file)) {
        char *ptr = buffer;
        while (*ptr) {
            if (is_tag(ptr)) {
                // Handle opening tag
                if (*(ptr + 1) != '/') {
                    add_indent(output_file, indent_level);
                    fprintf(output_file, "%s", ptr);
                    indent_level++;
                    break;
                } else {
                    // Handle closing tag
                    indent_level--;
                    add_indent(output_file, indent_level);
                    fprintf(output_file, "%s", ptr);
                    break;
                }
            }
            ptr++;
        }
        // After processing a line, adjust indentation if necessary
        if (strlen(buffer) > 0) {
            // For non-empty lines, write the line directly
            if (ptr - buffer > 0) {
                add_indent(output_file, indent_level);
                fprintf(output_file, "%s", buffer);
            }
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void add_indent(FILE *output_file, int indent_level) {
    for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
        fputc(' ', output_file);
    }
}

int is_tag(const char *buffer) {
    return buffer[0] == '<' && (buffer[1] != '?' && buffer[1] != '!');
}