//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *line;
    int len;
    int indent_level;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
} html_t;

html_t *html_new() {
    html_t *html = malloc(sizeof(html_t));
    html->lines = malloc(sizeof(line_t) * 10);
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

void html_add_line(html_t *html, char *line, int indent_level) {
    if (html->num_lines == 10) {
        html->lines = realloc(html->lines, sizeof(line_t) * (html->num_lines + 10));
    }
    line_t *new_line = &html->lines[html->num_lines++];
    new_line->line = strdup(line);
    new_line->len = strlen(line);
    new_line->indent_level = indent_level;
}

void html_print(html_t *html) {
    for (int i = 0; i < html->num_lines; i++) {
        line_t *line = &html->lines[i];
        for (int j = 0; j < line->indent_level; j++) {
            printf(" ");
        }
        printf("%s\n", line->line);
    }
}

int main() {
    html_t *html = html_new();
    html_add_line(html, "<html>", 0);
    html_add_line(html, "<head>", 1);
    html_add_line(html, "<title>My Page</title>", 2);
    html_add_line(html, "</head>", 1);
    html_add_line(html, "<body>", 1);
    html_add_line(html, "<h1>Hello World!</h1>", 2);
    html_add_line(html, "<p>This is my page.</p>", 2);
    html_add_line(html, "</body>", 1);
    html_add_line(html, "</html>", 0);
    html_print(html);
    html_free(html);
    return 0;
}