//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SPACES 4

void beautify_html(const char *input, const char *output) {
    FILE *in_file = fopen(input, "r");
    FILE *out_file = fopen(output, "w");
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    if (!in_file || !out_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), in_file)) {
        int i = 0;
        while (line[i]) {
            // Check for closing tags
            if (strstr(&line[i], "</") == &line[i]) {
                indent_level--;
                break;
            }
            // Check for opening tags
            if (strstr(&line[i], "<") == &line[i]) {
                if (line[i + 1] != '/') {
                    break; // Is an opening tag
                }
            }
            i++;
        }

        // Write indentations
        for (int j = 0; j < indent_level; j++) {
            fprintf(out_file, "%*s", INDENT_SPACES, " ");
        }

        fputs(line, out_file);

        // Adjust indent level after writing the line
        if (strstr(line, "<") && !strstr(line, "/>") && !strstr(line, "</")) {
            indent_level++;
        }
    }

    fclose(in_file);
    fclose(out_file);
}

void display_usage() {
    printf("Usage: html_beautifier <input_file.html> <output_file.html>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);

    printf("HTML beautification completed: %s -> %s\n", argv[1], argv[2]);
    return EXIT_SUCCESS;
}