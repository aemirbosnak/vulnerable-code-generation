//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

int main()
{
    int nPoints = 0;
    double **points = NULL;
    double **clusters = NULL;
    double totalDistance = 0.0;
    int i, j, k, l, clusterSize = 0;

    // Allocate memory for points and clusters
    points = (double**)malloc(MAX_POINTS * sizeof(double*));
    clusters = (double**)malloc(MAX_POINTS * sizeof(double*));

    // Create points
    points[0] = (double*)malloc(MAX_POINTS * sizeof(double));
    points[1] = (double*)malloc(MAX_POINTS * sizeof(double));

    // Generate points randomly
    for (i = 0; i < MAX_POINTS; i++)
    {
        points[0][i] = rand() % 100;
        points[1][i] = rand() % 100;
        nPoints++;
    }

    // Calculate distances between points and the center of each cluster
    for (i = 0; i < nPoints; i++)
    {
        for (j = 0; j < clusterSize; j++)
        {
            double distance = sqrt(pow(points[0][i] - points[0][j], 2) + pow(points[1][i] - points[1][j], 2));
            clusters[i][j] = distance;
        }
    }

    // Find the nearest cluster for each point
    for (i = 0; i < nPoints; i++)
    {
        double minDistance = 1000.0;
        int minCluster = -1;
        for (j = 0; j < clusterSize; j++)
        {
            if (clusters[i][j] < minDistance)
            {
                minDistance = clusters[i][j];
                minCluster = j;
            }
        }
        clusters[i][minCluster] = 1;
    }

    // Print the clusters
    for (i = 0; i < clusterSize; i++)
    {
        printf("Cluster %d:", i + 1);
        for (j = 0; j < nPoints; j++)
        {
            if (clusters[j][i] == 1)
            {
                printf(", point %d", j + 1);
            }
        }
        printf("\n");
    }

    // Free memory
    free(points);
    free(clusters);

    return 0;
}