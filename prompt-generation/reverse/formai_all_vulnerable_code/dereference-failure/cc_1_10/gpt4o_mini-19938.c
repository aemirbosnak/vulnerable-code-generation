//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 4096
#define INDENT_SIZE 4

void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    
    if (!input_file || !output_file) {
        fprintf(stderr, "Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER];
    int indent_level = 0;
    int inside_tag = 0;

    while (fgets(buffer, MAX_BUFFER, input_file)) {
        for (char *ptr = buffer; *ptr != '\0'; ptr++) {
            if (*ptr == '<') {
                if (inside_tag) {
                    fputc('\n', output_file);
                    for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
                        fputc(' ', output_file);
                    }
                }
                inside_tag = 1;
                // Check for closing tag
                if (*(ptr + 1) == '/') {
                    indent_level--;
                }
                fputs(ptr, output_file);
                if (*(ptr + 1) != '/') {
                    indent_level++;
                }
            } else if (*ptr == '>') {
                fputc(*ptr, output_file);
                inside_tag = 0;
                fputc('\n', output_file);
                for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
                    fputc(' ', output_file);
                }
            } else {
                if (!inside_tag) {
                    fputc(*ptr, output_file);
                }
            }
        }
    }

    fclose(input_file);
    fclose(output_file);
    
    printf("HTML beautification complete! Check the output file: %s\n", output_filename);
}

int main() {
    const char *input_filename = "input.html";      // Input file
    const char *output_filename = "output.html";    // Output file

    beautify_html(input_filename, output_filename);

    return 0;
}