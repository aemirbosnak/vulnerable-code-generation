//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Our trusty point struct
typedef struct {
    double x, y;
} Point;

// Initialize a cluster with a centroid and point count
typedef struct {
    Point centroid;
    int pointCount;
} Cluster;

// Calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Assign a point to the nearest cluster
void assignPointToCluster(Point p, Cluster* clusters, int numClusters) {
    int nearestCluster = -1;
    double minDistance = INFINITY;
    for (int i = 0; i < numClusters; i++) {
        double dist = distance(p, clusters[i].centroid);
        if (dist < minDistance) {
            nearestCluster = i;
            minDistance = dist;
        }
    }
    clusters[nearestCluster].pointCount++;
}

// Update the centroid of a cluster
void updateCentroid(Cluster* cluster) {
    double x = 0, y = 0;
    for (int i = 0; i < cluster->pointCount; i++) {
        x += cluster->centroid.x;
        y += cluster->centroid.y;
    }
    cluster->centroid.x = x / cluster->pointCount;
    cluster->centroid.y = y / cluster->pointCount;
}

// Main clustering algorithm
void kMeans(Point* points, int numPoints, Cluster* clusters, int numClusters) {
    // Initialize clusters with random centroids
    for (int i = 0; i < numClusters; i++) {
        clusters[i].centroid.x = points[rand() % numPoints].x;
        clusters[i].centroid.y = points[rand() % numPoints].y;
        clusters[i].pointCount = 0;
    }

    // Iterate until convergence
    int converged = 0;
    while (!converged) {
        // Assign points to clusters
        for (int i = 0; i < numPoints; i++) {
            assignPointToCluster(points[i], clusters, numClusters);
        }

        // Update cluster centroids
        for (int i = 0; i < numClusters; i++) {
            updateCentroid(&clusters[i]);
        }

        // Check for convergence
        converged = 1;
        for (int i = 0; i < numClusters; i++) {
            if (clusters[i].pointCount == 0) {
                converged = 0;
                break;
            }
        }
    }
}

int main() {
    // Create a bunch of points
    int numPoints = 100;
    Point* points = (Point*)malloc(sizeof(Point) * numPoints);
    for (int i = 0; i < numPoints; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    // Initialize clusters
    int numClusters = 3;
    Cluster* clusters = (Cluster*)malloc(sizeof(Cluster) * numClusters);

    // Run the k-means algorithm
    kMeans(points, numPoints, clusters, numClusters);

    // Print the results
    for (int i = 0; i < numClusters; i++) {
        printf("Cluster %d: (%.2f, %.2f)\n", i, clusters[i].centroid.x, clusters[i].centroid.y);
    }

    // Cleanup
    free(points);
    free(clusters);
    return 0;
}