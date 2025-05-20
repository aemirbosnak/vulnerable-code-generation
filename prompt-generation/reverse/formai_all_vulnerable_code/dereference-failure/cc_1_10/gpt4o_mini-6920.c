//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define TAB_SIZE 4

void indent(FILE *input, FILE *output, int tab_count) {
    for (int i = 0; i < tab_count; i++) {
        fprintf(output, "%*s", TAB_SIZE, " "); // Add spaces for a tab
    }
}

void beautify_html(const char *filename) {
    FILE *input = fopen(filename, "r");
    if (!input) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen("beautified_output.html", "w");
    if (!output) {
        fprintf(stderr, "Error creating output file\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int tab_count = 0;
    int in_script_style = 0;

    while (fgets(line, sizeof(line), input)) {
        // Trim any leading/trailing whitespace and detect tags
        char *trimmed_line = strtok(line, "\n");
        
        if (strstr(trimmed_line, "</script>") || strstr(trimmed_line, "</style>")) {
            tab_count--; // decrease the indent level before closing tags
        }

        // Indent the line
        indent(input, output, tab_count);
        fprintf(output, "%s\n", trimmed_line);

        // Check for opening tags
        if (strstr(trimmed_line, "<script") || strstr(trimmed_line, "<style")) {
            in_script_style = 1;
        }
        
        // Check for closing tags
        if (strstr(trimmed_line, "</script>") || strstr(trimmed_line, "</style>")) {
            in_script_style = 0;
        }

        // Check for self-closing tags
        if (strstr(trimmed_line, "<tag") && !strstr(trimmed_line, "</")) {
            tab_count++; // increase the indent level after opening non-self-closing tags
        }

        // Increase indent for standard opening tags
        if (!in_script_style && (strstr(trimmed_line, "<") && !strstr(trimmed_line, "/>"))) {
            if (!strstr(trimmed_line, "</")) {
                // If it's not a closing tag, we can potentially add indentation.
                char *next_tag = strchr(trimmed_line, '>');
                if (next_tag) {
                    if (*(next_tag + 1) != '<') {
                        tab_count++;
                    }
                }
            }
        }

        // Adjust indentation for lines with only closing tags
        if (strstr(trimmed_line, "</")) {
            if (!in_script_style) {
                tab_count--; // decrease the indent level again before closing tags
            }
        }
    }

    fclose(input);
    fclose(output);
    printf("HTML beautification complete. Output written to beautified_output.html\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    beautify_html(argv[1]);
    return 0;
}