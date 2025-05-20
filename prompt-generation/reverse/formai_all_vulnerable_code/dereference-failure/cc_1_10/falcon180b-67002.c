//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    int length;
} Line;

Line *read_file(FILE *file) {
    char buffer[MAX_LINE_LENGTH];
    Line *lines = NULL;
    int num_lines = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        Line *line = malloc(sizeof(Line));
        line->text = strdup(buffer);
        line->length = strlen(buffer);
        lines = realloc(lines, sizeof(Line) * ++num_lines);
        lines[num_lines - 1] = *line;
        free(line);
    }

    return lines;
}

void print_lines(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i + 1, lines[i].text);
    }
}

int main() {
    FILE *file;
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    Line *lines = read_file(file);

    print_lines(lines, lines->length);

    free(lines);
    fclose(file);

    return 0;
}