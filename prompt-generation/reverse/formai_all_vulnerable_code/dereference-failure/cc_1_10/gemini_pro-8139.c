//GEMINI-pro DATASET v1.0 Category: Game ; Style: ephemeral
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Line;

typedef struct {
    Line *lines;
    int n;
} Lines;

Lines *new_lines() {
    Lines *ls = malloc(sizeof(Lines));
    ls->lines = NULL;
    ls->n = 0;
    return ls;
}

void free_lines(Lines *ls) {
    free(ls->lines);
    free(ls);
}

void add_line(Lines *ls, Point p1, Point p2) {
    if (ls->lines == NULL) {
        ls->lines = malloc(sizeof(Line));
        ls->n = 1;
        ls->lines[0].p1 = p1;
        ls->lines[0].p2 = p2;
    } else {
        ls->lines = realloc(ls->lines, sizeof(Line) * (ls->n + 1));
        ls->lines[ls->n].p1 = p1;
        ls->lines[ls->n].p2 = p2;
        ls->n++;
    }
}

int main() {
    srand(time(NULL));

    int n = 100;
    Lines *ls = new_lines();

    for (int i = 0; i < n; i++) {
        Point p1 = {rand() % 100, rand() % 100};
        Point p2 = {rand() % 100, rand() % 100};
        add_line(ls, p1, p2);
    }

    FILE *f = fopen("lines.txt", "w");
    fprintf(f, "%d\n", ls->n);
    for (int i = 0; i < ls->n; i++) {
        fprintf(f, "%d %d %d %d\n", ls->lines[i].p1.x, ls->lines[i].p1.y, ls->lines[i].p2.x, ls->lines[i].p2.y);
    }
    fclose(f);

    free_lines(ls);

    return 0;
}