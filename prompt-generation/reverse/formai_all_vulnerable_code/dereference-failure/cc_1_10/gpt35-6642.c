//FormAI DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to hold a single data point
struct DataPoint {
    double x;
    double y;
};

// Function to generate random data points
struct DataPoint* generateRandomData(int numOfPoints) {
    struct DataPoint* data = malloc(numOfPoints * sizeof(struct DataPoint));
    for(int i = 0; i < numOfPoints; i++) {
        data[i].x = ((double)rand()/RAND_MAX) * 10;  // Random x value between 0 and 10
        data[i].y = sin(data[i].x);  // y value is calculated based on sin function
    }
    return data;
}

// Function to perform K-Means clustering on the data points
int* kMeansClustering(struct DataPoint* data, int numOfPoints, int k, int maxIterations) {
    // Initialize k random centroids
    struct DataPoint* centroids = malloc(k * sizeof(struct DataPoint));
    for(int i = 0; i < k; i++) {
        centroids[i] = data[rand() % numOfPoints];
    }

    // Initialize clusters
    int* clusters = malloc(numOfPoints * sizeof(int));

    // Perform K-Means iterations
    for(int i = 0; i < maxIterations; i++) {
        // Reassign data points to the closest centroid
        for(int j = 0; j < numOfPoints; j++) {
            double minDistance = INFINITY;
            int closestCentroid;
            for(int c = 0; c < k; c++) {
                double distance = sqrt(pow(data[j].x - centroids[c].x, 2) + pow(data[j].y - centroids[c].y, 2));
                if(distance < minDistance) {
                    minDistance = distance;
                    closestCentroid = c;
                }
            }
            clusters[j] = closestCentroid;
        }

        // Update centroids
        for(int c = 0; c < k; c++) {
            double sumX = 0;
            double sumY = 0;
            int count = 0;
            for(int j = 0; j < numOfPoints; j++) {
                if(clusters[j] == c) {
                    sumX += data[j].x;
                    sumY += data[j].y;
                    count++;
                }
            }
            if(count > 0) {
                centroids[c].x = sumX/count;
                centroids[c].y = sumY/count;
            }
        }
    }

    // Free memory
    free(centroids);

    return clusters;
}

int main() {
    int numOfPoints = 100;
    int k = 3;
    int maxIterations = 10;
    struct DataPoint* data = generateRandomData(numOfPoints);
    int* clusters = kMeansClustering(data, numOfPoints, k, maxIterations);

    // Print clusters
    for(int i = 0; i < numOfPoints; i++) {
        printf("Data point %d: Cluster %d\n", i+1, clusters[i]);
    }

    // Free memory
    free(data);
    free(clusters);

    return 0;
}