//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100000

char* beautify_html(char* input) {
    char* output = malloc(MAX_INPUT_SIZE);
    int i = 0, j = 0;

    while (input[i]) {
        if (input[i] == '<') {
            strcat(output, "&lt;");
            i++;
        } else if (input[i] == '>') {
            strcat(output, "&gt;");
            i++;
        } else if (input[i] == '&') {
            strcat(output, "&amp;");
            i++;
        } else if (input[i] == '"') {
            strcat(output, "&quot;");
            i++;
        } else if (input[i] == '\'') {
            strcat(output, "&apos;");
            i++;
        } else {
            output[j++] = input[i++];
        }
    }

    output[j] = '\0';
    return output;
}

int main() {
    char* input = malloc(MAX_INPUT_SIZE);

    printf("Enter the HTML code:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    char* output = beautify_html(input);

    printf("Beautified HTML:\n%s\n", output);

    free(input);
    free(output);

    return 0;
}