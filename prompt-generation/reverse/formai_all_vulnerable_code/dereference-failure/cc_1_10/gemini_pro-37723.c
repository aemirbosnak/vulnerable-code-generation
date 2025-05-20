//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NESTING_LEVEL 10

typedef struct {
    char *text;
    int length;
} line;

typedef struct {
    line *lines;
    int num_lines;
} html_document;

html_document *new_html_document() {
    html_document *doc = malloc(sizeof(html_document));
    doc->lines = NULL;
    doc->num_lines = 0;
    return doc;
}

void free_html_document(html_document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        free(doc->lines[i].text);
    }
    free(doc->lines);
    free(doc);
}

line *new_line(char *text, int length) {
    line *line = malloc(sizeof(line));
    line->text = malloc(length + 1);
    memcpy(line->text, text, length);
    line->text[length] = '\0';
    line->length = length;
    return line;
}

void free_line(line *line) {
    free(line->text);
    free(line);
}

void append_line(html_document *doc, char *text, int length) {
    doc->lines = realloc(doc->lines, (doc->num_lines + 1) * sizeof(line));
    doc->lines[doc->num_lines] = *new_line(text, length);
    doc->num_lines++;
}

void beautify_html(html_document *doc) {
    int nesting_level = 0;
    for (int i = 0; i < doc->num_lines; i++) {
        line *line = &doc->lines[i];
        if (line->length == 0) {
            continue;
        }
        if (line->text[0] == '<') {
            if (line->text[1] != '/') {
                nesting_level++;
            } else {
                nesting_level--;
            }
        }
        for (int j = 0; j < nesting_level; j++) {
            printf("    ");
        }
        printf("%s", line->text);
    }
}

int main() {
    html_document *doc = new_html_document();
    char *html = "<html><head><title>Hello, world!</title></head><body><h1>Hello, world!</h1></body></html>";
    append_line(doc, html, strlen(html));
    beautify_html(doc);
    free_html_document(doc);
    return 0;
}