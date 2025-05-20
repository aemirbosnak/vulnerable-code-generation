//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEVEL 10
#define MAX_X 800
#define MAX_Y 800

int xmin, ymin, xmax, ymax;

void draw_fractal(int level, int x1, int y1, int x2, int y2) {
    if (level == 0) {
        printf("%d ", rand() % 7);
    } else {
        int xmid = (x1 + x2) / 2;
        int ymid = (y1 + y2) / 2;
        int dx = x2 - x1;
        int dy = y2 - y1;
        int d = (dx > dy)? dx : dy;
        int n = d / 3;
        int x = x1 + n * dx / d;
        int y = y1 + n * dy / d;
        draw_fractal(level - 1, x1, y1, x, ymid);
        draw_fractal(level - 1, xmid, y1, x2, ymid);
        draw_fractal(level - 1, x1, ymid, xmid, y2);
        draw_fractal(level - 1, xmid, ymid, x2, y2);
    }
}

void fractal(int x1, int y1, int x2, int y2) {
    xmin = x1;
    ymin = y1;
    xmax = x2;
    ymax = y2;
    printf("0 ");
    for (int i = 1; i < MAX_LEVEL; i++) {
        int x = rand() % (xmax - xmin + 1) + xmin;
        int y = rand() % (ymax - ymin + 1) + ymin;
        draw_fractal(i, xmin, ymin, x, ymin);
        draw_fractal(i, xmin, ymin, xmax, ymin);
        draw_fractal(i, xmin, ymax, xmax, ymax);
        draw_fractal(i, xmin, ymax, x, ymax);
    }
}

int main() {
    int seed;
    printf("Enter a seed value: ");
    scanf("%d", &seed);
    srand(seed);
    fractal(0, 0, MAX_X, MAX_Y);
    return 0;
}