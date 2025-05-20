//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Polygon;

void init_polygon(Polygon *polygon) {
    polygon->points = malloc(MAX_SIZE * sizeof(Point));
    polygon->size = 0;
}

void add_point(Polygon *polygon, int x, int y) {
    Point *point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    polygon->points[polygon->size++] = *point;
}

void print_polygon(Polygon *polygon) {
    for (int i = 0; i < polygon->size; i++) {
        printf("(%d,%d) ", polygon->points[i].x, polygon->points[i].y);
    }
    printf("\n");
}

void free_polygon(Polygon *polygon) {
    free(polygon->points);
}

int main() {
    Polygon polygon;
    init_polygon(&polygon);

    char input[MAX_SIZE];
    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        char *token = strtok(input, " ");
        int x = atoi(token);
        token = strtok(NULL, " ");
        int y = atoi(token);
        add_point(&polygon, x, y);
    }

    print_polygon(&polygon);
    free_polygon(&polygon);

    return 0;
}