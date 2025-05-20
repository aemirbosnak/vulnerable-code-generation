//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Line;

typedef struct {
    int x;
    int y;
    int z;
} Vector;

typedef struct {
    Vector v1;
    Vector v2;
    Vector v3;
} Plane;

int main() {
    int n = 1000000; // number of points to generate
    Point *points = malloc(n * sizeof(Point)); // allocate memory for points
    Point *centroid = malloc(sizeof(Point)); // allocate memory for centroid
    srand(time(NULL)); // seed random number generator
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 1000; // generate random x coordinate
        points[i].y = rand() % 1000; // generate random y coordinate
    }
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 0; i < n; i++) {
        sum_x += points[i].x; // calculate sum of x coordinates
        sum_y += points[i].y; // calculate sum of y coordinates
    }
    centroid->x = (int)(sum_x / n); // calculate centroid x coordinate
    centroid->y = (int)(sum_y / n); // calculate centroid y coordinate
    double distance = 0;
    for (int i = 0; i < n; i++) {
        distance += sqrt(pow(points[i].x - centroid->x, 2) + pow(points[i].y - centroid->y, 2)); // calculate distance from centroid
    }
    printf("Centroid: (%d, %d)\n", centroid->x, centroid->y); // print centroid coordinates
    printf("Average distance from centroid: %.2f\n", distance / n); // print average distance from centroid
    free(points); // free memory allocated for points
    free(centroid); // free memory allocated for centroid
    return 0;
}