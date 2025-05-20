//Gemma-7B DATASET v1.0 Category: Data mining ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct Point {
    int x;
    int y;
} Point;

void loadPoints(Point *points, int *numPoints) {
    FILE *fp = fopen("points.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    *numPoints = 0;
    points = NULL;

    while (!feof(fp)) {
        points = realloc(points, (*numPoints + 1) * sizeof(Point));
        points[*numPoints].x = atoi(fgets(NULL, MAX_POINTS, fp));
        points[*numPoints].y = atoi(fgets(NULL, MAX_POINTS, fp));
        (*numPoints)++;
    }

    fclose(fp);
}

void findClusters(Point *points, int numPoints, int **clusters) {
    int i, j, k, d, minDistance, clusterId = 0;
    double distance;

    *clusters = malloc(numPoints * sizeof(int));

    for (i = 0; i < numPoints; i++) {
        for (j = 0; j < numPoints; j++) {
            if (i != j) {
                distance = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
                minDistance = distance;

                for (k = 0; k < clusters[i]; k++) {
                    if (minDistance > clusters[k]) {
                        minDistance = clusters[k];
                    }
                }

                clusters[i] = minDistance;
            }
        }
    }

    for (k = 0; k < numPoints; k++) {
        clusters[k] = clusterId;
    }

    clusterId++;
}

int main() {
    Point *points = NULL;
    int numPoints = 0;
    int **clusters = NULL;

    loadPoints(points, &numPoints);
    findClusters(points, numPoints, &clusters);

    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: (%d, %d) - Cluster %d\n", i, points[i].x, points[i].y, clusters[i]);
    }

    free(points);
    free(clusters);

    return 0;
}