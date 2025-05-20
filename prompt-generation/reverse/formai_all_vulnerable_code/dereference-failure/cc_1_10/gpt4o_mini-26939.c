//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 5

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    Point *points; // Array of points in the cluster
    int size;      // Number of points in the cluster
} Cluster;

void initializePoints(Point *points, int n) {
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 100; // Random x coordinate
        points[i].y = rand() % 100; // Random y coordinate
    }
}

void initializeClusters(Cluster *clusters, int k, Point *points) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[i]; // Initialize centroids to first k points
        clusters[i].points = malloc(MAX_POINTS * sizeof(Point)); // Allocate memory for points in cluster
        clusters[i].size = 0; // Initialize size
    }
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int findClosestCluster(Point p, Cluster *clusters, int k) {
    int closestIndex = 0;
    double minDistance = distance(p, clusters[0].centroid);
    
    for (int i = 1; i < k; i++) {
        double dist = distance(p, clusters[i].centroid);
        if (dist < minDistance) {
            minDistance = dist;
            closestIndex = i;
        }
    }
    
    return closestIndex;
}

void assignPointsToClusters(Point *points, int n, Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].size = 0; // Reset cluster size
    }

    for (int i = 0; i < n; i++) {
        int clusterIndex = findClosestCluster(points[i], clusters, k);
        clusters[clusterIndex].points[clusters[clusterIndex].size] = points[i];
        clusters[clusterIndex].size++;
    }
}

void updateCentroids(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        double sumX = 0, sumY = 0;

        for (int j = 0; j < clusters[i].size; j++) {
            sumX += clusters[i].points[j].x;
            sumY += clusters[i].points[j].y;
        }

        if (clusters[i].size > 0) {
            clusters[i].centroid.x = sumX / clusters[i].size;
            clusters[i].centroid.y = sumY / clusters[i].size;
        }
    }
}

int clustersChanged(Cluster *oldClusters, Cluster *newClusters, int k) {
    for (int i = 0; i < k; i++) {
        if (oldClusters[i].centroid.x != newClusters[i].centroid.x ||
            oldClusters[i].centroid.y != newClusters[i].centroid.y) {
            return 1; // Clusters have changed
        }
    }
    return 0; // Clusters remain unchanged
}

void freeClusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        free(clusters[i].points); // Freeing points array
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    int n = 20; // Number of points
    int k = 3;  // Number of clusters

    Point *points = malloc(n * sizeof(Point));
    initializePoints(points, n);
    
    Cluster *clusters = malloc(k * sizeof(Cluster));
    initializeClusters(clusters, k, points);

    int changed;
    do {
        Cluster *oldClusters = malloc(k * sizeof(Cluster));
        for (int i = 0; i < k; i++) {
            oldClusters[i] = clusters[i]; // Copy current clusters for comparison
        }

        assignPointsToClusters(points, n, clusters, k);
        updateCentroids(clusters, k);

        changed = clustersChanged(oldClusters, clusters, k);
        free(oldClusters); // Free the old clusters array

    } while (changed);

    // Display the results
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: Centroid (%.2f, %.2f) - Points:\n", i + 1, clusters[i].centroid.x, clusters[i].centroid.y);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("\t(%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    free(points);     // Free points array
    free(clusters);   // Free clusters array

    return 0;
}