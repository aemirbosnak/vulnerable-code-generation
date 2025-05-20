//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265359

typedef struct {
    int x;
    int y;
} Point;

void init_random_seed() {
    srand(time(NULL));
}

Point random_point(int min_x, int max_x, int min_y, int max_y) {
    Point result;
    result.x = rand() % (max_x - min_x + 1) + min_x;
    result.y = rand() % (max_y - min_y + 1) + min_y;
    return result;
}

int main() {
    init_random_seed();

    int width = 800;
    int height = 600;

    int num_points = 1000;
    Point* points = malloc(num_points * sizeof(Point));

    for (int i = 0; i < num_points; i++) {
        points[i] = random_point(0, width, 0, height);
    }

    int num_iterations = 100;

    for (int iteration = 0; iteration < num_iterations; iteration++) {
        for (int i = 0; i < num_points; i++) {
            Point p = points[i];

            double dx = (double)p.x / width;
            double dy = (double)p.y / height;

            double vx = cos(2 * PI * dx);
            double vy = sin(2 * PI * dy);

            p.x += (int)(vx * 10);
            p.y += (int)(vy * 10);

            if (p.x < 0) {
                p.x = width - 1;
            } else if (p.x >= width) {
                p.x = 0;
            }

            if (p.y < 0) {
                p.y = height - 1;
            } else if (p.y >= height) {
                p.y = 0;
            }

            points[i] = p;
        }
    }

    for (int i = 0; i < num_points; i++) {
        Point p = points[i];
        printf("%d %d\n", p.x, p.y);
    }

    free(points);

    return 0;
}