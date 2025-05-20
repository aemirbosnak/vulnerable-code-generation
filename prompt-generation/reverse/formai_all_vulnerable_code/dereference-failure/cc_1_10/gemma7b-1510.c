//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct Point {
  int x;
  int y;
} Point;

void cluster(Point *points, int numPoints) {
  int i, j, k, centroidX, centroidY, minDistance, clusterSize = 0;
  Point *centroid = malloc(sizeof(Point));
  centroid->x = centroid->y = -1;

  // Calculate the centroid
  for (i = 0; i < numPoints; i++) {
    int x = points[i].x;
    int y = points[i].y;
    centroidX = (centroidX == -1) ? x : (centroidX * clusterSize + x) / (clusterSize + 1);
    centroidY = (centroidY == -1) ? y : (centroidY * clusterSize + y) / (clusterSize + 1);
    clusterSize++;
  }

  // Calculate the minimum distance to the centroid
  for (i = 0; i < numPoints; i++) {
    int x = points[i].x;
    int y = points[i].y;
    minDistance = sqrt(pow(centroidX - x, 2) + pow(centroidY - y, 2));
    printf("Point %d: Distance to centroid %d is %d\n", i, clusterSize, minDistance);
  }

  free(centroid);
}

int main() {
  Point *points = malloc(sizeof(Point) * MAX_POINTS);
  int numPoints = 0;

  // Get the points
  points[numPoints].x = 10;
  points[numPoints].y = 20;
  numPoints++;

  points[numPoints].x = 15;
  points[numPoints].y = 30;
  numPoints++;

  points[numPoints].x = 20;
  points[numPoints].y = 40;
  numPoints++;

  points[numPoints].x = 25;
  points[numPoints].y = 50;
  numPoints++;

  cluster(points, numPoints);

  free(points);

  return 0;
}