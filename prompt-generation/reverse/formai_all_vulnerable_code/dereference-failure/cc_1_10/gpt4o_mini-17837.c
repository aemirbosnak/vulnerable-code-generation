//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2048
#define INDENT_WIDTH 4

void beautify_html(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0; // Keeper of the indentation secrets! 
    char indent[INDENT_WIDTH + 1]; // Magical space holder for indentation
    memset(indent, ' ', INDENT_WIDTH); // Fill the indent with spaces!

    while (fgets(line, sizeof(line), input)) {
        char *ptr = line;
        // Trim the line from whitespace at the beginning and end, if necessary
        while (*ptr == ' ') ptr++;
        char *line_end = ptr + strlen(ptr) - 1;
        while (line_end > ptr && *line_end == ' ') line_end--;
        line_end[1] = '\0'; // Null terminate after trimming

        if (strlen(ptr) == 0) continue; // Ignore empty lines, how puzzling!

        // Handle indentation based on "<" and ">" symbols
        for (int i = 0; ptr[i]; i++) {
            // If we see the opening tag and it's not a self-closing one
            if (ptr[i] == '<' && ptr[i + 1] != '/') {
                fprintf(output, "%s", indent);
                for (int j = 0; j < indent_level; j++) fprintf(output, "%s", indent);
                fprintf(output, "%s\n", ptr);
                indent_level++; // Increase the level of mystery!
                break; // We'll be back!
            } else if (ptr[i] == '<' && ptr[i + 1] == '/') {
                indent_level--; // Backtracking on our journey
                for (int j = 0; j < indent_level; j++) fprintf(output, "%s", indent);
                fprintf(output, "%s\n", ptr);
                break; // Off we go to the next line
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Whoa there! You forgot the input and output file names!\n");
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE; // Oopsie-daisy!
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Couldn't open the input file, what a bummer!");
        return EXIT_FAILURE; // Plan B!
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Couldn't open the output file for writing, what a twist!");
        fclose(input_file);
        return EXIT_FAILURE; // !?
    }

    // Let's start the beautification magic!
    beautify_html(input_file, output_file);
    printf("🎉 HTML Beautification is complete! Check the output file! 🎉\n");

    // All good things must come to an end...
    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS; // Huzzah!
}