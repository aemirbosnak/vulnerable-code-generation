//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define INDENT_SIZE 4

void html_beautify(char *input) {
    char *output = malloc(strlen(input) * 2);
    char *cur_line = output;
    char *prev_line = NULL;
    int indent = 0;

    // Iterate through each line of the input
    for (char *line = strtok(input, "\n"); line != NULL; line = strtok(NULL, "\n")) {
        // Check if the line is a empty line or a comment
        if (strlen(line) == 0 || line[0] == '/' && line[1] == '/') {
            continue;
        }

        // Count the number of spaces in the line
        int spaces = count_spaces(line);

        // Check if the line is indented
        if (spaces > indent) {
            // Indent the line
            for (int i = 0; i < (spaces - indent); i++) {
                *cur_line++ = ' ';
            }
        }

        // Add the line to the output
        strcpy(cur_line, line);
        cur_line += strlen(line);

        // Update the indent
        indent = spaces;

        // Check if the line is the last one
        if (prev_line == NULL) {
            // Add a newline character to the output
            *cur_line++ = '\n';
        }

        // Update the previous line
        prev_line = line;
    }

    // Add the last line to the output
    if (prev_line != NULL) {
        strcpy(cur_line, prev_line);
        cur_line += strlen(prev_line);
    }

    // Trim the output
    output[cur_line - output] = '\0';

    // Print the output
    printf("%s\n", output);

    free(output);
}

// Helper function to count the number of spaces in a line
int count_spaces(char *line) {
    int spaces = 0;

    for (char *cur = line; *cur != '\0'; cur++) {
        if (*cur == ' ') {
            spaces++;
        }
    }

    return spaces;
}

int main() {
    char input[] = "<html><body><p>This is a paragraph of text.</p><p>This is another paragraph of text.</p></body></html>";
    html_beautify(input);
    return 0;
}