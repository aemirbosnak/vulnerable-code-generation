//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 10

typedef struct {
    char *text;
    int length;
    int indent_level;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
    int max_indent_level;
} document_t;

document_t *document_new() {
    document_t *document = malloc(sizeof(document_t));
    document->lines = malloc(sizeof(line_t));
    document->num_lines = 0;
    document->max_indent_level = 0;
    return document;
}

void document_free(document_t *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].text);
    }
    free(document->lines);
    free(document);
}

void document_add_line(document_t *document, char *text, int length, int indent_level) {
    document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(line_t));
    document->lines[document->num_lines].text = malloc(length + 1);
    memcpy(document->lines[document->num_lines].text, text, length);
    document->lines[document->num_lines].text[length] = '\0';
    document->lines[document->num_lines].length = length;
    document->lines[document->num_lines].indent_level = indent_level;
    document->num_lines++;
    if (indent_level > document->max_indent_level) {
        document->max_indent_level = indent_level;
    }
}

void document_print(document_t *document) {
    for (int i = 0; i < document->num_lines; i++) {
        for (int j = 0; j < document->lines[i].indent_level; j++) {
            printf("  ");
        }
        printf("%s\n", document->lines[i].text);
    }
}

int main() {
    document_t *document = document_new();

    char *html = "<html>\n"
                   "  <head>\n"
                   "    <title>Hello World</title>\n"
                   "  </head>\n"
                   "  <body>\n"
                   "    <h1>Hello World</h1>\n"
                   "    <p>This is a paragraph.</p>\n"
                   "  </body>\n"
                   "</html>";

    char *line;
    int line_length;
    int indent_level = 0;
    while ((line = strtok(html, "\n")) != NULL) {
        line_length = strlen(line);
        if (line[0] == '<') {
            if (line[1] == '/') {
                indent_level--;
            } else {
                indent_level++;
            }
        }
        document_add_line(document, line, line_length, indent_level);
        html = NULL;
    }

    document_print(document);

    document_free(document);

    return 0;
}