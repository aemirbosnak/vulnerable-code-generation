//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: satisfied
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

char *html_beautify(html_t *html) {
    char *beautified_html = malloc(MAX_LINE_LENGTH * html->num_lines);
    int beautified_html_length = 0;
    for (int i = 0; i < html->num_lines; i++) {
        char *line = html->lines[i].line;
        int line_length = html->lines[i].length;
        for (int j = 0; j < line_length; j++) {
            char c = line[j];
            if (c == '<') {
                beautified_html[beautified_html_length++] = c;
                beautified_html[beautified_html_length++] = '\n';
            } else if (c == '>') {
                beautified_html[beautified_html_length++] = '\n';
                beautified_html[beautified_html_length++] = c;
            } else {
                beautified_html[beautified_html_length++] = c;
            }
        }
        beautified_html[beautified_html_length++] = '\n';
    }
    beautified_html[beautified_html_length] = '\0';
    return beautified_html;
}

int main() {
    html_t *html = html_new();
    html_add_line(html, "<html>");
    html_add_line(html, "<head>");
    html_add_line(html, "<title>My Website</title>");
    html_add_line(html, "</head>");
    html_add_line(html, "<body>");
    html_add_line(html, "<h1>Welcome to My Website</h1>");
    html_add_line(html, "<p>This is my website. It is still under construction, but I will be adding new content soon.</p>");
    html_add_line(html, "</body>");
    html_add_line(html, "</html>");

    char *beautified_html = html_beautify(html);
    printf("%s", beautified_html);

    html_free(html);
    free(beautified_html);
    return 0;
}