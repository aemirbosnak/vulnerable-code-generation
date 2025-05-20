//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A happy little function to beautify HTML.
char *html_beautify(char *html) {
    // Allocate a buffer for the beautified HTML.
    char *beautified_html = malloc(strlen(html) * 2);

    // Initialize the buffer with the original HTML.
    strcpy(beautified_html, html);

    // Replace all newlines with spaces.
    for (char *p = beautified_html; *p != '\0'; p++) {
        if (*p == '\n') {
            *p = ' ';
        }
    }

    // Replace all tabs with four spaces.
    for (char *p = beautified_html; *p != '\0'; p++) {
        if (*p == '\t') {
            *p = ' ';
            *(p + 1) = ' ';
            *(p + 2) = ' ';
            *(p + 3) = ' ';
        }
    }

    // Indent the HTML.
    int indent_level = 0;
    for (char *p = beautified_html; *p != '\0'; p++) {
        if (*p == '<') {
            indent_level++;
        } else if (*p == '>') {
            indent_level--;
        } else {
            for (int i = 0; i < indent_level; i++) {
                *p++ = ' ';
            }
            p--;
        }
    }

    // Return the beautified HTML.
    return beautified_html;
}

// A happy little main function.
int main(int argc, char **argv) {
    // Get the HTML from the command line.
    char *html = argv[1];

    // Beautify the HTML.
    char *beautified_html = html_beautify(html);

    // Print the beautified HTML.
    printf("%s", beautified_html);

    // Free the beautified HTML.
    free(beautified_html);

    return 0;
}