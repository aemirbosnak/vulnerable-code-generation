//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096
#define MAX_LINE_NUMBER 100000

typedef struct {
    char* str;
    int len;
} string_t;

typedef struct {
    string_t** lines;
    int line_count;
    int line_length;
} html_t;

void html_init(html_t* html) {
    html->lines = (string_t**)malloc(sizeof(string_t*) * MAX_LINE_NUMBER);
    html->line_count = 0;
    html->line_length = 0;
}

void html_free(html_t* html) {
    for (int i = 0; i < html->line_count; i++) {
        free(html->lines[i]->str);
        free(html->lines[i]);
    }
    free(html->lines);
}

void html_add_line(html_t* html, char* str) {
    if (html->line_count == MAX_LINE_NUMBER) {
        printf("Error: Maximum line count reached.\n");
        return;
    }

    string_t* line = (string_t*)malloc(sizeof(string_t));
    line->str = strdup(str);
    line->len = strlen(str);

    html->lines[html->line_count++] = line;
    html->line_length += line->len;
}

void html_print(html_t* html) {
    for (int i = 0; i < html->line_count; i++) {
        printf("%s", html->lines[i]->str);
    }
}

int main() {
    html_t html;
    html_init(&html);

    html_add_line(&html, "<html>");
    html_add_line(&html, "<head>");
    html_add_line(&html, "<title>My Website</title>");
    html_add_line(&html, "</head>");
    html_add_line(&html, "<body>");
    html_add_line(&html, "<h1>Hello, World!</h1>");
    html_add_line(&html, "<p>This is my first website.</p>");
    html_add_line(&html, "</body>");
    html_add_line(&html, "</html>");

    html_print(&html);

    html_free(&html);

    return 0;
}