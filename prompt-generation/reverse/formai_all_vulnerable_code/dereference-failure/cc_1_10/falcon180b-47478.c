//Falcon-180B DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Text;

void add_line(Text *text, char *line, int line_num) {
    if (text->num_lines >= MAX_NUM_LINES) {
        fprintf(stderr, "Error: Maximum number of lines exceeded.\n");
        exit(1);
    }
    Line *new_line = (Line *) malloc(sizeof(Line));
    new_line->line = strdup(line);
    new_line->line_num = line_num;
    text->lines = realloc(text->lines, sizeof(Line) * (text->num_lines + 1));
    text->lines[text->num_lines] = *new_line;
    text->num_lines++;
}

int main() {
    FILE *input_file;
    char *filename = "input.txt";
    char *line = NULL;
    size_t line_size = 0;
    Text text = {NULL, 0};

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        exit(1);
    }

    while ((getline(&line, &line_size, input_file))!= -1) {
        if (line[0] == '#') {
            continue;
        }
        char *comment = strchr(line, '#');
        if (comment) {
            *comment = '\0';
        }
        add_line(&text, line, 1);
    }

    fclose(input_file);

    if (text.num_lines == 0) {
        fprintf(stderr, "Error: File contains no lines of code.\n");
        exit(1);
    }

    for (int i = 0; i < text.num_lines; i++) {
        printf("%d: %s\n", text.lines[i].line_num, text.lines[i].line);
    }

    return 0;
}