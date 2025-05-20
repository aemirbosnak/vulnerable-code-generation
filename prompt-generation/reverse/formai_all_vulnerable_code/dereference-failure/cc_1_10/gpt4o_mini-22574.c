//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

void beautify_html(FILE *input, FILE *output) {
    char buffer[BUFFER_SIZE];
    int indent_level = 0;
    int inside_tag = 0;

    while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
        for (char *ptr = buffer; *ptr != '\0'; ptr++) {
            if (*ptr == '<') {
                if (*(ptr + 1) == '/') { // It's a closing tag
                    indent_level--;
                    fprintf(output, "\n%.*s", indent_level * INDENT_SIZE, " ");
                } else if (*(ptr + 1) != '!') { // Not a comment
                    fprintf(output, "\n%.*s", indent_level * INDENT_SIZE, " ");
                    indent_level++;
                }
                inside_tag = 1;
            }

            fputc(*ptr, output);

            if (inside_tag && *ptr == '>') {
                inside_tag = 0;
                if (*(ptr - 1) != '/') { // If not self-closing tag
                    indent_level--;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification complete. Output written to '%s'.\n", argv[2]);
    return EXIT_SUCCESS;
}