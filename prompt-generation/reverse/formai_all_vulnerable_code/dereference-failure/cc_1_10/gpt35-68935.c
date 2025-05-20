//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scalable
/*
 * A simple HTML beautifier program written in C
 * 
 * Author: John Doe
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

char * beautify(char * html) {
    char * beautified = malloc(MAX_LINE_LENGTH * sizeof(char));
    char * indentation = malloc(MAX_LINE_LENGTH * sizeof(char));
    int indent = 0;
    int i = 0;

    while (*html != '\0') {
        if (*html == '<' && *(html+1) != '/') {
            for (int j = 0; j < indent; j++) {
                *(indentation+j) = '\t';
            }
            *(indentation+indent) = '\0';
            i += sprintf(beautified+i, "%s%s\n", indentation, html);
            indent++;
        } else if (*html == '<' && *(html+1) == '/') {
            indent--;
            for (int j = 0; j < indent; j++) {
                *(indentation+j) = '\t';
            }
            *(indentation+indent) = '\0';
            i += sprintf(beautified+i, "%s%s\n", indentation, html);
        } else {
            i += sprintf(beautified+i, "%c", *html);
        }
        html++;
    }

    *(beautified+i) = '\0';
    return beautified;
}

int main() {
    char * html = "<html><body><h1>Welcome to my website!</h1><p>This is a paragraph of text.</p></body></html>";
    char * beautified = beautify(html);

    printf("%s", beautified);

    free(beautified);
    return 0;
}