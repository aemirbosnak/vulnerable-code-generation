//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 100

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in_fp = fopen(input_file, "r");
    FILE *out_fp = fopen(output_file, "w");
    if (!in_fp || !out_fp) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    const char *indent = "    "; // 4 spaces for indentation

    while (fgets(line, sizeof(line), in_fp)) {
        char *ptr = line; 
        while (*ptr) {
            // Ignore leading spaces
            if (isspace(*ptr)) {
                ptr++;
                continue;
            }
            // Handle opening tags
            if (*ptr == '<') {
                if (*(ptr + 1) == '/') { // Closing tag
                    indent_level--;
                }
                // Write current indent level
                for (int i = 0; i < indent_level; i++) {
                    fputs(indent, out_fp);
                }
                // Write opening tag
                while (*ptr && !isspace(*ptr) && *ptr != '>') {
                    fputc(*ptr, out_fp);
                    ptr++;
                }
                // Write closing '>'
                if (*ptr == '>') {
                    fputc(*ptr, out_fp);
                    ptr++;
                }
                // Handle indentation for closing tags
                if (*(ptr - 2) != '/' && (*(ptr - 1) != '>')) {
                    indent_level++;
                }
                fputc('\n', out_fp); // New line after tag
                break;
            } else {
                // Write normal text
                while (*ptr && *ptr != '<') {
                    fputc(*ptr, out_fp);
                    ptr++;
                }
                fputc('\n', out_fp); // New line after text
            }
        }
    }

    fclose(in_fp);
    fclose(out_fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);

    printf("HTML beautification completed successfully!\n");
    return EXIT_SUCCESS;
}