//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data structure for a point
typedef struct {
    double x;
    double y;
} Point;

// Data structure for a cluster
typedef struct {
    Point *points;
    int size;
    Point center;
} Cluster;

// Function to calculate the Euclidean distance between two points
double euclideanDistance(Point p1, Point p2) {
    double distance = 0.0;
    distance = sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
    return distance;
}

// Function to initialize clusters with randomly selected points
Cluster* initializeClusters(Point *points, int numPoints, int numClusters) {
    Cluster *clusters = (Cluster*) malloc(numClusters * sizeof(Cluster));
    int i, j, randIndex;
    for (i = 0; i < numClusters; i++) {
        clusters[i].points = (Point*) malloc(numPoints * sizeof(Point));
        randIndex = rand() % numPoints;
        clusters[i].points[0] = points[randIndex];
        clusters[i].size = 1;
        clusters[i].center = points[randIndex];
    }
    for (i = 0; i < numPoints; i++) {
        double minDistance = INFINITY;
        int closestCluster = -1;
        for (j = 0; j < numClusters; j++) {
            double distance = euclideanDistance(points[i], clusters[j].center);
            if (distance < minDistance) {
                minDistance = distance;
                closestCluster = j;
            }
        }
        clusters[closestCluster].points[clusters[closestCluster].size] = points[i];
        clusters[closestCluster].size++;
        Point newCenter;
        newCenter.x = 0.0;
        newCenter.y = 0.0;
        for (j = 0; j < clusters[closestCluster].size; j++) {
            newCenter.x += clusters[closestCluster].points[j].x;
            newCenter.y += clusters[closestCluster].points[j].y;
        }
        newCenter.x /= clusters[closestCluster].size;
        newCenter.y /= clusters[closestCluster].size;
        clusters[closestCluster].center = newCenter;
    }
    return clusters;
}

// Function to perform K-Means clustering algorithm
Cluster* kMeans(Cluster *clusters, int numPoints, int numClusters, int iterations) {
    int i, j, k;
    for (i = 0; i < iterations; i++) {
        for (j = 0; j < numClusters; j++) {
            clusters[j].size = 0;
            for (k = 0; k < numPoints; k++) {
                double minDistance = INFINITY;
                int closestCluster = -1;
                for (int l = 0; l < numClusters; l++) {
                    double distance = euclideanDistance(clusters[l].points[0], clusters[j].points[k]);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestCluster = l;
                    }
                }
                if (closestCluster == j) {
                    clusters[j].points[clusters[j].size] = clusters[j].points[k];
                    clusters[j].size++;
                } else {
                    Point newCenter;
                    newCenter.x = 0.0;
                    newCenter.y = 0.0;
                    for (int l = 0; l < clusters[closestCluster].size; l++) {
                        newCenter.x += clusters[closestCluster].points[l].x;
                        newCenter.y += clusters[closestCluster].points[l].y;
                    }
                    newCenter.x /= clusters[closestCluster].size;
                    newCenter.y /= clusters[closestCluster].size;
                    clusters[closestCluster].center = newCenter;
                }
            }
            Point newCenter;
            newCenter.x = 0.0;
            newCenter.y = 0.0;
            for (k = 0; k < clusters[j].size; k++) {
                newCenter.x += clusters[j].points[k].x;
                newCenter.y += clusters[j].points[k].y;
            }
            newCenter.x /= clusters[j].size;
            newCenter.y /= clusters[j].size;
            clusters[j].center = newCenter;            
        }
    }
    return clusters;
}

int main() {
    int numPoints = 100;
    Point *points = (Point*) malloc(numPoints * sizeof(Point));
    // Generate random points
    for (int i = 0; i < numPoints; i++) {
        points[i].x = (double) rand() / RAND_MAX;
        points[i].y = (double) rand() / RAND_MAX;
    }
    int numClusters = 3;
    int iterations = 10;
    Cluster *clusters = initializeClusters(points, numPoints, numClusters);
    clusters = kMeans(clusters, numPoints, numClusters, iterations);
    // Print each cluster's center point and the number of points in the cluster
    for (int i = 0; i < numClusters; i++) {
        printf("Cluster %d center point: (%f, %f)\n", i+1, clusters[i].center.x, clusters[i].center.y);
        printf("Number of points in cluster %d: %d\n", i+1, clusters[i].size);
    }
    // Free allocated memory
    for (int i = 0; i < numClusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
    free(points);
    return 0;
}