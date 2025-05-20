//FormAI DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

char * beautify(char * html) {
    char * beautified = malloc(strlen(html) + strlen("<br>") + 1);
    int indent_level = 0;
    int beautified_idx = 0;

    for (int i = 0; i < strlen(html); i++) {
        if (html[i] == '<' && html[i+1] != '/') {
            beautified[beautified_idx++] = '\n';
            for (int j = 0; j < indent_level; j++) {
                for (int k = 0; k < TAB_SIZE; k++) {
                    beautified[beautified_idx++] = ' ';
                }
            }
        }
        if (html[i] == '<') {
            indent_level++;
        }
        if (html[i] == '>' && html[i-1] == '/') {
            beautified[beautified_idx++] = '\n';
            for (int j = 0; j < indent_level - 1; j++) {
                for (int k = 0; k < TAB_SIZE; k++) {
                    beautified[beautified_idx++] = ' ';
                }
            }
        }
        if (html[i] == '>') {
            beautified[beautified_idx++] = '\n';
            for (int j = 0; j < indent_level - 1; j++) {
                for (int k = 0; k < TAB_SIZE; k++) {
                    beautified[beautified_idx++] = ' ';
                }
            }
        }
        beautified[beautified_idx++] = html[i];
        if (html[i] == '/' && html[i-1] == '<') {
            indent_level--;
        }
    }

    beautified[beautified_idx] = '\0';
    strcat(beautified, "<br>");
    return beautified;
}

int main() {
    char * html = "<html><body><h1>Hello, world!</h1><p>Testing 1 2 3</p></body></html>";
    char * beautified_html = beautify(html);

    printf("%s\n", beautified_html);
    free(beautified_html);

    return 0;
}