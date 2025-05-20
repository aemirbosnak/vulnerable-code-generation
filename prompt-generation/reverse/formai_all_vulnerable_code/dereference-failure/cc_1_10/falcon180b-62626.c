//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} PointSet;

void createPointSet(PointSet *set, int numPoints) {
    set->points = malloc(numPoints * sizeof(Point));
    set->size = numPoints;

    for (int i = 0; i < numPoints; i++) {
        set->points[i].x = rand() % MAX_SIZE;
        set->points[i].y = rand() % MAX_SIZE;
    }
}

void destroyPointSet(PointSet *set) {
    free(set->points);
}

void kMeans(PointSet *set, int k, Point *centroids) {
    Point *means = malloc(k * sizeof(Point));
    int *assignments = malloc(set->size * sizeof(int));

    for (int i = 0; i < k; i++) {
        means[i].x = rand() % MAX_SIZE;
        means[i].y = rand() % MAX_SIZE;
    }

    int *counts = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < set->size; i++) {
        int minDistance = MAX_SIZE;
        int minIndex = -1;

        for (int j = 0; j < k; j++) {
            int distance = sqrt(pow(set->points[i].x - means[j].x, 2) + pow(set->points[i].y - means[j].y, 2));

            if (distance < minDistance) {
                minDistance = distance;
                minIndex = j;
            }
        }

        assignments[i] = minIndex;
        counts[minIndex]++;
    }

    for (int i = 0; i < k; i++) {
        centroids[i].x = 0;
        centroids[i].y = 0;

        for (int j = 0; j < set->size; j++) {
            if (assignments[j] == i) {
                centroids[i].x += set->points[j].x;
                centroids[i].y += set->points[j].y;
            }
        }

        centroids[i].x /= counts[i];
        centroids[i].y /= counts[i];
    }

    free(means);
    free(assignments);
    free(counts);
}

int main() {
    PointSet set;
    createPointSet(&set, 100000);

    Point centroids[3];
    kMeans(&set, 3, centroids);

    for (int i = 0; i < 3; i++) {
        printf("Centroid %d: (%d, %d)\n", i, centroids[i].x, centroids[i].y);
    }

    destroyPointSet(&set);

    return 0;
}