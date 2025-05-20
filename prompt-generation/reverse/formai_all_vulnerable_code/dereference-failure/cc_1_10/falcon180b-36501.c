//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

void generate_polygon(Polygon *polygon) {
    int num_points = rand() % 10 + 3;
    polygon->num_points = num_points;
    polygon->points = malloc(sizeof(Point) * num_points);

    for (int i = 0; i < num_points; i++) {
        polygon->points[i].x = rand() % 1000;
        polygon->points[i].y = rand() % 1000;
    }
}

void print_polygon(Polygon *polygon) {
    printf("Polygon with %d points:\n", polygon->num_points);
    for (int i = 0; i < polygon->num_points; i++) {
        printf("(%d, %d)\n", polygon->points[i].x, polygon->points[i].y);
    }
}

void calculate_area(Polygon *polygon) {
    int area = 0;
    Point *last_point = polygon->points + polygon->num_points - 1;

    for (int i = 0; i < polygon->num_points; i++) {
        Point *current_point = polygon->points + i;
        Point *next_point = polygon->points + (i + 1) % polygon->num_points;

        area += (last_point->x - current_point->x) * (next_point->y - current_point->y) -
                (last_point->y - current_point->y) * (next_point->x - current_point->x);
    }

    printf("Polygon area: %d\n", abs(area) / 2);
}

int main() {
    srand(time(0));

    Polygon polygon;
    generate_polygon(&polygon);
    print_polygon(&polygon);
    calculate_area(&polygon);

    return 0;
}