//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_POINTS 1000
#define NUM_CLUSTERS 5
#define MAX_ITERATIONS 10

typedef struct Point {
    double x;
    double y;
    int cluster;
} Point;

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void KMeansClustering(Point* data, int numPoints, Point* centroids, int numClusters) {
    int i, j, k, index, iterations;
    double minDist, dist;
    
    // Allocate memory for cluster sums and counts
    Point* clusterSums = (Point*) calloc(numClusters, sizeof(Point));
    int* clusterCounts = (int*) calloc(numClusters, sizeof(int));
    
    // Assign initial clusters to points
    for (i = 0; i < numPoints; i++) {
        minDist = distance(data[i], centroids[0]);
        index = 0;
        for (j = 1; j < numClusters; j++) {
            dist = distance(data[i], centroids[j]);
            if (dist < minDist) {
                minDist = dist;
                index = j;
            }
        }
        data[i].cluster = index;
        clusterSums[index].x += data[i].x;
        clusterSums[index].y += data[i].y;
        clusterCounts[index]++;
    }
    
    // Update cluster centroids and reassign points until convergence or maximum iterations reached
    iterations = 0;
    while (iterations < MAX_ITERATIONS) {
        iterations++;
        for (i = 0; i < numClusters; i++) {
            if (clusterCounts[i] > 0) {
                centroids[i].x = clusterSums[i].x / clusterCounts[i];
                centroids[i].y = clusterSums[i].y / clusterCounts[i];
                clusterSums[i].x = 0;
                clusterSums[i].y = 0;
                clusterCounts[i] = 0;
            }
        }
        for (i = 0; i < numPoints; i++) {
            minDist = distance(data[i], centroids[0]);
            index = 0;
            for (j = 1; j < numClusters; j++) {
                dist = distance(data[i], centroids[j]);
                if (dist < minDist) {
                    minDist = dist;
                    index = j;
                }
            }
            if (data[i].cluster != index) {
                clusterCounts[data[i].cluster]--;
                clusterCounts[index]++;
                clusterSums[data[i].cluster].x -= data[i].x;
                clusterSums[data[i].cluster].y -= data[i].y;
                clusterSums[index].x += data[i].x;
                clusterSums[index].y += data[i].y;
                data[i].cluster = index;
            }
        }
    }
    
    // Free memory
    free(clusterSums);
    free(clusterCounts);
}

int main() {
    // Generate random points and initial centroids
    Point* data = (Point*) calloc(NUM_POINTS, sizeof(Point));
    Point* centroids = (Point*) calloc(NUM_CLUSTERS, sizeof(Point));
    srand(time(0));
    for (int i = 0; i < NUM_POINTS; i++) {
        data[i].x = (double) rand() / RAND_MAX * 100;
        data[i].y = (double) rand() / RAND_MAX * 100;
        data[i].cluster = -1;
    }
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        centroids[i].x = (double) rand() / RAND_MAX * 100;
        centroids[i].y = (double) rand() / RAND_MAX * 100;
    }
    
    // Run clustering algorithm
    KMeansClustering(data, NUM_POINTS, centroids, NUM_CLUSTERS);
    
    // Print results
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d center: (%f, %f)\n", i, centroids[i].x, centroids[i].y);
    }
    
    // Free memory
    free(data);
    free(centroids);
    
    return 0;
}