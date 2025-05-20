//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    double x;
    double y;
    int cluster;
};

double distance(struct Point p1, struct Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

void assignClusters(struct Point *points, int numPoints, struct Point *centers, int numCenters) {
    for (int i = 0; i < numPoints; i++) {
        double minDist = INFINITY;
        int minCluster = -1;
        for (int j = 0; j < numCenters; j++) {
            double dist = distance(points[i], centers[j]);
            if (dist < minDist) {
                minDist = dist;
                minCluster = j;
            }
        }
        points[i].cluster = minCluster;
    }
}

void updateCenters(struct Point *points, int numPoints, struct Point *centers, int numCenters) {
    int *counts = calloc(numCenters, sizeof(int));
    for (int i = 0; i < numPoints; i++) {
        int cluster = points[i].cluster;
        counts[cluster]++;
        centers[cluster].x += points[i].x;
        centers[cluster].y += points[i].y;
    }
    for (int i = 0; i < numCenters; i++) {
        if (counts[i] == 0) {
            continue;
        }
        centers[i].x /= counts[i];
        centers[i].y /= counts[i];
    }
    free(counts);
}

void printClusters(struct Point *points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: (%.2f, %.2f) - Cluster %d\n", i, points[i].x, points[i].y, points[i].cluster);
    }
}

int main() {
    int numPoints = 10;
    struct Point *points = calloc(numPoints, sizeof(struct Point));
    for (int i = 0; i < numPoints; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    int numCenters = 3;
    struct Point *centers = calloc(numCenters, sizeof(struct Point));
    for (int i = 0; i < numCenters; i++) {
        centers[i].x = rand() % 100;
        centers[i].y = rand() % 100;
    }
    for (int i = 0; i < 10; i++) {
        printf("Iteration %d\n", i);
        assignClusters(points, numPoints, centers, numCenters);
        updateCenters(points, numPoints, centers, numCenters);
        printClusters(points, numPoints);
        printf("\n");
    }
    free(points);
    free(centers);
    return 0;
}