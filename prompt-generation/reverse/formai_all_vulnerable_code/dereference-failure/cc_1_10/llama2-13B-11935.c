//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 4

void html_beautify(char *input) {
    char *output = malloc(strlen(input) * 2 + 1);
    char *current_line = output;
    char *previous_line = output;
    char *indent_stack[MAX_INDENT];
    int indent_stack_size = 0;

    // Iterate through each line of the input string
    for (char *line = strtok(input, "\n"); line != NULL; line = strtok(NULL, "\n")) {
        // Check if the current line is empty
        if (strlen(line) == 0) {
            // If the current line is empty, add a newline character to the output
            *current_line = '\n';
            current_line++;
            continue;
        }

        // Add the current line to the output, indented according to the previous line's indentation
        for (int i = 0; i < indent_stack_size; i++) {
            *current_line++ = ' ';
        }

        // If the previous line is not empty, add a newline character to the output before the current line
        if (previous_line != NULL && strlen(previous_line) > 0) {
            *current_line++ = '\n';
        }

        // Add the current line to the output, without any indentation
        for (char *cur_char = line; *cur_char != '\0'; cur_char++) {
            *current_line++ = *cur_char;
        }

        // Push the current line onto the indent stack
        indent_stack[indent_stack_size++] = current_line;

        // Set the previous line to the current line
        previous_line = current_line;

        // Set the current line to the next line in the input string
        current_line = strtok(NULL, "\n");
    }

    // If there are any remaining lines in the input string, add them to the output
    for (char *line = strtok(NULL, "\n"); line != NULL; line = strtok(NULL, "\n")) {
        for (int i = 0; i < indent_stack_size; i++) {
            *current_line++ = ' ';
        }

        for (char *cur_char = line; *cur_char != '\0'; cur_char++) {
            *current_line++ = *cur_char;
        }
    }

    // Free the memory allocated for the output string
    free(output);
}

int main() {
    char input[] = "<html><body><p>This is a paragraph of text.</p><p>This is another paragraph of text.</p></body></html>";
    char output[1024];

    html_beautify(input);

    printf("%s\n", output);

    return 0;
}