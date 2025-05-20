//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <assert.h>

typedef struct {
    uint64_t x;
    uint64_t y;
    uint64_t z;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Line;

typedef struct {
    Point p;
    uint64_t r;
} Circle;

bool point_in_circle(const Circle *c, const Point *p) {
    return (p->x - c->p.x) * (p->x - c->p.x) + (p->y - c->p.y) * (p->y - c->p.y) <= c->r * c->r;
}

bool line_intersects_circle(const Line *l, const Circle *c) {
    uint64_t dx = l->p2.x - l->p1.x;
    uint64_t dy = l->p2.y - l->p1.y;
    uint64_t drx = l->p1.x - c->p.x;
    uint64_t dry = l->p1.y - c->p.y;
    uint64_t det = dx * dx * dy * dy - 4 * dx * dx * dry * dry - 4 * dy * dy * drx * drx;
    return det >= 0;
}

int main() {
    srand(time(NULL));

    uint64_t n = 10000000;
    uint64_t m = 1000000;

    // Generate random points, lines, and circles
    Point *points = malloc(sizeof(Point) * n);
    Line *lines = malloc(sizeof(Line) * m);
    Circle *circles = malloc(sizeof(Circle) * m);
    for (uint64_t i = 0; i < n; i++) {
        points[i].x = rand() % 1000000;
        points[i].y = rand() % 1000000;
    }
    for (uint64_t i = 0; i < m; i++) {
        lines[i].p1.x = rand() % 1000000;
        lines[i].p1.y = rand() % 1000000;
        lines[i].p2.x = rand() % 1000000;
        lines[i].p2.y = rand() % 1000000;
        circles[i].p.x = rand() % 1000000;
        circles[i].p.y = rand() % 1000000;
        circles[i].r = rand() % 1000000;
    }

    // Perform intersection checks
    uint64_t count_line_intersections = 0;
    uint64_t count_point_intersections = 0;
    for (uint64_t i = 0; i < m; i++) {
        for (uint64_t j = 0; j < n; j++) {
            if (point_in_circle(&circles[i], &points[j])) {
                count_point_intersections++;
            }
            if (line_intersects_circle(&lines[i], &circles[i])) {
                count_line_intersections++;
            }
        }
    }

    // Print results
    printf("Number of line intersections: %lu\n", count_line_intersections);
    printf("Number of point intersections: %lu\n", count_point_intersections);

    // Free allocated memory
    free(points);
    free(lines);
    free(circles);

    return 0;
}