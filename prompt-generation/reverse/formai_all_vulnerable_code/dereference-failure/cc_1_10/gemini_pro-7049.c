//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 10

typedef struct {
    char *line;
    int length;
    int indent_level;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
    int max_line_length;
    int max_indent_level;
} html_document_t;

html_document_t *html_document_new() {
    html_document_t *doc = malloc(sizeof(html_document_t));
    if (!doc) {
        return NULL;
    }

    doc->lines = malloc(sizeof(line_t) * MAX_LINE_LENGTH);
    if (!doc->lines) {
        free(doc);
        return NULL;
    }

    doc->num_lines = 0;
    doc->max_line_length = 0;
    doc->max_indent_level = 0;

    return doc;
}

void html_document_free(html_document_t *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        free(doc->lines[i].line);
    }

    free(doc->lines);
    free(doc);
}

int html_document_add_line(html_document_t *doc, char *line, int length, int indent_level) {
    if (doc->num_lines >= MAX_LINE_LENGTH) {
        return -1;
    }

    if (length > MAX_LINE_LENGTH) {
        return -1;
    }

    if (indent_level > MAX_INDENT_LEVEL) {
        return -1;
    }

    doc->lines[doc->num_lines].line = malloc(length + 1);
    if (!doc->lines[doc->num_lines].line) {
        return -1;
    }

    memcpy(doc->lines[doc->num_lines].line, line, length);
    doc->lines[doc->num_lines].line[length] = '\0';
    doc->lines[doc->num_lines].length = length;
    doc->lines[doc->num_lines].indent_level = indent_level;

    if (length > doc->max_line_length) {
        doc->max_line_length = length;
    }

    if (indent_level > doc->max_indent_level) {
        doc->max_indent_level = indent_level;
    }

    doc->num_lines++;

    return 0;
}

int html_document_beautify(html_document_t *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        // Indent the line
        for (int j = 0; j < doc->lines[i].indent_level; j++) {
            printf("    ");
        }

        // Print the line
        printf("%s\n", doc->lines[i].line);
    }

    return 0;
}

int main() {
    html_document_t *doc = html_document_new();
    if (!doc) {
        return -1;
    }

    char *line = "<html>\n";
    int length = strlen(line);
    int indent_level = 0;
    if (html_document_add_line(doc, line, length, indent_level) < 0) {
        return -1;
    }

    line = "  <head>\n";
    length = strlen(line);
    indent_level = 1;
    if (html_document_add_line(doc, line, length, indent_level) < 0) {
        return -1;
    }

    line = "    <title>My Website</title>\n";
    length = strlen(line);
    indent_level = 2;
    if (html_document_add_line(doc, line, length, indent_level) < 0) {
        return -1;
    }

    line = "  </head>\n";
    length = strlen(line);
    indent_level = 1;
    if (html_document_add_line(doc, line, length, indent_level) < 0) {
        return -1;
    }

    line = "  <body>\n";
    length = strlen(line);
    indent_level = 1;
    if (html_document_add_line(doc, line, length, indent_level) < 0) {
        return -1;
    }

    line = "    <h1>Hello, world!</h1>\n";
    length = strlen(line);
    indent_level = 2;
    if (html_document_add_line(doc, line, length, indent_level) < 0) {
        return -1;
    }

    line = "  </body>\n";
    length = strlen(line);
    indent_level = 1;
    if (html_document_add_line(doc, line, length, indent_level) < 0) {
        return -1;
    }

    line = "</html>\n";
    length = strlen(line);
    indent_level = 0;
    if (html_document_add_line(doc, line, length, indent_level) < 0) {
        return -1;
    }

    html_document_beautify(doc);

    html_document_free(doc);

    return 0;
}