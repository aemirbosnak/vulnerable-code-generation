//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void print_error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

void beautify_html(const char *input, const char *output) {
    FILE *in_file = fopen(input, "r");
    if (!in_file) {
        print_error("Unable to open input file.");
    }

    FILE *out_file = fopen(output, "w");
    if (!out_file) {
        fclose(in_file);
        print_error("Unable to open output file.");
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int is_inside_tag = 0;

    while (fgets(line, sizeof(line), in_file)) {
        char *pos = line;
        while (*pos) {
            if (*pos == '<') {
                if (*(pos + 1) == '/') {
                    indent_level--; // Closing tag, decrease indent level
                }

                // Print indentation
                for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
                    fputc(' ', out_file);
                }

                is_inside_tag = 1; // We're now inside a tag
            }

            // If the character is '>', we might close a tag
            if (*pos == '>') {
                // Print the '>' character
                fputc(*pos, out_file);
                
                // If it's not a self-closing tag, increase before the next line
                if (*(pos - 1) != '/') {
                    if (*(pos + 1) != '\0' && *(pos + 1) != '\n') {
                        indent_level++; // Next line should be deeper
                    }
                }

                is_inside_tag = 0; // We're now outside a tag
            }
            fputc(*pos++, out_file);
        }
    }

    // Close files
    fclose(in_file);
    fclose(out_file);
}

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);

    printf("HTML has been beautified! Check the output file: %s\n", argv[2]);
    return EXIT_SUCCESS;
}