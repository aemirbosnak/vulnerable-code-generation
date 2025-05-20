//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the fractal dimension of a set of points
float fractalDimension(float *points, int numPoints) {
    float sumX = 0;
    float sumY = 0;
    float sumDist = 0;
    float minDist = distance(points[0], points[1], points[0], points[1]);
    float maxDist = 0;

    for (int i = 0; i < numPoints - 1; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            float dist = distance(points[i], points[j], points[i], points[j]);
            sumDist += dist;

            if (dist < minDist) {
                minDist = dist;
            }

            if (dist > maxDist) {
                maxDist = dist;
            }
        }
    }

    float avgDist = sumDist / (numPoints * (numPoints - 1));
    float fractalDimension = (log(avgDist) / log(minDist)) - 1;
    return fractalDimension;
}

int main() {
    int numPoints = 100;
    float *points = malloc(numPoints * sizeof(float));

    for (int i = 0; i < numPoints; i++) {
        points[i] = (float)rand() / RAND_MAX;
    }

    printf("Fractal Dimension: %f\n", fractalDimension(points, numPoints));

    free(points);

    return 0;
}