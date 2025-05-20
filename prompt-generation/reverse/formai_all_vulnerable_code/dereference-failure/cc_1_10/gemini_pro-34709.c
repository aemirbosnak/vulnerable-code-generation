//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int line_length;
    int indent_level;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
    int max_line_length;
} document_t;

document_t *document_new() {
    document_t *document = malloc(sizeof(document_t));
    document->lines = NULL;
    document->num_lines = 0;
    document->max_line_length = 0;
    return document;
}

void document_free(document_t *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].line);
    }
    free(document->lines);
    free(document);
}

int document_add_line(document_t *document, char *line) {
    int line_length = strlen(line);
    if (line_length > MAX_LINE_LENGTH) {
        return -1;
    }

    line_t *new_line = malloc(sizeof(line_t));
    new_line->line = malloc(line_length + 1);
    strcpy(new_line->line, line);
    new_line->line_length = line_length;
    new_line->indent_level = 0;

    document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(line_t));
    document->lines[document->num_lines] = *new_line;
    document->num_lines++;

    if (line_length > document->max_line_length) {
        document->max_line_length = line_length;
    }

    return 0;
}

int document_beautify(document_t *document) {
    for (int i = 0; i < document->num_lines; i++) {
        line_t *line = &document->lines[i];
        int indent_level = 0;

        for (int j = 0; j < line->line_length; j++) {
            char c = line->line[j];
            if (c == ' ' || c == '\t') {
                indent_level++;
            } else {
                break;
            }
        }

        if (indent_level > 0) {
            line->indent_level = indent_level;
            line->line = realloc(line->line, line->line_length + indent_level + 1);
            memmove(line->line + indent_level, line->line, line->line_length + 1);
            memset(line->line, ' ', indent_level);
        }
    }

    return 0;
}

int document_print(document_t *document) {
    for (int i = 0; i < document->num_lines; i++) {
        line_t *line = &document->lines[i];
        printf("%s\n", line->line);
    }

    return 0;
}

int main() {
    document_t *document = document_new();
    document_add_line(document, "<!DOCTYPE html>");
    document_add_line(document, "<html>");
    document_add_line(document, "  <head>");
    document_add_line(document, "    <title>Hello, world!</title>");
    document_add_line(document, "  </head>");
    document_add_line(document, "  <body>");
    document_add_line(document, "    <h1>Hello, world!</h1>");
    document_add_line(document, "    <p>This is a paragraph.</p>");
    document_add_line(document, "  </body>");
    document_add_line(document, "</html>");

    document_beautify(document);
    document_print(document);

    document_free(document);

    return 0;
}