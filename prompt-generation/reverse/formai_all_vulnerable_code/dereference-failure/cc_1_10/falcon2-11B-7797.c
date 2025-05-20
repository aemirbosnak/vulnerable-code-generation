//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void initializePoints(Point **points, int numPoints) {
    srand(time(0));
    for (int i = 0; i < numPoints; i++) {
        points[i] = (Point *)malloc(sizeof(Point));
        points[i]->x = rand() % 1000 - 500;
        points[i]->y = rand() % 1000 - 500;
    }
}

void printPoints(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

int distance(Point *p1, Point *p2) {
    int dx = p1->x - p2->x;
    int dy = p1->y - p2->y;
    return (dx * dx + dy * dy);
}

void kmeans(Point *points, int numPoints, int numClusters, Point *clusterCenters) {
    int i, j, k, minDist, minIdx;
    double dist;

    for (i = 0; i < numClusters; i++) {
        clusterCenters[i].x = 0;
        clusterCenters[i].y = 0;
    }

    for (i = 0; i < numPoints; i++) {
        minDist = 10000;
        minIdx = 0;
        for (j = 0; j < numClusters; j++) {
            dist = distance(&points[i], &clusterCenters[j]);
            if (dist < minDist) {
                minDist = dist;
                minIdx = j;
            }
        }
        clusterCenters[minIdx].x += points[i].x;
        clusterCenters[minIdx].y += points[i].y;
    }

    for (i = 0; i < numClusters; i++) {
        clusterCenters[i].x /= numPoints;
        clusterCenters[i].y /= numPoints;
    }

    for (i = 0; i < numPoints; i++) {
        minDist = 10000;
        minIdx = 0;
        for (j = 0; j < numClusters; j++) {
            dist = distance(&points[i], &clusterCenters[j]);
            if (dist < minDist) {
                minDist = dist;
                minIdx = j;
            }
        }
        points[i].x = clusterCenters[minIdx].x;
        points[i].y = clusterCenters[minIdx].y;
    }
}

int main() {
    int numPoints = 100;
    int numClusters = 3;

    Point *points;
    Point *clusterCenters;

    initializePoints(&points, numPoints);
    printPoints(points, numPoints);

    clusterCenters = (Point *)malloc(numClusters * sizeof(Point));
    kmeans(points, numPoints, numClusters, clusterCenters);
    printPoints(clusterCenters, numClusters);

    return 0;
}