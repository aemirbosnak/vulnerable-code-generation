//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: artistic
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

void html_add_line(html_t *html, char *line) {
    html->lines = realloc(html->lines, (html->num_lines + 1) * sizeof(line_t));
    html->lines[html->num_lines].line = strdup(line);
    html->lines[html->num_lines].length = strlen(line);
    html->num_lines++;
}

char *html_beautify(html_t *html) {
    char *output = malloc(MAX_LINE_LENGTH * html->num_lines);
    int output_length = 0;
    for (int i = 0; i < html->num_lines; i++) {
        char *line = html->lines[i].line;
        int line_length = html->lines[i].length;
        int indent_level = 0;
        for (int j = 0; j < line_length; j++) {
            char c = line[j];
            if (c == '<') {
                indent_level++;
            } else if (c == '>') {
                indent_level--;
            }
            for (int k = 0; k < indent_level; k++) {
                output[output_length++] = ' ';
            }
            output[output_length++] = c;
        }
        output[output_length++] = '\n';
    }
    output[output_length] = '\0';
    return output;
}

int main() {
    html_t *html = html_new();
    html_add_line(html, "<html>");
    html_add_line(html, "  <head>");
    html_add_line(html, "    <title>Hello, world!</title>");
    html_add_line(html, "  </head>");
    html_add_line(html, "  <body>");
    html_add_line(html, "    <h1>Hello, world!</h1>");
    html_add_line(html, "  </body>");
    html_add_line(html, "</html>");
    char *output = html_beautify(html);
    printf("%s", output);
    html_free(html);
    free(output);
    return 0;
}