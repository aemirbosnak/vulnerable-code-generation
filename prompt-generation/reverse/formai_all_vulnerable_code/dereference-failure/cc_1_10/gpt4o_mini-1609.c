//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

void beautify_html(char *input, char *output) {
    FILE *f_input = fopen(input, "r");
    FILE *f_output = fopen(output, "w");
    if (!f_input || !f_output) {
        printf("Error opening files!\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int indent = 0;
    bool in_tag = false;
    bool is_closing_tag = false;

    while (fgets(line, sizeof(line), f_input)) {
        char *ptr = line;
        while (*ptr) {
            if (*ptr == '<') {
                if (*(ptr + 1) == '/') {
                    is_closing_tag = true;
                    ptr++;
                }
                while (*ptr && *ptr != '>') {
                    in_tag = true;
                    ptr++;
                }
                if (is_closing_tag) {
                    indent--;
                    is_closing_tag = false;
                }
                if (in_tag) {
                    // Write new line and indent
                    fprintf(f_output, "\n%*s", indent * 4, "");
                    in_tag = false;
                }
                // Write the '<' and the tag itself
                fprintf(f_output, "<");
            } else if (*ptr == '>') {
                fprintf(f_output, ">");
                if (!is_closing_tag && *(ptr - 1) != '/') {
                    indent++;
                }
            } else {
                fprintf(f_output, "%c", *ptr);
            }
            ptr++;
        }
        // For pretty printing HTML, finished processing line includes new line
        fprintf(f_output, "\n");
    }

    fclose(f_input);
    fclose(f_output);
}

void display_usage() {
    printf("HTML Beautifier: Usage\n");
    printf("Run the program with input and output file as parameters.\n");
    printf("Example: ./html_beautifier input.html output.html\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return 1;
    }

    beautify_html(argv[1], argv[2]);
    
    printf("Successfully beautified HTML from '%s' to '%s'.\n", argv[1], argv[2]);
    return 0;
}