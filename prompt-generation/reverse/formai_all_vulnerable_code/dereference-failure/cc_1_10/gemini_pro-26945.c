//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int x, y;
} point;

typedef struct {
    point p1, p2;
} line;

typedef struct {
    line *lines;
    int num_lines;
} shape;

shape *create_shape(int num_lines) {
    shape *s = malloc(sizeof(shape));
    s->lines = malloc(sizeof(line) * num_lines);
    s->num_lines = num_lines;
    return s;
}

void free_shape(shape *s) {
    free(s->lines);
    free(s);
}

void draw_shape(shape *s) {
    for (int i = 0; i < s->num_lines; i++) {
        line *l = &s->lines[i];
        printf("line from (%d, %d) to (%d, %d)\n", l->p1.x, l->p1.y, l->p2.x, l->p2.y);
    }
}

shape *fibonacci_shape(int n) {
    if (n == 0) {
        return create_shape(0);
    } else if (n == 1) {
        shape *s = create_shape(1);
        s->lines[0].p1.x = 0;
        s->lines[0].p1.y = 0;
        s->lines[0].p2.x = WIDTH;
        s->lines[0].p2.y = 0;
        return s;
    } else {
        shape *s1 = fibonacci_shape(n - 1);
        shape *s2 = fibonacci_shape(n - 2);
        shape *s = create_shape(s1->num_lines + s2->num_lines);
        int i = 0;
        for (; i < s1->num_lines; i++) {
            s->lines[i] = s1->lines[i];
        }
        for (; i < s->num_lines; i++) {
            s->lines[i] = s2->lines[i - s1->num_lines];
        }
        free_shape(s1);
        free_shape(s2);
        return s;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: %s n\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    shape *s = fibonacci_shape(n);
    draw_shape(s);
    free_shape(s);
    return 0;
}