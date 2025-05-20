//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void beautify_html(const char *input_file, const char *output_file) {
    FILE *infile = fopen(input_file, "r");
    FILE *outfile = fopen(output_file, "w");
    if (!infile || !outfile) {
        fprintf(stderr, "Error: Cannot open input or output file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    
    while (fgets(line, sizeof(line), infile)) {
        char *ptr = line;
        int is_tag = 0;

        // Trim leading spaces
        while (*ptr == ' ') {
            ptr++;
        }

        // Check for opening/closing tags
        if (*ptr == '<') {
            if (*(ptr + 1) == '/') {
                // Closing tag
                indent_level--;
            }

            // Write line with indentation
            fprintf(outfile, "%*s%s", indent_level * INDENT_SIZE, "", ptr);

            if (*(ptr + 1) != '/') {
                // Opening tag
                indent_level++;
            }
        } else {
            // Non-tag line
            fprintf(outfile, "%*s%s", indent_level * INDENT_SIZE, "", ptr);
        }
    }

    fclose(infile);
    fclose(outfile);
}

void display_usage() {
    printf("HTML Beautifier - A Futuristic Code Styler v1.0\n");
    printf("Usage: html_beautifier <input HTML file> <output HTML file>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return 1;
    }

    beautify_html(argv[1], argv[2]);
    
    printf("HTML beautification complete! Output saved to '%s'.\n", argv[2]);
    
    return 0;
}