//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int length;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
} html_t;

html_t *html_new() {
    html_t *html = malloc(sizeof(html_t));
    html->lines = malloc(sizeof(line_t) * 100);
    html->num_lines = 0;
    return html;
}

void html_free(html_t *html) {
    for (int i = 0; i < html->num_lines; i++) {
        free(html->lines[i].line);
    }
    free(html->lines);
    free(html);
}

void html_add_line(html_t *html, char *line) {
    if (html->num_lines >= 100) {
        html->lines = realloc(html->lines, sizeof(line_t) * (html->num_lines + 100));
    }
    html->lines[html->num_lines].line = strdup(line);
    html->lines[html->num_lines].length = strlen(line);
    html->num_lines++;
}

char *html_beautify(html_t *html) {
    char *beautified = malloc(MAX_LINE_LENGTH * html->num_lines);
    int offset = 0;
    for (int i = 0; i < html->num_lines; i++) {
        line_t *line = &html->lines[i];
        for (int j = 0; j < line->length; j++) {
            char c = line->line[j];
            if (c == '<') {
                beautified[offset++] = '&';
                beautified[offset++] = 'l';
                beautified[offset++] = 't';
                beautified[offset++] = ';';
            } else if (c == '>') {
                beautified[offset++] = '&';
                beautified[offset++] = 'g';
                beautified[offset++] = 't';
                beautified[offset++] = ';';
            } else {
                beautified[offset++] = c;
            }
        }
        beautified[offset++] = '\n';
    }
    beautified[offset] = '\0';
    return beautified;
}

int main() {
    html_t *html = html_new();
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        html_add_line(html, line);
    }
    char *beautified = html_beautify(html);
    printf("%s", beautified);
    free(beautified);
    html_free(html);
    return 0;
}