//FormAI DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAB_SIZE 4

void beautify_html(FILE *input_file, FILE *output_file) {
    char current_char, prev_char;
    int indent_level = 0;

    while ((current_char = fgetc(input_file)) != EOF) {
        if (current_char == '<') {
            // Check if it is an opening tag or a closing tag
            bool is_closing_tag = false;
            current_char = fgetc(input_file); // Skip the '<'
            if (current_char == '/') {
                is_closing_tag = true;
                current_char = fgetc(input_file);
            }

            // Output the proper indentation level and the tag
            for (int i = 0; i < indent_level * TAB_SIZE; i++) {
                fputc(' ', output_file);
            }
            if (is_closing_tag) {
                indent_level--;
                fputc('/', output_file);
            }
            else {
                indent_level++;
            }
            fputc('<', output_file);
            fputc(current_char, output_file);

            // Copy everything until the end of the tag
            while ((current_char = fgetc(input_file)) != '>') {
                fputc(current_char, output_file);
            }
            fputc('>', output_file);

            // Check if it was a self-closing tag
            if (prev_char == '/') {
                indent_level--;
                fputs(">", output_file);
            }

            // Add a newline
            fputs("\n", output_file);
        }
        else {
            fputc(current_char, output_file);
        }

        prev_char = current_char;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s [input file] [output file]\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}