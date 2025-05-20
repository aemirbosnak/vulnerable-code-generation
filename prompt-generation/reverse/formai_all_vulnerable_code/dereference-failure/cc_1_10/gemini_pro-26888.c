//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: immersive
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
    html->lines = realloc(html->lines, (html->num_lines + 1) * sizeof(line_t));
    html->lines[html->num_lines].line = malloc(length + 1);
    strcpy(html->lines[html->num_lines].line, line);
    html->lines[html->num_lines].length = length;
    html->num_lines++;
    return 0;
}

char *html_beautify(html_t *html) {
    char *beautified = malloc(1);
    beautified[0] = '\0';
    for (int i = 0; i < html->num_lines; i++) {
        char *line = html->lines[i].line;
        int length = html->lines[i].length;
        int indent = 0;
        for (int j = 0; j < length; j++) {
            if (line[j] == '<') {
                indent++;
            } else if (line[j] == '>') {
                indent--;
            }
            for (int k = 0; k < indent; k++) {
                strcat(beautified, "  ");
            }
            strncat(beautified, line + j, 1);
        }
        strcat(beautified, "\n");
    }
    return beautified;
}

int main() {
    html_t *html = html_new();
    html_add_line(html, "<html>");
    html_add_line(html, "  <head>");
    html_add_line(html, "    <title>Hello World</title>");
    html_add_line(html, "  </head>");
    html_add_line(html, "  <body>");
    html_add_line(html, "    <h1>Hello World</h1>");
    html_add_line(html, "  </body>");
    html_add_line(html, "</html>");

    char *beautified = html_beautify(html);
    printf("%s", beautified);

    html_free(html);
    free(beautified);

    return 0;
}