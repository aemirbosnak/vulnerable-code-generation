//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *text;
    int length;
} Line;

void read_file(FILE *file, Line **lines, int *line_count) {
    char buffer[MAX_LINE_SIZE];
    Line *new_line = NULL;
    int line_length = 0;

    while (fgets(buffer, MAX_LINE_SIZE, file)!= NULL) {
        new_line = realloc(lines[*line_count], (*line_count + 1) * sizeof(Line));
        if (new_line == NULL) {
            printf("Memory error!\n");
            exit(1);
        }
        lines[*line_count] = new_line;

        new_line[*line_count].text = strdup(buffer);
        new_line[*line_count].length = strlen(buffer);

        (*line_count)++;
    }
}

void print_lines(Line *lines, int line_count) {
    int i;

    for (i = 0; i < line_count; i++) {
        printf("%s\n", lines[i].text);
    }
}

int main() {
    FILE *file;
    Line *lines = NULL;
    int line_count = 0;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    read_file(file, &lines, &line_count);
    fclose(file);

    print_lines(lines, line_count);

    free(lines);
    return 0;
}