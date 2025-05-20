//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of points
#define MAX_POINTS 100

// Define the structure of a point
typedef struct {
  double x;
  double y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to calculate the mean of a set of points
Point mean(Point points[], int numPoints) {
  Point meanPoint;
  meanPoint.x = 0;
  meanPoint.y = 0;
  for (int i = 0; i < numPoints; i++) {
    meanPoint.x += points[i].x;
    meanPoint.y += points[i].y;
  }
  meanPoint.x /= numPoints;
  meanPoint.y /= numPoints;
  return meanPoint;
}

// Function to calculate the standard deviation of a set of points
double standardDeviation(Point points[], int numPoints) {
  Point meanPoint = mean(points, numPoints);
  double sumOfSquares = 0;
  for (int i = 0; i < numPoints; i++) {
    sumOfSquares += pow(distance(points[i], meanPoint), 2);
  }
  return sqrt(sumOfSquares / numPoints);
}

// Function to generate a set of random points
Point *generateRandomPoints(int numPoints) {
  Point *points = malloc(sizeof(Point) * numPoints);
  for (int i = 0; i < numPoints; i++) {
    points[i].x = rand() % 100;
    points[i].y = rand() % 100;
  }
  return points;
}

// Function to print a set of points
void printPoints(Point points[], int numPoints) {
  for (int i = 0; i < numPoints; i++) {
    printf("(%f, %f)\n", points[i].x, points[i].y);
  }
}

int main() {
  // Generate a set of random points
  int numPoints = 10;
  Point *points = generateRandomPoints(numPoints);

  // Calculate the mean and standard deviation of the points
  Point meanPoint = mean(points, numPoints);
  double standardDeviationValue = standardDeviation(points, numPoints);

  // Print the mean and standard deviation
  printf("Mean: (%f, %f)\n", meanPoint.x, meanPoint.y);
  printf("Standard deviation: %f\n", standardDeviationValue);

  // Print the points
  printf("Points:\n");
  printPoints(points, numPoints);

  // Free the allocated memory
  free(points);

  return 0;
}