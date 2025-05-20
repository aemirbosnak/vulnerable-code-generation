//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: authentic
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
    html->lines = NULL;
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

int html_add_line(html_t *html, char *line) {
    int length = strlen(line);
    if (length > MAX_LINE_LENGTH) {
        return -1;
    }
    line_t *new_line = malloc(sizeof(line_t));
    new_line->line = malloc(length + 1);
    strcpy(new_line->line, line);
    new_line->length = length;
    html->lines = realloc(html->lines, (html->num_lines + 1) * sizeof(line_t));
    html->lines[html->num_lines] = *new_line;
    html->num_lines++;
    return 0;
}

char *html_beautify(html_t *html) {
    char *beautified_html = malloc(MAX_LINE_LENGTH * html->num_lines);
    int index = 0;
    for (int i = 0; i < html->num_lines; i++) {
        line_t line = html->lines[i];
        for (int j = 0; j < line.length; j++) {
            char c = line.line[j];
            if (c == '<') {
                beautified_html[index++] = c;
                beautified_html[index++] = '\n';
                beautified_html[index++] = '\t';
            } else if (c == '>') {
                beautified_html[index++] = '\n';
            } else {
                beautified_html[index++] = c;
            }
        }
        beautified_html[index++] = '\n';
    }
    beautified_html[index] = '\0';
    return beautified_html;
}

int main() {
    html_t *html = html_new();
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, stdin)) != -1) {
        html_add_line(html, line);
    }
    free(line);
    char *beautified_html = html_beautify(html);
    printf("%s", beautified_html);
    free(beautified_html);
    html_free(html);
    return 0;
}