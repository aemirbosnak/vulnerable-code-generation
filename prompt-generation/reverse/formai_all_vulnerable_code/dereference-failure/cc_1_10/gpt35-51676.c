//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 4 

// A structure to represent a data point
struct DataPoint {
    double x[M];
};

// A function to calculate the distance between two points
double calculateDistance(struct DataPoint *dataPoint1, struct DataPoint *dataPoint2) {
    double distance = 0;
    for(int i = 0; i < M; i++) {
        distance += (dataPoint1->x[i] - dataPoint2->x[i]) * (dataPoint1->x[i] - dataPoint2->x[i]);
    }
    return sqrt(distance);
}

// A function to find the closest point
int findClosestPoint(struct DataPoint *centroids, int numClusters, struct DataPoint *dataPoint) {
    int closestPointIndex = 0;
    double closestPointDistance = calculateDistance(&centroids[0], dataPoint);
    for(int i = 1; i < numClusters; i++) {
        double distance = calculateDistance(&centroids[i], dataPoint);
        if(distance < closestPointDistance) {
            closestPointIndex = i;
            closestPointDistance = distance;
        }
    }
    return closestPointIndex;
}

// A function to move the centroids to the new locations
void updateCentroids(struct DataPoint *centroids, int numClusters, struct DataPoint *clusteredPoints, int *clusterSizes) {
    for(int i = 0; i < numClusters; i++) {
        for(int j = 0; j < M; j++) {
            if(clusterSizes[i] > 0) {
                centroids[i].x[j] /= clusterSizes[i];
            }
        }
    }
}

// A function to perform the k-means clustering algorithm
void kMeansClustering(struct DataPoint *dataPoints, int numDataPoints, struct DataPoint *centroids, int numClusters) {
    int *clusterSizes = (int *) calloc(numClusters, sizeof(int));
    struct DataPoint *clusteredPoints = (struct DataPoint *) calloc(numDataPoints, sizeof(struct DataPoint));
    int iterations = 0;

    // Repeat until convergence
    while(iterations++ < 1000) {
        // For each data point, find the closest centroid
        for(int i = 0; i < numDataPoints; i++) {
            int clusterIndex = findClosestPoint(centroids, numClusters, &dataPoints[i]);
            clusterSizes[clusterIndex]++;
            for(int j = 0; j < M; j++) {
                clusteredPoints[clusterIndex].x[j] += dataPoints[i].x[j];
            }
        }

        // Move the centroids to the new locations
        updateCentroids(centroids, numClusters, clusteredPoints, clusterSizes);

        // Reset the cluster sizes and clustered points
        for(int i = 0; i < numClusters; i++) {
            clusterSizes[i] = 0;
            for(int j = 0; j < M; j++) {
                clusteredPoints[i].x[j] = 0;
            }
        }
    }

    // Print the final clusters
    for(int i = 0; i < numClusters; i++) {
        printf("Cluster %d:\n", i);
        for(int j = 0; j < numDataPoints; j++) {
            if(findClosestPoint(&centroids[i], 1, &dataPoints[j]) == i) {
                printf("(%lf, %lf, %lf, %lf) ", dataPoints[j].x[0], dataPoints[j].x[1], dataPoints[j].x[2], dataPoints[j].x[3]);
            }
        }
        printf("\n");
    }

    free(clusterSizes);
    free(clusteredPoints);
}

// The main function
int main() {
    struct DataPoint dataPoints[] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};
    int numDataPoints = sizeof(dataPoints) / sizeof(struct DataPoint);
    
    struct DataPoint centroids[] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    int numClusters = sizeof(centroids) / sizeof(struct DataPoint);

    kMeansClustering(dataPoints, numDataPoints, centroids, numClusters);

    return 0;
}