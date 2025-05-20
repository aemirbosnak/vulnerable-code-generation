//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_POINTS 1000000
#define PI 3.14159

typedef struct {
    int x;
    int y;
    int color;
} Point;

Point* generatePoints(int numPoints) {
    Point* points = malloc(numPoints * sizeof(Point));
    srand(time(NULL));
    for (int i = 0; i < numPoints; i++) {
        points[i].x = rand() % WIDTH;
        points[i].y = rand() % HEIGHT;
        points[i].color = rand() % 256;
    }
    return points;
}

void drawPoint(int x, int y, int color) {
    printf("\033[31m");
    printf("\033[48;2;%d;%d;%dm ", x, y, color);
    printf("\033[0m");
}

void drawPoints(Point* points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        drawPoint(points[i].x, points[i].y, points[i].color);
    }
}

void generateRandomGraph(int numPoints) {
    Point* points = generatePoints(numPoints);
    drawPoints(points, numPoints);
    free(points);
}

int main() {
    int numPoints = 10000;
    generateRandomGraph(numPoints);
    return 0;
}