//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 20

void beautify_html(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int is_in_tag = 0; // To track if the current character is inside a tag

    while (fgets(line, sizeof(line), input)) {
        char *ptr = line;
        while (*ptr) {
            // If we encounter an opening tag
            if (*ptr == '<') {
                // If this is not a closing tag, increase the indent before printing
                if (*(ptr + 1) != '/') {
                    fprintf(output, "%*s", indent_level * 4, ""); // Indentation
                    indent_level++;
                }
                is_in_tag = 1;
            }
            // If we encounter a closing tag
            else if (*ptr == '>') {
                fprintf(output, "%*s", indent_level * 4, ""); // Indentation
                if (*(ptr - 1) == '/') {
                    // Self-closing tag, do not change indent level
                } else if (*(ptr - 1) == '?') {
                    // XML declaration
                } else {
                    indent_level--;
                }
                is_in_tag = 0;
            }

            // Print the character, capitalizing first letters or special treatment inside tags
            if (is_in_tag || !isspace(*ptr)) {
                fputc(*ptr, output);
            }

            ptr++;
        }
        fputc('\n', output); // Newline after each processed line
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    fprintf(output_file, "<!-- Beautified HTML -->\n");

    // Call the beautifier function
    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification completed successfully!\n");
    return EXIT_SUCCESS;
}