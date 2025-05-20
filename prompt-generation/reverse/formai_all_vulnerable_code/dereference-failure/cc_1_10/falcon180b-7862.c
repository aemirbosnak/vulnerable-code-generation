//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Ebook;

void init_ebook(Ebook *ebook) {
    ebook->lines = NULL;
    ebook->num_lines = 0;
}

void add_line(Ebook *ebook, char *line, int line_num) {
    Line *new_line = malloc(sizeof(Line));

    new_line->line = malloc(strlen(line) + 1);
    strcpy(new_line->line, line);

    new_line->line_num = line_num;

    ebook->lines = realloc(ebook->lines, sizeof(Line) * (ebook->num_lines + 1));
    ebook->lines[ebook->num_lines] = *new_line;
    ebook->num_lines++;
}

void print_ebook(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%d: %s\n", ebook->lines[i].line_num, ebook->lines[i].line);
    }
}

int main() {
    Ebook ebook;
    init_ebook(&ebook);

    char line[MAX_LINE_SIZE];
    int line_num = 1;

    while (fgets(line, MAX_LINE_SIZE, stdin)!= NULL) {
        add_line(&ebook, line, line_num);
        line_num++;
    }

    print_ebook(&ebook);

    return 0;
}