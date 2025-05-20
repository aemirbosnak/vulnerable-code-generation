//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 20

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in_fp = fopen(input_file, "r");
    if (!in_fp) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    FILE *out_fp = fopen(output_file, "w");
    if (!out_fp) {
        perror("Could not open output file");
        fclose(in_fp);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0; // Current level of indentation
    int in_tag = 0; // Flag to indicate if we are reading inside a tag

    while (fgets(line, sizeof(line), in_fp)) {
        char *ptr = line;
        while (*ptr) {
            // Check for the start of a tag
            if (*ptr == '<') {
                // Handle closing tags
                if (*(ptr + 1) == '/') {
                    indent_level--;
                    fprintf(out_fp, "\n%*s", indent_level * 4, ""); // Indentation before closing tag
                }
                // Print the current tag with indentation
                fprintf(out_fp, "%*s", indent_level * 4, "");
                in_tag = 1;
            }

            // Print the character
            fputc(*ptr, out_fp);

            // Check for the end of a tag
            if (*ptr == '>') {
                if (*(ptr - 1) != '/') { // Not a self-closing tag
                    if (in_tag) {
                        // Increase the indentation level for the next line if it's an opening tag
                        if (*(ptr - 1) != '/') {
                            indent_level++;
                        }
                    }
                }
                in_tag = 0;
            }
            ptr++;
        }
        fprintf(out_fp, "\n"); // Newline after each line
    }

    fclose(in_fp);
    fclose(out_fp);
    printf("HTML beautification completed. Output written to '%s'.\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    return EXIT_SUCCESS;
}