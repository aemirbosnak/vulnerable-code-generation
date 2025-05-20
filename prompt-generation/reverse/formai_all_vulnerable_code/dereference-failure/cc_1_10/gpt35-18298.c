//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Point {
    int x, y;
} Point;

float distance(Point a, Point b) {
    return sqrt(pow((b.x-a.x), 2) + pow((b.y-a.y), 2));
}

Point *generateRandomPoints(int num) {
    Point *points = malloc(num * sizeof(Point));
    for (int i = 0; i < num; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    return points;
}

void printPoints(Point *points, int num) {
    for (int i = 0; i < num; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

bool isSquare(Point *points) {
    float d1 = distance(points[0], points[1]);
    float d2 = distance(points[0], points[2]);
    float d3 = distance(points[0], points[3]);

    if (d2 == d3 && 2 * pow(d2, 2) == pow(d1, 2)) {
        return true;
    }
    if (d1 == d3 && 2 * pow(d1, 2) == pow(d2, 2)) {
        return true;
    }
    if (d1 == d2 && 2 * pow(d1, 2) == pow(d3, 2)) {
        return true;
    }
    return false;
}

int main(void) {
    // Generate random points
    Point *points = generateRandomPoints(4);
    printf("Randomly generated points:\n");
    printPoints(points, 4);

    // Check if the points form a square
    bool square = isSquare(points);
    if (square) {
        printf("The points form a square!\n");
    } else {
        printf("The points do not form a square.\n");
    }

    free(points);

    return 0;
}