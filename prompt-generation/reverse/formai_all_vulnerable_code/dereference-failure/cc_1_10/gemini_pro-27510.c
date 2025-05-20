//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int line_length;
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
    html->lines[html->num_lines].line_length = strlen(line);
    html->num_lines++;
}

void html_beautify(html_t *html) {
    for (int i = 0; i < html->num_lines; i++) {
        line_t *line = &html->lines[i];

        // Remove leading and trailing whitespace
        while (line->line_length > 0 && isspace(line->line[line->line_length - 1])) {
            line->line[line->line_length - 1] = '\0';
            line->line_length--;
        }
        while (line->line_length > 0 && isspace(line->line[0])) {
            line->line = &line->line[1];
            line->line_length--;
        }

        // Indent lines
        for (int j = 0; j < line->line_length; j++) {
            if (line->line[j] == '<') {
                line->line = realloc(line->line, (line->line_length + 2) * sizeof(char));
                memmove(&line->line[j + 2], &line->line[j], (line->line_length - j) * sizeof(char));
                line->line[j] = '\n';
                line->line[j + 1] = '\t';
                line->line_length += 2;
                j += 2;
            }
        }

        // Add newline at the end of the line
        line->line = realloc(line->line, (line->line_length + 2) * sizeof(char));
        line->line[line->line_length] = '\n';
        line->line[line->line_length + 1] = '\0';
        line->line_length++;
    }
}

void html_print(html_t *html) {
    for (int i = 0; i < html->num_lines; i++) {
        printf("%s", html->lines[i].line);
    }
}

int main() {
    html_t *html = html_new();
    html_add_line(html, "<html>");
    html_add_line(html, "<head>");
    html_add_line(html, "<title>My Website</title>");
    html_add_line(html, "</head>");
    html_add_line(html, "<body>");
    html_add_line(html, "<h1>Hello, world!</h1>");
    html_add_line(html, "</body>");
    html_add_line(html, "</html>");
    html_beautify(html);
    html_print(html);
    html_free(html);
    return 0;
}