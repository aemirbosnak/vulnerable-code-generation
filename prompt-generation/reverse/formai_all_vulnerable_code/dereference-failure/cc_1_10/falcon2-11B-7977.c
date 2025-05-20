//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate Euclidean distance between two points
double euclideanDistance(double* p1, double* p2, int numDimensions) {
    double distance = 0.0;
    for (int i = 0; i < numDimensions; i++) {
        distance += pow(p1[i] - p2[i], 2);
    }
    return sqrt(distance);
}

// Function to initialize cluster centers randomly
void initializeClusterCenters(int numClusters, double* clusterCenters, int numDimensions) {
    for (int i = 0; i < numClusters; i++) {
        clusterCenters[i] = (double)rand() / RAND_MAX; // Generate random number between 0 and 1, convert to double, and use as index to initialize cluster center
    }
}

// Function to assign each point to the nearest cluster center
void assignPointsToClusters(double* data, int numDataPoints, int numDimensions, int numClusters, double* clusterCenters, int* clusterAssignments) {
    for (int i = 0; i < numDataPoints; i++) {
        double minDistance = 10000.0;
        int minCluster = -1;
        for (int j = 0; j < numClusters; j++) {
            double distance = euclideanDistance(data + i * numDimensions, clusterCenters + j * numDimensions, numDimensions);
            if (distance < minDistance) {
                minDistance = distance;
                minCluster = j;
            }
        }
        clusterAssignments[i] = minCluster;
    }
}

// Function to update cluster centers using the mean of all points assigned to the cluster
void updateClusterCenters(double* clusterCenters, int numClusters, int numDataPoints, int numDimensions, int* clusterAssignments, double* data) {
    for (int i = 0; i < numClusters; i++) {
        int numPointsInCluster = 0;
        for (int j = 0; j < numDataPoints; j++) {
            if (clusterAssignments[j] == i) {
                numPointsInCluster++;
            }
        }
        if (numPointsInCluster == 0) {
            continue;
        }
        double sum = 0.0;
        for (int j = 0; j < numDataPoints; j++) {
            if (clusterAssignments[j] == i) {
                sum += data[j * numDimensions];
            }
        }
        clusterCenters[i] = sum / numPointsInCluster;
    }
}

int main() {
    int numClusters = 3; // Number of clusters
    int numDimensions = 2; // Number of dimensions for each point

    int numDataPoints = 100; // Number of data points
    double* data = (double*)malloc(numDataPoints * numDimensions * sizeof(double));
    int* clusterAssignments = (int*)malloc(numDataPoints * sizeof(int));

    // Generate random data points
    for (int i = 0; i < numDataPoints; i++) {
        for (int j = 0; j < numDimensions; j++) {
            data[i * numDimensions + j] = (double)rand() / RAND_MAX;
        }
    }

    // Initialize cluster centers randomly
    double* clusterCenters = (double*)malloc(numClusters * numDimensions * sizeof(double));
    initializeClusterCenters(numClusters, clusterCenters, numDimensions);

    // Assign points to clusters
    assignPointsToClusters(data, numDataPoints, numDimensions, numClusters, clusterCenters, clusterAssignments);

    // Update cluster centers using the mean of all points assigned to the cluster
    updateClusterCenters(clusterCenters, numClusters, numDataPoints, numDimensions, clusterAssignments, data);

    // Print cluster assignments
    for (int i = 0; i < numDataPoints; i++) {
        printf("%d ", clusterAssignments[i]);
    }
    printf("\n");

    // Print updated cluster centers
    for (int i = 0; i < numClusters; i++) {
        printf("Cluster %d: ", i + 1);
        for (int j = 0; j < numDimensions; j++) {
            printf("%.2f ", clusterCenters[i * numDimensions + j]);
        }
        printf("\n");
    }

    // Free allocated memory
    free(data);
    free(clusterAssignments);
    free(clusterCenters);

    return 0;
}