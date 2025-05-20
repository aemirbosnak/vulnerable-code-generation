//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_INDENT_LEVEL 100

typedef struct {
    char *line;
    int indent_level;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int max_line_length;
    int indent_level;
} HTML;

void html_add_line(HTML *html, const char *line) {
    if (html->num_lines >= html->max_line_length) {
        printf("Error: max line length reached\n");
        exit(1);
    }
    Line *new_line = malloc(sizeof(Line));
    new_line->line = strdup(line);
    new_line->indent_level = html->indent_level;
    html->lines = realloc(html->lines, sizeof(Line) * (html->num_lines + 1));
    html->lines[html->num_lines] = *new_line;
    html->num_lines++;
}

void html_print(HTML *html) {
    for (int i = 0; i < html->num_lines; i++) {
        Line *line = &html->lines[i];
        for (int j = 0; j < line->indent_level; j++) {
            printf(" ");
        }
        printf("%s", line->line);
        if (i < html->num_lines - 1) {
            printf("\n");
        }
    }
}

void html_free(HTML *html) {
    for (int i = 0; i < html->num_lines; i++) {
        free(html->lines[i].line);
    }
    free(html->lines);
}

int main() {
    HTML html = {0};
    html.max_line_length = MAX_LINE_LENGTH;
    html.indent_level = 0;
    char input_buffer[MAX_LINE_LENGTH];
    while (fgets(input_buffer, sizeof(input_buffer), stdin)!= NULL) {
        char *line = strtok(input_buffer, "\n");
        while (line!= NULL) {
            if (strlen(line) == 0) {
                html_add_line(&html, "");
            } else if (line[0] == '<') {
                if (html.indent_level == 0) {
                    printf("<html>\n");
                    html.indent_level++;
                }
                printf("%s", line);
            } else if (line[0] == '>') {
                if (html.indent_level > 0) {
                    html.indent_level--;
                }
                printf("%s", line);
            } else {
                html_add_line(&html, line);
            }
            line = strtok(NULL, "\n");
        }
    }
    html_print(&html);
    html_free(&html);
    return 0;
}