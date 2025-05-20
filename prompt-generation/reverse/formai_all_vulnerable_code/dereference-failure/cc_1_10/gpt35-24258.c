//FormAI DATASET v1.0 Category: HTML beautifier ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 10000

/*
 * Function to beautify HTML code
 */
char* beautify_html(char* code) {
    char* buffer = (char*)malloc(MAX_BUFFER_SIZE);
    int indent_size = 4, indent = 0;
    int i, j;

    for (i = 0, j = 0; code[i] != '\0'; i++) {
        if (code[i] == '<') {
            if (code[i + 1] == '/') {
                indent -= indent_size;
            }

            for (int k = 0; k < indent; k++) {
                buffer[j++] = ' ';
            }

            if (code[i + 1] != '!') {
                indent += indent_size;
            }
        }

        buffer[j++] = code[i];

        if (code[i] == '>') {
            buffer[j++] = '\n';
        }
    }

    buffer[j] = '\0';

    return buffer;
}

int main() {
    char* code = "<html><head><title>My HTML Page</title></head><body><h1>Hello World!</h1><p>This is my HTML page.</p></body></html>";

    char* beautified_code = beautify_html(code);

    printf("%s", beautified_code);

    free(beautified_code);

    return 0;
}