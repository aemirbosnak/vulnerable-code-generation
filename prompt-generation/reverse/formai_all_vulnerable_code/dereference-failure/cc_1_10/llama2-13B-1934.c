//LLAMA2-13B DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define SCALE 2.0

struct Point {
    int x;
    int y;
};

struct Line {
    struct Point start;
    struct Point end;
};

struct Pattern {
    struct Line *lines;
    int numLines;
};

static void generatePattern(struct Pattern *p) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        p->lines = (struct Line *)realloc(p->lines, (i + 1) * sizeof(struct Line));
        p->lines[i].start.x = i % 2 == 0 ? -10 : 10;
        p->lines[i].start.y = i / 2 + 5;
        p->lines[i].end.x = p->lines[i].start.x + (rand() % 20 - 10) * SCALE;
        p->lines[i].end.y = p->lines[i].start.y + (rand() % 20 - 10) * SCALE;
        for (j = 0; j < i; j++) {
            if (p->lines[j].start.x == p->lines[i].start.x && p->lines[j].start.y == p->lines[i].start.y) {
                p->lines[i].end.x = p->lines[j].end.x;
                p->lines[i].end.y = p->lines[j].end.y;
                break;
            }
        }
    }
    p->numLines = i + 1;
}

static void drawPattern(struct Pattern *p) {
    int i;
    for (i = 0; i < p->numLines; i++) {
        printf("{%d, %d} -> {%d, %d}\n", p->lines[i].start.x, p->lines[i].start.y, p->lines[i].end.x, p->lines[i].end.y);
    }
}

int main() {
    struct Pattern p;
    generatePattern(&p);
    drawPattern(&p);
    return 0;
}