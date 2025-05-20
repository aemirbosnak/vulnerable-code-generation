//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

void beautify_html(FILE *input, FILE *output) {
    char buffer[BUFFER_SIZE];
    int indent_level = 0;
    int in_tag = 0;  // Flag to track if we are inside an HTML tag
    int is_closing_tag = 0;
    int is_self_closing_tag = 0;

    while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
        char *ptr = buffer;
        while (*ptr) {
            if (*ptr == '<') {
                if (*(ptr + 1) == '/') { // Check for closing tag
                    is_closing_tag = 1;
                } else if (*(ptr + strlen(ptr) - 2) == '/') { // Check for self-closing tag
                    is_self_closing_tag = 1;
                } else {
                    // Only increment indent level if it's not a self-closing tag
                    if (!is_self_closing_tag) {
                        indent_level++;
                    }
                }

                // Print indentation
                for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
                    fputc(' ', output);
                }
                fputs(ptr, output);
                in_tag = 1;

                // Adjust indent level if it's a closing tag
                if (is_closing_tag) {
                    indent_level--;
                }
                // Reset flags
                is_closing_tag = 0;
                is_self_closing_tag = 0;
                break;

            } else if (*ptr == '>') {
                fputc(*ptr, output);
                in_tag = 0;

                if (!is_closing_tag && !is_self_closing_tag) {
                    // Only add indentation for new lines after opening tags
                    fputc('\n', output);
                    indent_level--;
                }
                break; // Exit inner while loop to re-check character at ptr
            }

            // Print current character if we're not in a tag
            if (!in_tag) {
                fputc(*ptr, output);
            }

            ptr++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error creating output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Beautification completed. Output written to %s\n", argv[2]);
    return EXIT_SUCCESS;
}