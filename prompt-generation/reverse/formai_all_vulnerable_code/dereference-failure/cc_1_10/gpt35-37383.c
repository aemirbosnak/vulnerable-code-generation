//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define INDENT_SPACES 4

char* beautify(const char* input) {
    size_t input_len = strlen(input);

    char* output = calloc(input_len + 1, sizeof(char));
    size_t output_len = 0;

    int indent = 0;
    bool in_tag = false;
    bool in_attr = false;

    int i = 0;
    while (i < input_len) {
        char c = input[i];

        if (c == '<') {
            in_tag = true;
            output[output_len++] = c;

            if (input[i+1] == '/') {
                indent -= INDENT_SPACES;
                for(int j=0; j<indent; j++) {
                    output[output_len++] = ' ';
                }
            } else {
                for(int j=0; j<indent; j++) {
                    output[output_len++] = ' ';
                }
                indent += INDENT_SPACES;
            }
        } else if (c == '>') {
            in_tag = false;
            in_attr = false;
            output[output_len++] = c;
        } else if (c == '"' || c == '\'') {
            in_attr = !in_attr;
            output[output_len++] = c;
        } else if (!in_attr && !in_tag && isspace(c)) {
            // ignore white space outside of tags and quotes
        } else {
            output[output_len++] = c;
        }

        i++;
    }

    return output;
}

int main(void) {
    const char* input = "<html>  <head><title>Test</title></head>\n\t<body><p>Some text.</p></body></html>";

    char* output = beautify(input);

    printf("%s", output);

    free(output);

    return 0;
}