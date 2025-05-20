//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
    int x;
    int y;
} Point;

void move(int dx, int dy, Point *p) {
    p->x += dx;
    p->y += dy;
}

int main() {
    srand(time(NULL));
    int width = 1000;
    int height = 1000;
    int num_points = 100;
    Point *points = malloc(sizeof(Point) * num_points);

    for (int i = 0; i < num_points; i++) {
        points[i].x = rand() % width;
        points[i].y = rand() % height;
    }

    int num_iterations = 100000;

    for (int i = 0; i < num_iterations; i++) {
        for (int j = 0; j < num_points; j++) {
            int dx = 0;
            int dy = 0;

            for (int k = 0; k < num_points; k++) {
                if (k == j)
                    continue;

                int distance = sqrt(pow(points[j].x - points[k].x, 2) + pow(points[j].y - points[k].y, 2));

                if (distance < 50) {
                    dx += (points[k].x - points[j].x) / distance;
                    dy += (points[k].y - points[j].y) / distance;
                }
            }

            move(dx, dy, &points[j]);
        }
    }

    for (int i = 0; i < num_points; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    free(points);
    return 0;
}