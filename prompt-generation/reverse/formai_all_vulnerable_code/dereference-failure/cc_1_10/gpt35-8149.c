//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Configurable style options
#define INDENTATION_CHAR '\t'
#define INDENTATION_SIZE 1
#define NEWLINE_CHAR '\n'

// Function to beautify the HTML
char* beautifyHtml(char* code) {
    int len = strlen(code);
    int indent = 0;
    char* result = malloc(len + MAX_LENGTH);

    for (int i = 0, j = 0; i < len;) {
        if (code[i] == '<') {
            if (code[i + 1] == '/') {
                indent -= INDENTATION_SIZE;
            }

            for (int k = 0; k < indent; k++) {
                result[j++] = INDENTATION_CHAR;
            }

            if (code[i + 1] != '?' && code[i + 1] != '!') {
                indent += INDENTATION_SIZE;
            }
        }

        result[j++] = code[i++];

        if (code[i - 1] == '>') {
            result[j++] = NEWLINE_CHAR;
        }
    }

    result[strlen(result) - 1] = '\0'; // Removing final new line

    return result;
}

int main() {
    char code[MAX_LENGTH];
    printf("Please enter your HTML code:\n");
    fgets(code, MAX_LENGTH, stdin);

    char* beautifiedCode = beautifyHtml(code);

    printf("Beautified code: \n%s", beautifiedCode);

    free(beautifiedCode);
    
    return 0;
}