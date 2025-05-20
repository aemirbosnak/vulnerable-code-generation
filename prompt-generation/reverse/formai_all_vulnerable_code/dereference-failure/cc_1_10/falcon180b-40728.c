//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *line;
    int length;
} Line;

void add_line(Line **lines, int *num_lines, char *line) {
    Line *new_line = malloc(sizeof(Line));

    new_line->line = strdup(line);
    new_line->length = strlen(line);

    (*lines)[*num_lines] = *new_line;
    (*num_lines)++;
}

void beautify_html(Line *lines, int num_lines) {
    int i;
    for (i = 0; i < num_lines; i++) {
        if (lines[i].length > MAX_LINE_LENGTH) {
            printf("Line %d is too long (%d characters).\n", i + 1, lines[i].length);
        }
    }
}

int main() {
    Line *lines = NULL;
    int num_lines = 0;

    char *filename = "example.html";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file '%s'.\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(&lines, &num_lines, line);
    }

    fclose(file);

    beautify_html(lines, num_lines);

    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].line);
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);

    return 0;
}