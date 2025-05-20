//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define TAB_SIZE 4

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    if (in == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    if (out == NULL) {
        perror("Error opening output file");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int i;

    while (fgets(line, sizeof(line), in)) {
        char *ptr = line;
        while (*ptr) {
            if (*ptr == '<' && *(ptr + 1) != '/') { // Opening tag
                // Print the current line with indentation
                for (i = 0; i < indent_level * TAB_SIZE; i++) {
                    fputc(' ', out);
                }
                fputs(ptr, out);
                indent_level++;
                break;
            }
            if (*ptr == '<' && *(ptr + 1) == '/') { // Closing tag
                indent_level--;
                // Print the current line with indentation
                for (i = 0; i < indent_level * TAB_SIZE; i++) {
                    fputc(' ', out);
                }
                fputs(ptr, out);
                break;
            }
            ptr++;
        }
    }

    fclose(in);
    fclose(out);
}

void display_instructions() {
    printf("HTML Beautifier\n");
    printf("Usage: ./html_beautifier <input_file> <output_file>\n");
    printf("This program reads an HTML file and outputs a beautified version of it.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_instructions();
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    printf("Beautification complete. Output written to %s\n", argv[2]);
    return EXIT_SUCCESS;
}