//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int id;
    double x, y, z;
} Point;

void generatePoints(Point* points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        points[i].id = i;
        points[i].x = rand() % MAX_SIZE;
        points[i].y = rand() % MAX_SIZE;
        points[i].z = rand() % MAX_SIZE;
    }
}

void calculateDistance(Point* points, int numPoints, Point* closest, int* distance) {
    for (int i = 0; i < numPoints; i++) {
        double xDiff = points[i].x - closest->x;
        double yDiff = points[i].y - closest->y;
        double zDiff = points[i].z - closest->z;
        double distanceSquared = xDiff * xDiff + yDiff * yDiff + zDiff * zDiff;
        if (*distance == 0 || distanceSquared < *distance) {
            *distance = distanceSquared;
            closest->id = i;
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <numPoints>\n", argv[0]);
        return 1;
    }

    int numPoints = atoi(argv[1]);
    Point* points = (Point*) malloc(numPoints * sizeof(Point));
    Point closest;
    int closestDistance = MAX_SIZE;

    generatePoints(points, numPoints);
    calculateDistance(points, numPoints, &closest, &closestDistance);

    printf("Closest points: (%d, %d, %d), Distance: %d\n", closest.id, closest.x, closest.y, closest.z);

    free(points);
    return 0;
}