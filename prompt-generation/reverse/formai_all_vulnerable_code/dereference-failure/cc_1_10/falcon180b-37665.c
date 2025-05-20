//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Code;

void add_line(Code *code, char *line) {
    Line *new_line = malloc(sizeof(Line));
    new_line->line = line;
    new_line->length = strlen(line);
    code->lines = realloc(code->lines, sizeof(Line) * (code->num_lines + 1));
    code->lines[code->num_lines++] = *new_line;
}

void print_line(Line line, int indent) {
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("%s\n", line.line);
}

void print_code(Code code, int indent) {
    for (int i = 0; i < code.num_lines; i++) {
        print_line(code.lines[i], indent);
    }
}

int main() {
    FILE *file = fopen("example.c", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Code code = {0};
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(&code, line);
    }

    fclose(file);

    print_code(code, 0);

    return 0;
}