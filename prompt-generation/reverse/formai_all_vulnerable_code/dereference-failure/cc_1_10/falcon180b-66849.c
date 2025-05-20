//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *content;
    int length;
} Line;

void append_line(Line *line, char *content) {
    int new_length = line->length + strlen(content);
    char *new_content = realloc(line->content, new_length + 1);
    if (new_content == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    strcat(new_content, content);
    line->content = new_content;
    line->length = new_length;
}

void print_line(Line *line) {
    printf("%s", line->content);
}

int main() {
    FILE *input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file\n");
        exit(1);
    }

    char *line_content = NULL;
    size_t line_length = 0;
    Line current_line = {0};

    while (getline(&line_content, &line_length, input_file)!= -1) {
        if (current_line.length + strlen(line_content) > MAX_LINE_LENGTH) {
            print_line(&current_line);
            current_line = (Line) {0};
        }
        append_line(&current_line, line_content);
    }

    if (current_line.length > 0) {
        print_line(&current_line);
    }

    free(line_content);
    fclose(input_file);

    return 0;
}