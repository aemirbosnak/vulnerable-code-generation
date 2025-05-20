//FormAI DATASET v1.0 Category: HTML beautifier ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char* html) {
    char* beautified = malloc(strlen(html) * 2);
    int indent_level = 0;
    int cursor = 0;
    int i;

    for (i = 0; i < strlen(html); i++) {
        if (html[i] == '<') {
            beautified[cursor] = '\n';
            cursor++;
            int j;
            for (j = 0; j < indent_level; j++) {
                beautified[cursor] = '\t';
                cursor++;
            }
            beautified[cursor] = '<';
            cursor++;
            beautified[cursor] = '\n';
            cursor++;
            indent_level++;
        } else if (html[i] == '>') {
            beautified[cursor] = '\n';
            cursor++;
            indent_level--;
            int j;
            for (j = 0; j < indent_level; j++) {
                beautified[cursor] = '\t';
                cursor++;
            }
            beautified[cursor] = '>';
            cursor++;
        } else {
            beautified[cursor] = html[i];
            cursor++;
        }
    }
    beautified[cursor] = '\0';
    free(html);
    printf("%s", beautified);
}

int main() {
    char* html = "<html><head><title>My Awesome Website</title><meta charset=\"UTF-8\"></head><body><h1>Welcome!</h1><p>This is my awesome website.</p></body></html>";
    beautify(html);
    return 0;
}