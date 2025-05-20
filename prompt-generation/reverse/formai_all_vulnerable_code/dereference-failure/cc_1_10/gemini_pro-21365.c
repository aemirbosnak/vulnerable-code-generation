//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our cheerful beautifier!

void beautify(char *html) {
    // Split the HTML into lines.
    char **lines = malloc(sizeof(char *) * 100);
    int num_lines = 0;
    char *line = strtok(html, "\n");
    while (line) {
        lines[num_lines++] = strdup(line);
        line = strtok(NULL, "\n");
    }

    // Indent each line.
    int indent_level = 0;
    for (int i = 0; i < num_lines; i++) {
        // Count the number of leading spaces.
        int num_spaces = 0;
        char *c = lines[i];
        while (*c == ' ') {
            num_spaces++;
            c++;
        }

        // Calculate the new indent level.
        int new_indent_level = num_spaces / 2;

        // Add the correct number of indents.
        if (new_indent_level > indent_level) {
            for (int j = indent_level; j < new_indent_level; j++) {
                printf("  ");
            }
        } else if (new_indent_level < indent_level) {
            for (int j = indent_level; j > new_indent_level; j--) {
                printf("  ");
            }
        }

        // Print the line.
        printf("%s\n", lines[i]);

        // Update the indent level.
        indent_level = new_indent_level;
    }

    // Free the memory we allocated.
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main() {
    // Read the HTML from stdin.
    char *html = malloc(10000);
    int len = fread(html, 1, 10000, stdin);

    // Beautify the HTML.
    beautify(html);

    // Free the memory we allocated.
    free(html);

    return 0;
}