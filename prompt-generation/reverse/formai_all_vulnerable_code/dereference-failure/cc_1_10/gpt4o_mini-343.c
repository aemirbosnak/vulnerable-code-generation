//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENTATION "    "

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input_fp = fopen(input_file, "r");
    FILE *output_fp = fopen(output_file, "w");
    
    if (input_fp == NULL) {
        fprintf(stderr, "Could not open input file: %s\n", input_file);
        return;
    }

    if (output_fp == NULL) {
        fclose(input_fp);
        fprintf(stderr, "Could not open output file: %s\n", output_file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int in_tag = 0;

    while (fgets(line, sizeof(line), input_fp)) {
        char *ptr = line;
        while (*ptr) {
            // Check for opening tags
            if (*ptr == '<') {
                if (*(ptr + 1) != '/') {
                    // Opening tag
                    fprintf(output_fp, "%*s%s", indent_level * strlen(INDENTATION), "", ptr);
                    indent_level++;
                    in_tag = 1;
                } else {
                    // Closing tag
                    indent_level--;
                    fprintf(output_fp, "%*s%s", indent_level * strlen(INDENTATION), "", ptr);
                }
                break;
            } else if (*ptr == '\n') {
                // A new line should be written
                if (in_tag) {
                    fprintf(output_fp, "\n");
                    in_tag = 0;
                }
                break;  // Break to read a new line
            } else {
                fprintf(output_fp, "%c", *ptr);
            }

            ptr++;
        }
    }

    fclose(input_fp);
    fclose(output_fp);
    printf("HTML beautification completed. Output saved to: %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    return EXIT_SUCCESS;
}