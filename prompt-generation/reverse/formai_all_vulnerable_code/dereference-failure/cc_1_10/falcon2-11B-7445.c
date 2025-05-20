//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void kmeans(Point *data, int numPoints, int numClusters, Point *centroids) {
    int *assignments = malloc(numPoints * sizeof(int));
    for (int i = 0; i < numPoints; i++) {
        assignments[i] = -1;
    }

    int counter = 0;
    while (counter < 1000) {
        counter++;

        // Calculate distances from data points to centroids
        for (int i = 0; i < numPoints; i++) {
            double minDistance = distance(data[i], centroids[assignments[i]]);
            for (int j = 0; j < numClusters; j++) {
                if (assignments[i] == -1) {
                    assignments[i] = j;
                }
                if (assignments[i]!= -1 && minDistance > distance(data[i], centroids[j])) {
                    assignments[i] = j;
                }
            }
        }

        // Update centroids
        for (int i = 0; i < numClusters; i++) {
            double sumX = 0, sumY = 0;
            for (int j = 0; j < numPoints; j++) {
                if (assignments[j] == i) {
                    sumX += data[j].x;
                    sumY += data[j].y;
                }
            }
            centroids[i].x = sumX / numPoints;
            centroids[i].y = sumY / numPoints;
        }
    }
}

int main() {
    Point data[] = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}};
    Point centroids[3];

    kmeans(data, 4, 3, centroids);

    printf("Centroids: (%f, %f), (%f, %f), (%f, %f)\n", centroids[0].x, centroids[0].y, centroids[1].x, centroids[1].y, centroids[2].x, centroids[2].y);

    return 0;
}