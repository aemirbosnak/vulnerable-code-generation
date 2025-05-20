//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 4

void beautify(char *html) {
    char *token, *word, *next;
    int i, j, indent = 0;

    // Tokenize the HTML code
    for (i = 0; html[i] != '\0'; i++) {
        if (html[i] == '<') {
            // Find the end of the current tag
            token = html + i;
            while (*token != '>') {
                if (*token == '/') {
                    // Handle self-closing tag
                    break;
                }
                token++;
            }
            // Check if there is a closing tag
            if (*token == '>') {
                // Remove the current tag and its contents
                html = strcasestr(html, token) + 1;
                i = 0;
            } else {
                // Start a new tag
                indent += 2;
                html += 2;
            }
        } else if (html[i] == ' ' || html[i] == '\t') {
            // Check for whitespace
            if (indent > 0) {
                // Indent the current line
                for (j = 0; j < indent; j++) {
                    html += ' ';
                }
            }
        } else {
            // Check for end of tag
            if (html[i] == '>') {
                // Remove the current tag and its contents
                html = strcasestr(html, html + i) + 1;
                i = 0;
            }
        }
    }

    // Remove trailing whitespace
    while (html[strlen(html) - 1] == ' ') {
        html[strlen(html) - 1] = '\0';
    }

    // Pretty print the HTML code
    for (i = 0; html[i] != '\0'; i++) {
        if (html[i] == '<') {
            // Start a new tag
            word = html + i;
            next = strchr(word, '>');
            if (next) {
                *next = '>';
                indent += 2;
            }
            html = word;
        } else if (html[i] == '>') {
            // End of tag
            if (indent > 0) {
                // Dedent the current line
                for (j = 0; j < indent; j++) {
                    html -= ' ';
                }
                indent = 0;
            }
        } else {
            // Normal character
            html[i] = ' ';
        }
    }
}

int main() {
    char html[] = "<html><body>Hello World!</body></html>";
    beautify(html);
    printf("%s\n", html);
    return 0;
}