//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3

typedef struct point {
    double x;
    double y;
} Point;

int main() {
    srand(time(NULL));

    int numPoints = 1000;
    Point* points = (Point*) malloc(numPoints * sizeof(Point));
    int numClusters = K;
    Point* clusters = (Point*) malloc(numClusters * sizeof(Point));

    // Generate random points
    for (int i = 0; i < numPoints; i++) {
        points[i].x = (double) rand() / RAND_MAX;
        points[i].y = (double) rand() / RAND_MAX;
    }

    // Perform k-means clustering
    for (int i = 0; i < numClusters; i++) {
        double minDistance = INFINITY;
        int minIndex = -1;

        for (int j = 0; j < numPoints; j++) {
            double distance = sqrt(pow(points[j].x - clusters[i].x, 2) + pow(points[j].y - clusters[i].y, 2));
            if (distance < minDistance) {
                minDistance = distance;
                minIndex = j;
            }
        }

        clusters[i].x = points[minIndex].x;
        clusters[i].y = points[minIndex].y;
    }

    // Print results
    printf("Clusters:\n");
    for (int i = 0; i < numClusters; i++) {
        printf("Cluster %d: (%f, %f)\n", i, clusters[i].x, clusters[i].y);
    }

    free(points);
    free(clusters);

    return 0;
}