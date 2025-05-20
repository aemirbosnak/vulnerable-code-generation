//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 5
#define INDENT_SIZE 4

void recurse_beautify(char *html, int depth);
void print_beautified_html(char *html);

int main() {
    char *html = "<html><body>Hello World!</body></html>";
    recurse_beautify(html, 0);
    return 0;
}

void recurse_beautify(char *html, int depth) {
    int i, j;
    char *token;
    char indentation[INDENT_SIZE];

    if (depth == MAX_DEPTH) {
        printf("HTML code is too deep. Max depth reached.\n");
        return;
    }

    // Check if the current token is a tag
    if ((token = strtok(html, "</")) == NULL) {
        // If it's not a tag, just print it as is
        printf("%s", html);
        return;
    }

    // Get the indentation for the current tag
    for (i = 0; i < depth; i++) {
        indentation[i] = ' ';
    }

    // Print the indentation
    for (i = 0; i < INDENT_SIZE; i++) {
        printf("%c", indentation[i]);
    }

    // Print the tag name
    printf("%s", token);

    // Recursively beautify the contents of the tag
    for (j = 0; (token = strtok(NULL, "</")) != NULL; j++) {
        if (j == 0) {
            // If the first token is not a tag, just print it as is
            printf("%s", token);
        } else {
            // Recursively beautify the contents of the tag
            recurse_beautify(token, depth + 1);
        }
    }

    // Print the closing tag
    for (i = 0; i < INDENT_SIZE; i++) {
        printf("%c", indentation[i]);
    }
    printf("</%s>", token);
}

void print_beautified_html(char *html) {
    recurse_beautify(html, 0);
}