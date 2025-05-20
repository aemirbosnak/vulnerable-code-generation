//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH    1024
#define MAX_NESTING_DEPTH 10

typedef struct {
    char *start;
    char *end;
    int nesting_depth;
} html_tag_t;

char *html_beautify(char *input) {
    char *output = malloc(2 * strlen(input) + 1);

    int input_index = 0;
    int output_index = 0;

    html_tag_t tag_stack[MAX_NESTING_DEPTH];
    int tag_stack_index = 0;

    while (input[input_index] != '\0') {
        if (input[input_index] == '<') {
            // Start of a tag
            tag_stack[tag_stack_index].start = &input[input_index];
            tag_stack[tag_stack_index].nesting_depth = tag_stack_index;
            tag_stack_index++;

            // Copy the tag to the output
            while (input[input_index] != '>' && input[input_index] != '\0') {
                output[output_index++] = input[input_index++];
            }

            // End of the tag
            tag_stack[tag_stack_index - 1].end = &input[input_index];

            // Copy the greater-than sign to the output
            output[output_index++] = input[input_index++];
        } else if (input[input_index] == ' ') {
            // Whitespace
            output[output_index++] = input[input_index++];
        } else {
            // Text
            // Indent the text according to the nesting depth
            for (int i = 0; i < tag_stack[tag_stack_index - 1].nesting_depth; i++) {
                output[output_index++] = '\t';
            }

            // Copy the text to the output
            while (input[input_index] != '<' && input[input_index] != '\0') {
                output[output_index++] = input[input_index++];
            }
        }
    }

    output[output_index] = '\0';

    return output;
}

int main(void) {
    // Read the input HTML from stdin
    char *input = NULL;
    size_t input_length = 0;
    getline(&input, &input_length, stdin);

    // Beautify the HTML
    char *output = html_beautify(input);

    // Print the beautified HTML to stdout
    printf("%s", output);

    // Free the allocated memory
    free(input);
    free(output);

    return 0;
}