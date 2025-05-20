//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Ebook;

Ebook *create_ebook() {
    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->lines = NULL;
    ebook->num_lines = 0;
    return ebook;
}

void add_line_to_ebook(Ebook *ebook, char *line) {
    Line *new_line = malloc(sizeof(Line));
    new_line->text = strdup(line);
    new_line->length = strlen(line);
    ebook->lines = realloc(ebook->lines, (ebook->num_lines + 1) * sizeof(Line));
    ebook->lines[ebook->num_lines] = *new_line;
    ebook->num_lines++;
}

void print_ebook(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i].text);
    }
}

int main() {
    Ebook *ebook = create_ebook();

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line_to_ebook(ebook, line);
    }

    print_ebook(ebook);

    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i].text);
    }
    free(ebook->lines);
    free(ebook);

    return 0;
}