//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: recursive
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

void free_html(html_t *html) {
    for (int i = 0; i < html->num_lines; i++) {
        free(html->lines[i].line);
    }
    free(html->lines);
    free(html);
}

html_t *parse_html(char *html_string) {
    html_t *html = malloc(sizeof(html_t));
    html->lines = malloc(sizeof(line_t) * MAX_LINE_LENGTH);
    html->num_lines = 0;

    int line_length = 0;
    char *line = malloc(sizeof(char) * MAX_LINE_LENGTH);
    for (int i = 0; html_string[i] != '\0'; i++) {
        if (html_string[i] == '\n') {
            html->lines[html->num_lines].line = malloc(sizeof(char) * line_length);
            strncpy(html->lines[html->num_lines].line, line, line_length);
            html->lines[html->num_lines].line[line_length] = '\0';
            html->num_lines++;
            line_length = 0;
        } else {
            line[line_length++] = html_string[i];
        }
    }

    free(line);
    return html;
}

void beautify_html_recursive(html_t *html, int level) {
    for (int i = 0; i < html->num_lines; i++) {
        for (int j = 0; j < level; j++) {
            printf("  ");
        }
        printf("%s\n", html->lines[i].line);
        if (strstr(html->lines[i].line, "<") != NULL) {
            html_t *inner_html = parse_html(strstr(html->lines[i].line, ">") + 1);
            beautify_html_recursive(inner_html, level + 1);
            free_html(inner_html);
        }
    }
}

void beautify_html(html_t *html) {
    beautify_html_recursive(html, 0);
}

int main() {
    char *html_string = "<html>\n"
                          "  <head>\n"
                          "    <title>My Website</title>\n"
                          "  </head>\n"
                          "  <body>\n"
                          "    <h1>Welcome to my website!</h1>\n"
                          "    <p>This is my website. It is still under construction, but I am working hard to make it the best it can be.</p>\n"
                          "    <ul>\n"
                          "      <li>Item 1</li>\n"
                          "      <li>Item 2</li>\n"
                          "      <li>Item 3</li>\n"
                          "    </ul>\n"
                          "  </body>\n"
                          "</html>";

    html_t *html = parse_html(html_string);
    beautify_html(html);
    free_html(html);

    return 0;
}