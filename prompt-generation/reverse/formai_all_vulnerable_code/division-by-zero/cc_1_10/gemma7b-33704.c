//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Point {
    int x;
    int y;
} Point;

int main() {
    Point p[MAX];
    int n, i, j, k, d, area, perimeter, centroid_x, centroid_y;
    double distance;

    scanf("Enter the number of points: ", &n);

    for (i = 0; i < n; i++) {
        scanf("Enter the x-coordinate: ", &p[i].x);
        scanf("Enter the y-coordinate: ", &p[i].y);
    }

    // Calculate the area of the polygon
    area = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            d = p[j].x - p[i].x;
            distance = sqrt(d * d + (p[j].y - p[i].y) * (p[j].y - p[i].y));
            area += distance;
        }
    }

    // Calculate the perimeter of the polygon
    perimeter = 0;
    for (i = 0; i < n; i++) {
        d = p[i].x - p[0].x;
        distance = sqrt(d * d + (p[i].y - p[0].y) * (p[i].y - p[0].y));
        perimeter += distance;
    }

    // Calculate the centroid of the polygon
    centroid_x = (p[0].x * n - p[0].x * area) / perimeter;
    centroid_y = (p[0].y * n - p[0].y * area) / perimeter;

    // Print the results
    printf("The area of the polygon is: %d\n", area);
    printf("The perimeter of the polygon is: %d\n", perimeter);
    printf("The centroid of the polygon is: (%d, %d)\n", centroid_x, centroid_y);

    return 0;
}