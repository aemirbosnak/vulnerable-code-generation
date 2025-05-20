//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *text;
    int length;
} Line;

Line *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    Line *lines = NULL;
    int num_lines = 0;

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        int length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[--length] = '\0';
        }

        Line *new_line = malloc(sizeof(Line));
        new_line->text = strdup(buffer);
        new_line->length = length;

        lines = realloc(lines, sizeof(Line) * ++num_lines);
        lines[num_lines - 1] = *new_line;
    }

    fclose(file);
    return lines;
}

void print_lines(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].text);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Line *lines = read_file(argv[1]);
    print_lines(lines, MAX_NUM_LINES);

    for (int i = 0; i < MAX_NUM_LINES; i++) {
        free(lines[i].text);
    }
    free(lines);

    return 0;
}