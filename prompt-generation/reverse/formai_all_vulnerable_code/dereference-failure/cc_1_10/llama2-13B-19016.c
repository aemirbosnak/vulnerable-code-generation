//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 2048
#define MAX_INDENT 8

void html_beautify(char *input) {
    char *output = malloc(strlen(input) * 2 + 1);
    char *line = output;
    char *indent = "";
    int level = 0;

    // Iterate through each line of the input string
    for (char *p = input; *p != '\0'; p++) {
        if (*p == '<') {
            // If we encounter an opening tag, increase the indent level
            level++;
            *line++ = '\n';
            for (int i = 0; i < level * MAX_INDENT; i++) {
                *line++ = indent;
            }
        } else if (*p == '>') {
            // If we encounter a closing tag, decrease the indent level
            level--;
            for (int i = 0; i < level * MAX_INDENT; i++) {
                *line++ = indent;
            }
        } else if (*p == ' ' || *p == '\t') {
            // If we encounter a space or tab character, skip it
            continue;
        } else {
            // If we encounter any other character, add it to the output
            *line++ = *p;
        }
    }

    // Add a final newline character to the output
    *line++ = '\n';

    // Copy the output to the input string
    strcpy(input, output);
}

int main() {
    char input[] = "<html><body>Hello World!</body></html>";
    html_beautify(input);
    printf("%s\n", input);
    return 0;
}