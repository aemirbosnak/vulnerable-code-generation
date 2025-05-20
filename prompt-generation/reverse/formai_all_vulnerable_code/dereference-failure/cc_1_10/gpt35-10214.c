//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4 // tab size in spaces

int get_space_count(int level) {
    // calculate the required space count for given indentation level
    return TAB_SIZE * level;
}

char* beautify_html(const char* input) {
    int input_length = strlen(input);
    int output_length = input_length;
    int indentation_level = 0;
    char* output = (char*) malloc(output_length + 1); // allocate memory for output string
    memset(output, 0, output_length + 1); // clear output string

    int i = 0;
    while (i < input_length) {
        if (input[i] == '<') {
            if (input[i+1] == '/') {
                // closing tag
                indentation_level--;
            }

            int space_count = get_space_count(indentation_level);
            for (int j = 0; j < space_count; j++) {
                output[strlen(output)] = ' '; // add indentation spaces
            }

            memcpy(&output[strlen(output)], &input[i], strlen(&input[i]));
            i += strlen(&input[i]);

            if (input[i-2] != '/') {
                // not a self-closing tag
                output[strlen(output)] = '\n'; // add newline after opening tag
                indentation_level++;
            }
        } else {
            // ordinary text
            memcpy(&output[strlen(output)], &input[i], 1);
            i++;
        }
    }

    return output;
}

int main() {
    const char* input = "<html><head><title>Example</title></head><body><h1>Hello World!</h1><p>This is an example HTML document.</p></body></html>";

    char* output = beautify_html(input);
    printf("%s", output);

    free(output);
    return 0;
}