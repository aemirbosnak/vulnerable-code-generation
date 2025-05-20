//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

bool is_point_inside_polygon(Point point, Polygon polygon) {
    int j, k;
    bool inside = false;

    for (j = 0, k = polygon.num_points - 1; j < polygon.num_points; k = j++) {
        if ((polygon.points[j].y > point.y)!= (polygon.points[k].y > point.y) &&
            (point.x < (polygon.points[k].x - polygon.points[j].x) * (point.y - polygon.points[j].y) / (polygon.points[k].y - polygon.points[j].y) + polygon.points[j].x)) {
            inside =!inside;
        }
    }

    return inside;
}

int main() {
    Polygon polygon;
    Point point;
    int i, num_points;
    char input[100];

    // Read number of points for polygon
    printf("Enter number of points for polygon: ");
    scanf("%d", &num_points);

    // Read coordinates of polygon points
    polygon.points = (Point *)malloc(num_points * sizeof(Point));
    for (i = 0; i < num_points; i++) {
        printf("Enter coordinates of point %d: ", i + 1);
        scanf("%lf %lf", &point.x, &point.y);
        polygon.points[i] = point;
    }

    // Read coordinates of point to check
    printf("Enter coordinates of point to check: ");
    scanf("%lf %lf", &point.x, &point.y);

    // Check if point is inside polygon
    if (is_point_inside_polygon(point, polygon)) {
        printf("The point is inside the polygon.\n");
    } else {
        printf("The point is outside the polygon.\n");
    }

    return 0;
}