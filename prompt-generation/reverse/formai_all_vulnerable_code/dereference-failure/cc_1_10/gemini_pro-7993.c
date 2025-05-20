//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
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
    html->lines = realloc(html->lines, (html->num_lines + 1) * sizeof(line_t));
    html->lines[html->num_lines].line = strdup(line);
    html->lines[html->num_lines].length = strlen(line);
    html->num_lines++;
    return 0;
}

char *html_to_string(html_t *html) {
    char *str = malloc(MAX_LINE_LENGTH * html->num_lines);
    int offset = 0;
    for (int i = 0; i < html->num_lines; i++) {
        memcpy(str + offset, html->lines[i].line, html->lines[i].length);
        offset += html->lines[i].length;
    }
    return str;
}

int main() {
    html_t *html = html_new();
    html_add_line(html, "<html>");
    html_add_line(html, "  <head>");
    html_add_line(html, "    <title>HTML Beautifier</title>");
    html_add_line(html, "  </head>");
    html_add_line(html, "  <body>");
    html_add_line(html, "    <h1>HTML Beautifier</h1>");
    html_add_line(html, "    <p>This is an example of an HTML beautifier.</p>");
    html_add_line(html, "  </body>");
    html_add_line(html, "</html>");
    char *str = html_to_string(html);
    printf("%s", str);
    free(str);
    html_free(html);
    return 0;
}