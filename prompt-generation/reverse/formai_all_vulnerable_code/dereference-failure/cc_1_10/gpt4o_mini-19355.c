//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENTATION_SIZE 4

void beautify_html(const char *input_html, FILE *output_file) {
    int indent_level = 0;
    char line[MAX_LINE_LENGTH];
    int in_tag = 0;
    
    // Read each line from the input HTML
    while (fgets(line, sizeof(line), input_html)) {
        char *pos = line;

        // Trim leading spaces
        while (*pos == ' ') {
            pos++;
        }

        // Modify indentation based on tags
        for (char *ptr = pos; *ptr; ptr++) {
            if (*ptr == '<') {
                in_tag = 1;
                // Check if it is a closing tag
                if (*(ptr + 1) == '/') {
                    indent_level--;
                }
                // Print indentation spaces
                for (int i = 0; i < indent_level * INDENTATION_SIZE; i++) {
                    fputc(' ', output_file);
                }
                fputs(ptr, output_file);
                break;
            }
            else if (in_tag && *ptr == '>') {
                in_tag = 0;
                // Check if it is an opening tag
                if (*(ptr - 1) != '/') {
                    indent_level++;
                }
            }
        }
    }
}

void display_usage() {
    printf("Welcome to the HTML Beautifier!\n");
    printf("Usage: ./html_beautifier <input_file> <output_file>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification complete! Check out your beautiful output in %s!\n", argv[2]);
    return EXIT_SUCCESS;
}