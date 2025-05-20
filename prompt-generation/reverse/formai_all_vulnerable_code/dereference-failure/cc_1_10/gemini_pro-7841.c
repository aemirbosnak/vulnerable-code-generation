//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: standalone
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
    line_t *new_line = malloc(sizeof(line_t));
    new_line->line = strdup(line);
    new_line->length = strlen(line);
    html->lines = realloc(html->lines, (html->num_lines + 1) * sizeof(line_t));
    html->lines[html->num_lines] = *new_line;
    html->num_lines++;
    return 0;
}

char *html_beautify(html_t *html) {
    char *beautified_html = malloc(MAX_LINE_LENGTH * html->num_lines);
    int current_line = 0;
    for (int i = 0; i < html->num_lines; i++) {
        line_t *line = &html->lines[i];
        strcat(beautified_html, line->line);
        if (line->length > 0 && line->line[line->length - 1] != '\n') {
            strcat(beautified_html, "\n");
        }
        current_line++;
        if (current_line >= 10) {
            strcat(beautified_html, "\n");
            current_line = 0;
        }
    }
    return beautified_html;
}

int main() {
    html_t *html = html_new();
    html_add_line(html, "<html>");
    html_add_line(html, "<head>");
    html_add_line(html, "<title>My Website</title>");
    html_add_line(html, "</head>");
    html_add_line(html, "<body>");
    html_add_line(html, "<h1>Welcome to my website!</h1>");
    html_add_line(html, "<p>This is my website. It is still under construction, but I will be adding new content soon.</p>");
    html_add_line(html, "</body>");
    html_add_line(html, "</html>");

    char *beautified_html = html_beautify(html);
    printf("%s", beautified_html);

    html_free(html);
    free(beautified_html);
    return 0;
}