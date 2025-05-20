//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char* input) {
    char* result = (char*)malloc(strlen(input) + 1);
    int i;
    int newLine = 0;
    int tabCount = 0;
    int lineCount = 0;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '\n') {
            lineCount++;
            newLine = 1;
        } else if (input[i] == '\t') {
            tabCount++;
        } else if (input[i] == '<') {
            if (newLine) {
                result[lineCount] = '\n';
                newLine = 0;
            }
            result[lineCount++] = '<';
            if (tabCount > 0) {
                result[lineCount] = '\t';
                tabCount--;
            }
        } else if (input[i] == '>') {
            if (newLine) {
                result[lineCount] = '\n';
                newLine = 0;
            }
            result[lineCount++] = '>';
            if (tabCount > 0) {
                result[lineCount] = '\t';
                tabCount--;
            }
        } else {
            if (newLine) {
                result[lineCount] = '\n';
                newLine = 0;
            }
            result[lineCount++] = input[i];
        }
    }
    result[lineCount] = '\0';

    printf("%s", result);

    free(result);
}

int main() {
    char* input = "<h1>Hello, world!</h1>";
    beautifyHTML(input);
    return 0;
}