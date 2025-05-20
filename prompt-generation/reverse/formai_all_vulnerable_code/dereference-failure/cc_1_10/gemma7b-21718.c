//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

int main()
{
    int nPoints = 0;
    double x, y;
    double **points = NULL;

    // Allocate memory for points
    points = (double**)malloc(MAX_POINTS * sizeof(double*));
    for (int i = 0; i < MAX_POINTS; i++)
    {
        points[i] = (double*)malloc(2 * sizeof(double));
    }

    // Get the number of points from the user
    printf("Enter the number of points: ");
    scanf("%d", &nPoints);

    // Create the points
    for (int i = 0; i < nPoints; i++)
    {
        printf("Enter the x coordinate of point %d: ", i + 1);
        scanf("%lf", &x);

        printf("Enter the y coordinate of point %d: ", i + 1);
        scanf("%lf", &y);

        points[i][0] = x;
        points[i][1] = y;
    }

    // Calculate the distance between two points
    double distance = sqrt(pow(points[0][0] - points[1][0], 2) + pow(points[0][1] - points[1][1], 2));

    // Print the distance
    printf("The distance between points (%.2lf, %.2lf) and (%.2lf, %.2lf) is %.2lf units.\n", points[0][0], points[0][1], points[1][0], points[1][1], distance);

    // Free the memory
    for (int i = 0; i < MAX_POINTS; i++)
    {
        free(points[i]);
    }
    free(points);

    return 0;
}