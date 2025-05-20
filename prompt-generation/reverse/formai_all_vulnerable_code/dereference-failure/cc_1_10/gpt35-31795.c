//FormAI DATASET v1.0 Category: Fractal Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500
#define SCALE 200

typedef struct {
    double x, y;
} Point;

Point *new_point(double x, double y) {
    Point *p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

void free_points(Point **points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        free(points[i]);
    }
    free(points);
}

void draw_point(char *img, int x, int y) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        img[x + y * WIDTH] = '.';
    }
}

void draw_line(char *img, Point *start, Point *end) {
    double dx = end->x - start->x;
    double dy = end->y - start->y;

    if (fabs(dx) < 0.0001 && fabs(dy) < 0.0001) {
        draw_point(img, start->x * SCALE + WIDTH / 2, start->y * SCALE + HEIGHT / 2);
    } else if (fabs(dx) > fabs(dy)) {
        double slope = dy / dx;
        double intercept = start->y - slope * start->x;
        int xstart = fmin(start->x, end->x) * SCALE + WIDTH / 2;
        int xend = fmax(start->x, end->x) * SCALE + WIDTH / 2;
        for (int x = xstart; x <= xend; x++) {
            int y = round(slope * (x - WIDTH / 2) / SCALE + intercept + HEIGHT / 2);
            draw_point(img, x, y);
        }
    } else {
        double slope = dx / dy;
        double intercept = start->x - slope * start->y;
        int ystart = fmin(start->y, end->y) * SCALE + HEIGHT / 2;
        int yend = fmax(start->y, end->y) * SCALE + HEIGHT / 2;
        for (int y = ystart; y <= yend; y++) {
            int x = round(slope * (y - HEIGHT / 2) / SCALE + intercept + WIDTH / 2);
            draw_point(img, x, y);
        }
    }
}

void fractal(char *img, Point **points, int num_points, int iterations) {
    if (iterations == 0) {
        return;
    }
    Point **new_points = malloc(sizeof(Point *) * (num_points + 1));
    new_points[0] = points[0];
    new_points[num_points] = points[0];
    for (int i = 1; i < num_points; i++) {
        new_points[i] = new_point((points[i]->x + points[i-1]->x) / 2,
                                  (points[i]->y + points[i-1]->y) / 2);
        draw_line(img, points[i-1], new_points[i]);
    }
    fractal(img, new_points, num_points+1, iterations-1);
}

int main() {
    char *img = malloc(sizeof(char) * WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        img[i] = ' ';
    }
    Point **points = malloc(sizeof(Point *) * 4);
    points[0] = new_point(-1, -1);
    points[1] = new_point(1, -1);
    points[2] = new_point(1, 1);
    points[3] = new_point(-1, 1);
    draw_line(img, points[0], points[1]);
    draw_line(img, points[1], points[2]);
    draw_line(img, points[2], points[3]);
    draw_line(img, points[3], points[0]);
    fractal(img, points, 4, 10);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(img[x + y * WIDTH]);
        }
        putchar('\n');
    }
    free(img);
    free_points(points, 4);
    return 0;
}