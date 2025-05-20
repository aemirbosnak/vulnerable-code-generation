//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define INDENT_STRING "    "

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    FILE *out_file = fopen(output_file, "w");
    
    if (!in_file || !out_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    char buffer[BUFFER_SIZE];
    int indent_level = 0;
    int in_tag = 0;

    while (fgets(buffer, BUFFER_SIZE, in_file)) {
        char *ptr = buffer;

        while (*ptr) {
            // Check for opening tag
            if (*ptr == '<' && (*(ptr + 1) != '/')) {
                if (in_tag) {
                    fprintf(out_file, "\n"); // Ensure new line for nested tag
                }
                fprintf(out_file, "%*s<", indent_level * 4, ""); // Indentation for the tag
                in_tag = 1;
                while (*ptr && *ptr != '>') {
                    fputc(*ptr++, out_file);
                }
                fputc('>', out_file);
                indent_level++; // Increase indent level after an opening tag
            }
            // Check for closing tag
            else if (*ptr == '<' && (*(ptr + 1) == '/')) {
                indent_level--; // Decrease indent level before a closing tag
                fprintf(out_file, "\n%*s<", indent_level * 4, ""); // Indentation
                while (*ptr && *ptr != '>') {
                    fputc(*ptr++, out_file);
                }
                fputc('>', out_file);
                in_tag = 0;
            } else {
                if (in_tag) {
                    fputc('\n', out_file); // Ensure new line after a complete tag
                }
                fputc(*ptr, out_file);
            }
            ptr++; // Move to next character
        }
        fputc('\n', out_file); // End of line for current buffer
    }

    fclose(in_file);
    fclose(out_file);
    printf("HTML file has been beautified and saved to %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    printf("Welcome to the HTML beautifier!\n");
    printf("We're about to format your HTML file for better readability.\n");
    
    beautify_html(argv[1], argv[2]);

    printf("Beautification complete! Check the output file for your prettified HTML.\n");
    
    return EXIT_SUCCESS;
}