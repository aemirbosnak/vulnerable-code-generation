//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_INDENT_LEVEL 10

typedef struct {
    char *text;
    int indent_level;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int current_line;
} Code;

void code_init(Code *code) {
    code->lines = NULL;
    code->num_lines = 0;
    code->current_line = 0;
}

void code_add_line(Code *code, const char *text, int indent_level) {
    Line *line = malloc(sizeof(Line));
    line->text = strdup(text);
    line->indent_level = indent_level;
    code->lines = realloc(code->lines, sizeof(Line) * (code->num_lines + 1));
    code->lines[code->num_lines++] = *line;
}

void code_free(Code *code) {
    for (int i = 0; i < code->num_lines; i++) {
        free(code->lines[i].text);
    }
    free(code->lines);
}

void code_print(Code *code) {
    for (int i = 0; i < code->num_lines; i++) {
        printf("%*s%s\n", code->lines[i].indent_level * 4, "", code->lines[i].text);
    }
}

int main() {
    Code code;
    code_init(&code);

    code_add_line(&code, "<html>", 0);
    code_add_line(&code, "  <head>", 4);
    code_add_line(&code, "    <title>Hello, world!</title>", 8);
    code_add_line(&code, "  </head>", 4);
    code_add_line(&code, "  <body>", 4);
    code_add_line(&code, "    <h1>Hello, world!</h1>", 8);
    code_add_line(&code, "    <p>This is my first webpage.</p>", 8);
    code_add_line(&code, "  </body>", 4);
    code_add_line(&code, "</html>", 0);

    code_print(&code);

    code_free(&code);

    return 0;
}